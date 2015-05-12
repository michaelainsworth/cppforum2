#ifndef CPPFORUM2_USE_CASE_HPP_INCLUDED
#define CPPFORUM2_USE_CASE_HPP_INCLUDED

#include <string>

#include "model/error.hpp"
#include "database/unit_of_work.hpp"

class repository;
class database;
class usr;

namespace soci {
    class session;
}

class use_case {
public:
    
    use_case(repository& repo, soci::session& db, const std::string& usr_id);
    virtual ~use_case() = 0;
    
    virtual std::error_condition operator ()() = 0;
    
protected:
    
    repository& repo_;
    soci::session& db_;
    unit_of_work tx_;
    std::string usr_id_;
    usr* usr_;
    
};

#endif // #ifndef CPPFORUM2_USE_CASE_HPP_INCLUDED
