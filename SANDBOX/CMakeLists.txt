cmake_minimum_required(VERSION 3.14)
project(Sandbox)

include_directories(${CMAKE_SOURCE_DIR}/STRUCTURES/src)

add_executable(ArrayDemo src/Array/ArrayDemo.cpp)
target_link_libraries(ArrayDemo structures)

add_executable(LinkedListDemo src/LinkedList/LinkedListDemo.cpp)
target_link_libraries(LinkedListDemo structures)
