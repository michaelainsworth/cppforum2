#include <cppforum2/model/repository.hpp>
#include <soci.h>
#include <iostream>
#include <fstream>
#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>
#include <vector>
using namespace std;
using namespace soci;
using namespace boost;
using namespace boost::filesystem;

std::string get_file_contents(const path& version_file) {
    ifstream fin(version_file.string().c_str());
    fin.seekg(0, ios::end);
    ios::pos_type length = fin.tellg();
    fin.seekg(0, ios::beg);
    char *data = new char[length];
    fin.read(data, length);
    string str(data, length);
    delete [] data;
    return str;
}

void upgrade_database(soci::session& db, const path& version_file, int version) {
    string sql = get_file_contents(version_file);
    
    string delimiter = "-- SEPARATOR";
    string::size_type delimiter_length = delimiter.length();
    
    string::size_type last = 0, i = 0;
    while (true) {
        i = sql.find(delimiter, last);
        string subsql = sql.substr(last, i - last);
        
        if (i == string::npos) {
            break;
        } else {
            last = i + delimiter_length;
        }
    }
}

repository::repository(session& db, const std::string& schema_directory) : db_(db), schema_directory_(schema_directory) {
    string backend_schema_directory = schema_directory_ + "/" + db_.get_backend()->get_backend_name();
    string version_1_string = backend_schema_directory + "/1.sql";
    upgrade_database(db_, version_1_string, 1);
    
    string version_string;
    indicator ind;
    
    db_ << "select opt_value from opt where opt_id = 'database_version'", into(version_string, ind);
    if (!db_.got_data()) {
        db_ << "insert into opt (opt_id, opt_value) values ('database_version', '1')";
        version_string = "1";
    }
        
    int version = lexical_cast<int>(version_string);
    
    for (version = version + 1; true; ++version) {
        version_string = lexical_cast<string>(version);
        string version_file_string = backend_schema_directory + "/" + version_string + ".sql";
        path version_file(version_file_string);
   
        if (!exists(version_file)) {
            break;
        } else {
            upgrade_database(db_, version_file, version);
            db_ << "update opt set opt_value = ? where opt_id = 'database_version'", use(version_string);
        }
    }
}

template<>
usr* repository::get<string, usr>(const string& k) {
    unique_cache<string, usr>& c = cache<string, usr>();
    if (c.has(k)) {
        return c.get(k);
    } else {
        usr::key_t usr_key;
        string usr_id, first_name, last_name;
        int is_admin;
        
        db_ << "select usr_key, usr_id, first_name, last_name, is_admin from usr where usr_id = ?", use(k), into(usr_key), into(usr_id), into(first_name), into(last_name), into(is_admin);
        
        if (!db_.got_data()) {
            return nullptr;
        }
        
        usr* u = new usr(*this, usr_key, usr_id, first_name, last_name, is_admin);
        c.set(usr_id, u);
        return u;
    }
}

template<>
forum* repository::get<std::string, forum>(const std::string& k) {
    unique_cache<string, forum>& c = cache<string, forum>();
    if (c.has(k)) {
        return c.get(k);
    } else {
        forum::key_t forum_key;
        string forum_id, name, description;
        
        db_ << "select forum_key, forum_id, forum_name, description from forum where forum_id = ?", use(k), into(forum_key), into(forum_id), into(name), into(description);
        
        if (!db_.got_data()) {
            return nullptr;
        }
        
        forum* f = new forum(*this, forum_key, forum_id, name, description);
        c.set(forum_id, f);
        return f;
    }
}

template<typename K,typename T>
unique_cache<K, T>& repository::cache() {
    static unique_cache<K, T> c;
    return c;
}
