#ifndef CPPFORUM2_CONFIG_HPP_INCLUDED
#define CPPFORUM2_CONFIG_HPP_INCLUDED

#include <string>

class config {
public:
    
    config();
    config(const std::string& database, const std::string& schema);
    
    const std::string& database() const;
    const std::string& schema() const;
    
private:
    
    std::string database_;
    std::string schema_;
    
};


#endif // #ifndef CPPFORUM2_CONFIG_HPP_INCLUDED