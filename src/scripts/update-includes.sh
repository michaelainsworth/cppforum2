#!/bin/bash

echo "#ifndef CPPFORUM2_HPP_INCLUDED" > cppforum2.hpp
echo "#define CPPFORUM2_HPP_INCLUDED" >> cppforum2.hpp
echo >> cppforum2.hpp

find . -name \*.hpp | grep -v cppforum2.hpp | sort -u | sed -E -e 's/^..//g' -e 's/^(.*)$/#include "\1"/g' >> cppforum2.hpp
echo >> cppforum2.hpp

echo "#endif // #ifndef CPPFORUM2_HPP_INCLUDED" >> cppforum2.hpp
echo >> cppforum2.hpp
