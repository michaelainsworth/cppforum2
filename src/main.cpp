#include <iostream>
#include <fstream>
#include <string>
#include <boost/filesystem.hpp>
#include <cstdlib>
#include "cppforum2.hpp"
#include <cstdio>
#include <soci/soci.h>
#include <rapidjson/document.h>
#include <rapidjson/filereadstream.h>
using namespace std;
using namespace boost::filesystem;
using namespace soci;
using namespace rapidjson;

int main() {

    // TODO: Finish this.
    const char* config_file = getenv("CPPFORUM2_CONFIG");
    if (!config_file) {
        cerr << "No configuration file was specified in the CPPFORUM2_CONFIG environment variable." << endl;
        return 1;
    }

    path config_file_path(config_file);
    if (!exists(config_file_path)) {
        cerr << "The configuration file specified does not exist." << endl;
        return 2;
    }

    if (!is_regular_file(config_file_path)) {
        cerr << "The configuration file specified is not a regular file." << endl;
        return 3;
    }
    
    FILE* fp = fopen(config_file, "r");
    char buffer[65536];
    FileReadStream is(fp, buffer, sizeof(buffer));
    Document d;
    d.ParseStream(is);
    fclose(fp);
    
    if (!d.IsObject()) {
        cerr << "The CPPFORUM2_CONFIG file must contain a JSON object." << endl;
        return 4;
    }
    
    if (!d.HasMember("schema") || !d["schema"].IsString()) {
        cerr << "The CPPFORUM2_CONFIG file must contain a string property called 'schema'." << endl;
        return 5;
    }
    
    string schema_dir = d["schema"].GetString();
    path schema_dir_path(schema_dir);
    
    if (!exists(schema_dir_path) || !is_directory(schema_dir_path)) {
        cerr << "The 'schema' directory does not exist or is not a directory." << endl;
        return 6;
    }
    
    if (!d.HasMember("database") || !d["database"].IsString()) {
        cerr << "The CPPFORUM2_CONFIG file must contain a string property called 'database'." << endl;
        return 6;
    }
    
    string dsn = d["database"].GetString();
    session db(dsn);
    repository repo(db);
    
    // TODO: Finish
    
    
    return 0;

}
