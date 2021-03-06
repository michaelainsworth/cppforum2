#!/bin/bash

echo "#ifndef CPPFORUM2_HPP_INCLUDED" > cppforum2.hpp
echo "#define CPPFORUM2_HPP_INCLUDED" >> cppforum2.hpp
echo >> cppforum2.hpp

find src/lib -name \*.hpp ! -path '*vendor*' | grep -F -v cppforum2.hpp | sort -u | sed -E -e 's#src/lib/##g' -e 's/^(.*)$/#include <\1>/g' >> cppforum2.hpp
echo >> cppforum2.hpp

echo "#endif // #ifndef CPPFORUM2_HPP_INCLUDED" >> cppforum2.hpp
echo >> cppforum2.hpp

mv -f cppforum2.hpp src/lib/cppforum2/cppforum2.hpp
