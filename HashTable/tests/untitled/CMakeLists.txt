cmake_minimum_required(VERSION 3.5)

project(HashCase LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

add_executable(HashCase main.c++)

target_link_libraries(HashCase
    HashTable
    )
add_test(HashCase COMMAND HashCase)

if (DEFINED ENV{BOOST_INCLUDE_DIR})
    set(BOOST_INCLUDE_DIR $ENV{BOOST_INCLUDE_DIR})
else ()
    set(BOOST_INCLUDE_DIR "") # set by Qt Creator wizard
endif ()
if (BOOST_INCLUDE_DIR STREQUAL "")
    message("BOOST_INCLUDE_DIR is not set, assuming Boost can be found automatically in your system")
elseif (EXISTS ${BOOST_INCLUDE_DIR})
    include_directories(${BOOST_INCLUDE_DIR})
endif ()
