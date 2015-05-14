#ifndef CPPFORUM2_POST_HPP_INCLUDED
#define CPPFORUM2_POST_HPP_INCLUDED

class repository;

class post {
public:
    
    typedef unsigned long long key_t;
    
    post(repository& repo, key_t post_key);
    
    // TODO: Finish
    
private:
    
    repository& repo_;
    key_t post_key_;
    
};

#endif // #ifndef CPPFORUM2_POST_HPP_INCLUDED