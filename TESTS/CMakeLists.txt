cmake_minimum_required(VERSION 3.14)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../STRUCTURES/src)

# Add the test executable
add_executable(ArrayTest ArrayTest.cpp)

# Link Google Test and the structures library to the test executable
target_link_libraries(ArrayTest gtest gtest_main structures)

# Add a custom target to run the tests
add_custom_target(tests
    COMMAND ArrayTest
    DEPENDS ArrayTest
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)
