#ifndef CPPFORUM2_USR_HPP_INCLUDED
#define CPPFORUM2_USR_HPP_INCLUDED

#include <string>

class repository;

class usr {
public:
    
    typedef unsigned long long key_t;
    
    usr(repository& repo, key_t usr_key, const std::string& usr_id, const std::string& first_name, const std::string& last_name, bool is_admin);
    
    bool is_admin() const;
    
private:
    
    repository& repo_;
    key_t usr_key_;
    std::string usr_id_;
    std::string first_name_;
    std::string last_name_;
    bool is_admin_;
    
};

#endif // #ifndef CPPFORUM2_USR_HPP_INCLUDED
