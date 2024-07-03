cmake_minimum_required(VERSION 3.14)
project(StructsForgeTests)

include_directories(${CMAKE_SOURCE_DIR}/STRUCTURES/src)

# Add test executable for Array
add_executable(ArrayTest ArrayTest.cpp)
target_link_libraries(ArrayTest gtest gtest_main structures)
add_test(NAME ArrayTest COMMAND ArrayTest)

# Add test executable for LinkedList
add_executable(LinkedListTest LinkedListTest.cpp)
target_link_libraries(LinkedListTest gtest gtest_main structures)
add_test(NAME LinkedListTest COMMAND LinkedListTest)
