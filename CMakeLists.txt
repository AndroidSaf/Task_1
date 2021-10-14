cmake_minimum_required(VERSION 3.16.0)

set(PROJECT_NAME Task_1)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -ggdb3")

set(TARGET task)
set(MAIN main.c)
set(LIB_HEADERS include)
set(LIB_SOURCES source)
set(LIB_NAME road_lib)

include_directories(${CMAKE_CURRENT_LIST_DIR}/${LIB_HEADERS})

add_library(${LIB_NAME} STATIC
        ${LIB_SOURCES}/upload.c
        ${LIB_SOURCES}/struct.c
        ${LIB_SOURCES}/average.c
        )

add_executable(${TARGET} ${MAIN})
target_link_libraries(${TARGET} ${LIB_NAME})

option(BUILD_TESTS "Build all tests." ON)
if(BUILD_TESTS)

    add_subdirectory(googletest)
    include_directories(googletest/include)

    set(TEST_SOURCES tests)

    file(GLOB test_sources
            ${TEST_SOURCES}/upload.cpp
            ${TEST_SOURCES}/struct.cpp
            ${TEST_SOURCES}/average.cpp
            )

    enable_testing()

    foreach(file ${test_sources})
        set(name)
        get_filename_component(name ${file} NAME_WE)
        add_executable("${name}_tests" ${file})
        target_link_libraries("${name}_tests" PRIVATE gtest)
        target_link_libraries("${name}_tests" PRIVATE ${LIB_NAME})
        add_test(NAME ${name} COMMAND "${name}_tests")
    endforeach()

endif()
