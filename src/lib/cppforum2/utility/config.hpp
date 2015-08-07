#ifndef CPPFORUM2_CONFIG_HPP_INCLUDED
#define CPPFORUM2_CONFIG_HPP_INCLUDED

#include <string>
#include <system_error>

class config {
public:

    static config load(const char* config_file);
    
    config();
    config(const std::string& database, const std::string& schema);
    
    const std::string& database() const;
    const std::string& schema() const;
    
private:
    
    std::string database_;
    std::string schema_;
    
};


#endif // #ifndef CPPFORUM2_CONFIG_HPP_INCLUDED
