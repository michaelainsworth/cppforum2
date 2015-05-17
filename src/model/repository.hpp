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
    
    repository(soci::session& db, const std::string& schema_directory);

    template<typename K, typename T>
    bool has(const K& k) {
        return get<K,T>(k) != nullptr;
    }
    
    template<typename K, typename T>
    T* get(const K& k);
    
protected:
    
    // Caching helpers
    template<typename K,typename T>
    unique_cache<K, T>& cache();
    
private:
    
    // No copying.
    repository(const repository& that) = delete;
    repository& operator =(const repository& that) = delete;
    
    soci::session& db_;
    std::string schema_directory_;
    
};

#endif // #ifndef CPPFORUM2_REPOSITORY_HPP_INCLUDED
