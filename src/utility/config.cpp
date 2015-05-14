#include "utility/config.hpp"

config::config() : database_(""), schema_(".") {}

config::config(const std::string& database, const std::string& schema) : database_(database), schema_(schema) {}

const std::string& config::database() const {
    return database_;
}

const std::string& config::schema() const {
    return schema_;
}

