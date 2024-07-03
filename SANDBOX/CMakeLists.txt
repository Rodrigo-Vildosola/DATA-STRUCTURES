cmake_minimum_required(VERSION 3.10)
project(SandboxDemos)

# Include the STRUCTURES library
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../STRUCTURES/src)

# Add executables for each demo
add_executable(Array src/Array/ArrayDemo.cpp)
target_link_libraries(Array structures)

add_executable(LinkedList src/LinkedList/LinkedListDemo.cpp)
target_link_libraries(LinkedList structures)

# Add more demos as needed
