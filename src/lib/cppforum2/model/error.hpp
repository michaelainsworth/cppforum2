#ifndef CPPFORUM2_ERROR_HPP_INCLUDED
#define CPPFORUM2_ERROR_HPP_INCLUDED

#include <system_error>
#include <string>

class error_category;

enum class error {
    ok = 0,
    missing_config_file,
    config_file_not_exists,
    config_file_not_file,
    config_file_not_json,
    config_file_schema_missing,
    config_file_schema_not_dir,
    config_file_database_missing,
    auth_required,
    admin_required,
    forum_exists
};

namespace std {

    template<> struct is_error_code_enum<::error> : public std::true_type {};
    template<> struct is_error_condition_enum<::error> : public std::true_type {};
    
}

const error_category& get_error_category();

std::error_code make_error_code(error e);
std::error_condition make_error_condition(error e);

class error_category : public std::error_category {
public:
    
    const char* name() const noexcept(true);
    std::string message(int ev) const noexcept(true);
    
};

#endif // #ifndef CPPFORUM2_ERROR_HPP_INCLUDED
