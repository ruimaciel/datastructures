cmake_minimum_required(VERSION 3.10)

project(HashTable
    VERSION 0.1.0.0
    LANGUAGES CXX
    )

set(HashTable_INCLUDES
    includes/HashTable.h++
    )

set(HashTable_SOURCES
    src/HashTable.c++
    )

set(HashTable_HEADERS
    )

add_library(${PROJECT_NAME}
    SHARED
    ${HashTable_INCLUDES}
    ${HashTable_SOURCES}
    ${HashTable_HEADERS}
    )

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/includes>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(
    ${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    C_EXTENSIONS OFF
    POSITION_INDEPENDENT_CODE ON
    )


option(RUN_TESTS "runs unit tests" ON)
if(RUN_TESTS)
    add_subdirectory(tests)
endif(RUN_TESTS)
