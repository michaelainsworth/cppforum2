#ifndef CPPFORUM2_UNIQUE_CACHE_HPP_INCLUDED
#define CPPFORUM2_UNIQUE_CACHE_HPP_INCLUDED

#include <map>

template<typename K, typename T>
class unique_cache {
public:
    
    unique_cache();
    ~unique_cache();
    
    bool has(const K& k);
    T* get(const K& k);
    void set(const K& k, T* t);
    
private:
    
    typedef std::map<K,T*> item_map;
    
    // No copying.
    unique_cache(const unique_cache& that) = delete;
    unique_cache& operator =(const unique_cache& that) = delete;
    
    item_map items_;
    
};

template<typename K, typename T>
unique_cache<K,T>::unique_cache() {}

template<typename K, typename T>
unique_cache<K,T>::~unique_cache() {
    for (auto p : items_) {
        delete p.second;
    }
    
    items_.clear();
}

template<typename K, typename T>
bool unique_cache<K,T>::has(const K& k) {
    return items_.find(k) != items_.end();
}

template<typename K, typename T>
T* unique_cache<K,T>::get(const K& k) {
    return items_.find(k)->second;
}

template<typename K, typename T>
void unique_cache<K,T>::set(const K& k, T* t) {
    if (has(k)) {
        typename item_map::iterator it = items_.find(k);
        delete it->second;
        items_.erase(it);
    }
    
    items_[k] = t;
}

#endif // #ifndef CPPFORUM2_UNIQUE_CACHE_HPP_INCLUDED
