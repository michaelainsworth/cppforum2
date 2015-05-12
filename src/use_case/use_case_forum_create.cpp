#include "use_case_forum_create.hpp"
#include "model/error.hpp"
#include "model/usr.hpp"
#include "model/forum.hpp"
#include "model/repository.hpp"

use_case_forum_create::use_case_forum_create(repository& repo, soci::session& db, const std::string usr_id, const std::string& forum_id, const std::string& description) : use_case(repo, db, usr_id), forum_id_(forum_id), description_(description) {}

std::error_condition use_case_forum_create::operator ()() {
    
    if (!usr_) {
        return error::auth_required;
    }
    
    if (!usr_->is_admin()) {
        return error::admin_required;
    }
    
    forum* existing = repo_.get<std::string,forum>(forum_id_);
    if (existing) {
        return error::forum_exists;
    }
    
    new_forum_ = new forum(repo_, 0, forum_id_, description_);
    tx_.save<forum>(*new_forum_);
    tx_.commit();
    
    return error::ok;
}




