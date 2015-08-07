#include <cppforum2/cmd/cmd_forum_create.hpp>
#include <cppforum2/model/error.hpp>
#include <cppforum2/model/usr.hpp>
#include <cppforum2/model/forum.hpp>
#include <cppforum2/model/repository.hpp>

cmd_forum_create::cmd_forum_create(repository& repo, soci::session& db, const std::string usr_id, const std::string& forum_id, const std::string& name, const std::string& description) : cmd(repo, db, usr_id), forum_id_(forum_id), name_(name), description_(description) {}

std::error_condition cmd_forum_create::operator ()() {
    
    if (!usr_) {
        return error::auth_required;
    }
    
    if (!usr_->is_admin()) {
        return error::admin_required;
    }
    
    if (repo_.has<std::string,forum>(forum_id_)) {
        return error::forum_exists;
    }
    
    new_forum_ = new forum(repo_, 0, forum_id_, name_, description_);
    tx_.save<forum>(*new_forum_);
    tx_.commit();
    
    return error::ok;
}




