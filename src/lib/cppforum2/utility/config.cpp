// TODO: Change include style.
#include <cppforum2/utility/config.hpp>
#include <fstream>
#include <cppforum2/model/error.hpp>
#include <cstdio>
#include <boost/filesystem.hpp>
#include <json/json.h>
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
    
    ifstream fin(config_file);
    Json::Value value;
    fin >> value;

    if (!value.isObject()) {
        throw std::system_error(error::config_file_not_json);        
    }
    
    if (!value["schema"].isString()) {
        throw std::system_error(error::config_file_schema_missing);
    }

    string schema_dir = value["schema"].asString();
    path schema_dir_path(schema_dir);
    
    if (!exists(schema_dir_path) || !is_directory(schema_dir_path)) {
        throw std::system_error(error::config_file_schema_not_dir);
    }
    
    if (!value["database"].isString()) {
        throw std::system_error(error::config_file_database_missing);
    }

    return config(value["database"].asString(), schema_dir);
}

const std::string& config::database() const {
    return database_;
}

const std::string& config::schema() const {
    return schema_;
}

