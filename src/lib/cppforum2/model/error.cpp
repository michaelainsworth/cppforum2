#include <cppforum2/model/error.hpp>

const char* error_category::name() const noexcept(true) {
    return "forum";
}

std::string error_category::message(int ev) const noexcept(true) {
    switch (static_cast<error>(ev)) {
        case error::missing_config_file:
            return "No configuration file name was specified in the CPPFORUM2_CONFIG environment variable.";
        case error::config_file_not_exists:
            return "The configuration file specified does not exist.";
        case error::config_file_not_file:
            return "The configuration file specified is not a regular file.";
        case error::config_file_not_json:
            return "The CPPFORUM2_CONFIG file must contain a JSON object.";
        case error::config_file_schema_missing:
            return "The CPPFORUM2_CONFIG file must contain a string property called 'schema'.";
        case error::config_file_schema_not_dir:
            return "The 'schema' directory does not exist or is not a directory.";
        case error::config_file_database_missing:
            return "The CPPFORUM2_CONFIG file must contain a string property called 'database'.";
        case error::auth_required:
            return "You must be authenticated in order to continue.";
        case error::admin_required:
            return "Only administrators can perform the action specified.";
        case error::forum_exists:
            return "The forum specified already exists.";
        default:
            return "An unknown error occurred.";
    }
}

const error_category& get_error_category() {
    static error_category ec;
    return ec;
}

std::error_code make_error_code(error e) {
    return std::error_code(static_cast<int>(e), get_error_category());
}

std::error_condition make_error_condition(error e) {
    return std::error_condition(static_cast<int>(e), get_error_category());
}
