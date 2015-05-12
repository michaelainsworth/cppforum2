#include "model/error.hpp"

const char* error_category::name() const noexcept(true) {
    return "forum";
}

std::string error_category::message(int ev) const noexcept(true) {
    switch (static_cast<error>(ev)) {
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

std::error_condition make_error_condition(error e) {
    return std::error_condition(static_cast<int>(e), get_error_category());
}
