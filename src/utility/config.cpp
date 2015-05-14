#include "utility/config.hpp"
#include "model/error.hpp"
#include <cstdio>
#include <rapidjson/document.h>
#include <rapidjson/filereadstream.h>
#include <boost/filesystem.hpp>
using namespace rapidjson;
using namespace boost::filesystem;
using namespace std;

config::config() : database_(""), schema_(".") {}

config::config(const std::string& database, const std::string& schema) : database_(database), schema_(schema) {}

config config::load(const char* config_file) {

    if (!config_file) {
	throw std::system_error(error::missing_config_file);
    }

    path config_file_path(config_file);
    if (!exists(config_file_path)) {
	throw std::system_error(error::config_file_not_exists);
    }

    if (!is_regular_file(config_file_path)) {
        throw std::system_error(error::config_file_not_file);
    }
    
    FILE* fp = fopen(config_file, "r");
    char buffer[2048];
    FileReadStream is(fp, buffer, sizeof(buffer));
    Document d;
    d.ParseStream(is);
    fclose(fp);
    
    if (!d.IsObject()) {
        throw std::system_error(error::config_file_not_json);
    }
    
    if (!d.HasMember("schema") || !d["schema"].IsString()) {
	throw std::system_error(error::config_file_schema_missing);
    }
    
    string schema_dir = d["schema"].GetString();
    path schema_dir_path(schema_dir);
    
    if (!exists(schema_dir_path) || !is_directory(schema_dir_path)) {
        throw std::system_error(error::config_file_schema_not_dir);
    }
    
    if (!d.HasMember("database") || !d["database"].IsString()) {
        throw std::system_error(error::config_file_database_missing);
    }

}

const std::string& config::database() const {
    return database_;
}

const std::string& config::schema() const {
    return schema_;
}

