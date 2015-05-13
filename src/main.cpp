#include <iostream>
#include <string>
#include <boost/filesystem.hpp>
#include <cstdlib>
#include "cppforum2.hpp"
#include <soci/soci.h>
using namespace std;
using namespace boost::filesystem;

int main() {

    // TODO: Finish this.
    const char* config_file = getenv("CPPFORUM2_CONFIG");
    if (!config_file) {
        cerr << "No configuration file was specified in the CPPFORUM2_CONFIG environment variable." << endl;
        return 1;
    }

    path config_file_path(config_file);
    if (!exists(config_file_path)) {
        cerr << "The configuration file specified does not exist." << endl;
        return 2;
    }

    if (!is_regular_file(config_file_path)) {
        cerr << "The configuration file specified is not a regular file." << endl;
        return 3;
    }

    cout << "Loading configuration file: " << config_file << endl;
    
    return 0;

}
