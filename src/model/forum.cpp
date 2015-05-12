#include "model/forum.hpp"

forum::forum(repository& repo, key_t forum_key, const std::string& name, const std::string& description) : repo_(repo), forum_key_(forum_key), name_(name), description_(description) {}