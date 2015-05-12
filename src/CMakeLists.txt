cmake_minimum_required(VERSION 2.6)
project(cppforum2)

set(CXX "c++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Soci REQUIRED)
find_package(Boost COMPONENTS system filesystem REQUIRED)

include_directories("${CMAKE_SOURCE_DIR}")
include_directories(${Soci_INCLUDE_DIRS})

file(GLOB headers "${CMAKE_SOURCE_DIR}/*/*.hpp")
file(GLOB sources "${CMAKE_SOURCE_DIR}/*/*.cpp")
file(GLOB executable_sources "${CMAKE_SOURCE_DIR}/*.cpp")

add_executable(cppforum2 ${sources} ${headers} ${executable_sources})

target_link_libraries(cppforum2 ${Soci_LIBRARIES})
target_link_libraries(cppforum2 ${Boost_LIBRARIES})
