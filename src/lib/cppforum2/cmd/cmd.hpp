#ifndef CPPFORUM2_CMD_HPP_INCLUDED
#define CPPFORUM2_CMD_HPP_INCLUDED

#include <string>

#include <cppforum2/model/error.hpp>
#include <cppforum2/database/unit_of_work.hpp>

class repository;
class database;
class usr;

namespace soci {
    class session;
}

class cmd {
public:
    
    cmd(repository& repo, soci::session& db, const std::string& usr_id);
    virtual ~cmd() = 0;
    
    virtual std::error_condition operator ()() = 0;
    
protected:
    
    repository& repo_;
    soci::session& db_;
    unit_of_work tx_;
    std::string usr_id_;
    usr* usr_;
    
};

#endif // #ifndef CPPFORUM2_CMD_HPP_INCLUDED
