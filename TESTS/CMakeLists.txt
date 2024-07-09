cmake_minimum_required(VERSION 3.14)
project(StructsForgeTests)

include_directories(${CMAKE_SOURCE_DIR}/STRUCTURES/src)

# Automatically find all test .cpp files
file(GLOB TEST_SOURCES "*.cpp")

# Create a test executable for each test source file
foreach(TEST_SRC ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_SRC} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_SRC})
    target_link_libraries(${TEST_NAME} GTest::gtest GTest::gtest_main)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()
