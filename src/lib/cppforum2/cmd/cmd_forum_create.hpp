#ifndef CMD_FORUM_CREATE_HPP_INCLUDED
#define CMD_FORUM_CREATE_HPP_INCLUDED

#include <cppforum2/cmd/cmd.hpp>
#include <cppforum2/model/forum.hpp>

#include <string>

class cmd_forum_create : public cmd {
public:
    
    cmd_forum_create(repository& repo, soci::session& db, const std::string usr_id, const std::string& forum_id, const std::string& name, const std::string& description);
    
    std::error_condition operator ()();
    
private:
    
    std::string forum_id_, name_, description_;
    forum* new_forum_;
    
};

#endif // #ifndef CMD_FORUM_CREATE_HPP_INCLUDED

