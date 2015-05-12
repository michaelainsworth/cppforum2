#ifndef CPPFORUM2_REPOSITORY_HPP_INCLUDED
#define CPPFORUM2_REPOSITORY_HPP_INCLUDED

#include <string>

#include "model/usr.hpp"
#include "model/forum.hpp"

#include "utility/unique_cache.hpp"

class usr;

namespace soci {
    class session;
}

class repository {
public:
    
    typedef unique_cache<std::string, usr> usr_id_cache_t;
    
    repository(soci::session& db);
    
    template<typename K, typename T>
    T* get(const K& k);
    
private:
    
    // No copying.
    repository(const repository& that) = delete;
    repository& operator =(const repository& that) = delete;
    
    soci::session& db_;
    
    usr_id_cache_t usr_id_cache_;
    
};

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

#endif // #ifndef CPPFORUM2_REPOSITORY_HPP_INCLUDED
