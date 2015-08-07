#include "model/forum.hpp"

// TODO: Friend class so that key is not provided in constructor?
forum::forum(repository& repo, key_t forum_key, const std::string& forum_id, const std::string& name, const std::string& description) : repo_(repo), forum_key_(forum_key), forum_id_(forum_id), name_(name), description_(description) {}

forum::key_t forum::forum_key() const {
    return forum_key_;
}

const std::string& forum::forum_id() const {
    return forum_id_;
}

const std::string& forum::name() const {
    return name_;
}

const std::string& forum::description() const {
    return description_;
}