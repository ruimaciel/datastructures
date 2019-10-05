cmake_minimum_required(VERSION 3.5)

project(Case LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

add_executable(CaseBinaryHeap test_BinaryHeap.c++)
add_test(CaseBinaryHeap COMMAND CaseBinaryHeap)

target_link_libraries(CaseBinaryHeap
    BinaryHeap
    )

add_executable(CaseBinaryHeapInsert test_BinaryHeap_insert.c++)
add_test(CaseBinaryHeapInsert COMMAND CaseBinaryHeapInsert)

target_link_libraries(CaseBinaryHeapInsert
    BinaryHeap
    )

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
