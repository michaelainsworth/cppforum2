cmake_minimum_required(VERSION 2.6)
project(cppforum2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")

find_package(Soci REQUIRED)

include_directories("${CMAKE_SOURCE_DIR}")
include_directories(${Soci_INCLUDE_DIRS})

file(GLOB headers "${CMAKE_SOURCE_DIR}/*/*.hpp")
file(GLOB sources "${CMAKE_SOURCE_DIR}/*/*.cpp")

add_executable(cppforum2 ${sources} ${headers})

target_link_libraries(cppforum2 ${Soci_LIBRARIES})