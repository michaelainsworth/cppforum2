#ifndef USE_CASE_FORUM_CREATE_HPP_INCLUDED
#define USE_CASE_FORUM_CREATE_HPP_INCLUDED

#include "use_case/use_case.hpp"
#include "model/forum.hpp"

#include <string>

class use_case_forum_create : public use_case {
public:
    
    use_case_forum_create(repository& repo, soci::session& db, const std::string usr_id, const std::string& forum_id, const std::string& description);
    
    std::error_condition operator ()();
    
private:
    
    std::string forum_id_;
    std::string description_;
    forum* new_forum_;
    
};

#endif // #ifndef USE_CASE_FORUM_CREATE_HPP_INCLUDED

