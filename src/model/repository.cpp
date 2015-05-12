#include "model/repository.hpp"

repository::repository(soci::session& db) : db_(db) {}

template<>
usr* repository::get<std::string, usr>(const std::string& k) {
    // TODO: Implement
    return nullptr;
}

template<>
forum* repository::get<std::string, forum>(const std::string& k) {
    // TODO: Implement
    return nullptr;
}
