cmake_minimum_required(VERSION 3.14)
project(StructuresLib)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# Add source files for the data structures
add_library(structures
    src/Array/Array.cpp
    src/LinkedList/LinkedList.cpp
    # Add more data structure source files here
)

# Link Google Test libraries for testing purposes
# target_link_libraries(structures gtest _main)
