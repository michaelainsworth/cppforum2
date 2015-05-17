#ifndef CPPFORUM2_FORUM_HPP_INCLUDED
#define CPPFORUM2_FORUM_HPP_INCLUDED

#include <string>

class repository;

class forum {
public:
    
    typedef unsigned long long key_t;
    
    forum(repository& repo, key_t forum_key, const std::string& forum_id, const std::string& forum_name, const std::string& description);
    
    key_t forum_key() const;
    const std::string& forum_id() const;
    const std::string& name() const;
    const std::string& description() const;
    
private:
    
    repository& repo_;
    key_t forum_key_;
    std::string forum_id_;
    std::string name_;
    std::string description_;
    
};

#endif // #ifndef CPPFORUM2_FORUM_HPP_INCLUDED