#ifndef CPPFORUM2_FORUM_HPP_INCLUDED
#define CPPFORUM2_FORUM_HPP_INCLUDED

#include <string>

class repository;

class forum {
public:
    
    typedef unsigned long long key_t;
    
    forum(repository& repo, key_t forum_key, const std::string& name, const std::string& description);
    
private:
    
    repository& repo_;
    key_t forum_key_;
    std::string name_;
    std::string description_;
    
};

#endif // #ifndef CPPFORUM2_FORUM_HPP_INCLUDED