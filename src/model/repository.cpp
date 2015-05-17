#include "model/repository.hpp"
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

std::string get_file_contents(const std::string& file_path) {
    ifstream fin(file_path.c_str());
    fin.seekg(0, ios::end);
    ios::pos_type length = fin.tellg();
    fin.seekg(0, ios::beg);
    char *data = new char[length];
    fin.read(data, length);
    string str(data, length);
    delete [] data;
    return str;
}

void upgrade_database(soci::session& db, const string& backend_schema_directory, int version) {
    typedef std::vector<path> path_vector;

    path version_directory(backend_schema_directory + "/" + lexical_cast<string>(version));
    path_vector paths;
    
    copy(directory_iterator(version_directory), directory_iterator(), back_inserter(paths));
    sort(paths.begin(), paths.end());
    
    for (auto &p : paths) {
        string file_path_name = p.generic_string();
        if (file_path_name.rfind(".sql") == file_path_name.length() - 4) {
            string sql = get_file_contents(file_path_name);
            db << sql;
        }
    }
}

repository::repository(session& db, const std::string& schema_directory) : db_(db), schema_directory_(schema_directory) {
    
    
    string backend_schema_directory = schema_directory_ + "/" + db_.get_backend()->get_backend_name();
    
    upgrade_database(db_, backend_schema_directory, 1);
    
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
        string version_directory_string = backend_schema_directory + "/" + version_string;
        path version_directory(version_directory_string);
        
        if (!exists(version_directory)) {
            break;
        } else {
            upgrade_database(db_, backend_schema_directory, version);
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
