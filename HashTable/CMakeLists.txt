cmake_minimum_required(VERSION 3.10)

project(HashTable
    VERSION 0.1.0.0
    LANGUAGES CXX
    )

set(HashTable_INCLUDES includes/HashTable.h++ )

add_library(${PROJECT_NAME} INTERFACE )

target_include_directories(${PROJECT_NAME}
    INTERFACE
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/includes>
)

option(RUN_TESTS "runs unit tests" ON)
if(RUN_TESTS)
    add_subdirectory(tests)
endif(RUN_TESTS)
