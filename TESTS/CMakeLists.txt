cmake_minimum_required(VERSION 3.14)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../STRUCTURES/src)

# Add the test executable for ArrayTest
add_executable(ArrayTest ArrayTest.cpp)
target_link_libraries(ArrayTest gtest gtest_main structures)

# Register the ArrayTest with CTest
add_test(NAME ArrayTest COMMAND ArrayTest)

# If you have more tests in the future, add them similarly
# Example:
# add_executable(LinkedListTest LinkedListTest.cpp)
# target_link_libraries(LinkedListTest gtest gtest_main structures)
# add_test(NAME LinkedListTest COMMAND LinkedListTest)
