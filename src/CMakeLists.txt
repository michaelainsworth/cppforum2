set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Soci REQUIRED)
find_package(Boost COMPONENTS system filesystem REQUIRED)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/lib")
include_directories(${SOCI_INCLUDE_DIR})
include_directories(${Boost_INCLUDE_DIRS})

link_directories("${SOCI_LIBRARY_DIR}")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/vendor/booster_cgix")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/vendor/booster_cgix/src/lib")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/vendor/jsoncpp")

file(GLOB headers "${CMAKE_CURRENT_SOURCE_DIR}/lib/cppforum2/*.hpp" "${CMAKE_CURRENT_SOURCE_DIR}/lib/cppforum2/*/*.hpp")
file(GLOB sources "${CMAKE_CURRENT_SOURCE_DIR}/lib/cppforum2/*/*.cpp")
add_library(cppforum2lib ${headers} ${sources})
target_link_libraries(cppforum2lib soci_core soci_sqlite3)
target_link_libraries(cppforum2lib ${Boost_LIBRARIES})
target_link_libraries(cppforum2lib booster_cgix jsoncpp_lib_static)

file(GLOB headers "${CMAKE_CURRENT_SOURCE_DIR}/cgi/*.hpp")
file(GLOB sources "${CMAKE_CURRENT_SOURCE_DIR}/cgi/*.cpp")
add_executable(cppforum2 ${headers} ${sources})
target_link_libraries(cppforum2 cppforum2lib)

