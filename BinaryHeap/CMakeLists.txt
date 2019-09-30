cmake_minimum_required(VERSION 3.10)

project(BinaryHeap
    VERSION 0.1.0.0
    LANGUAGES CXX
    )

set(BinaryHeap_INCLUDES
    includes/BinaryHeap.h++
    )

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(
  ${PROJECT_NAME}
  INTERFACE $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
            )

target_compile_features(
    ${PROJECT_NAME}
    INTERFACE cxx_std_11
    )


option(RUN_TESTS "runs unit tests" ON)
if(RUN_TESTS)
    add_subdirectory(tests)
endif(RUN_TESTS)

install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}_Targets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        )
