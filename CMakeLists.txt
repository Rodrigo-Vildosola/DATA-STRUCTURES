cmake_minimum_required(VERSION 3.14)
project(StructsForge)

# Enable testing
enable_testing()

# Set the output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define build types
set(CMAKE_CONFIGURATION_TYPES "Debug;Release;Dist" CACHE STRING "" FORCE)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build." FORCE)
endif()

# Common compiler warnings
set(COMMON_WARNINGS "-Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Woverloaded-virtual -Wsign-conversion -Wnull-dereference")

# Add different compiler flags for different build types
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 ${COMMON_WARNINGS} -Werror")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG ${COMMON_WARNINGS}")
set(CMAKE_CXX_FLAGS_DIST "-O3 -DNDEBUG ${COMMON_WARNINGS}")

# Add definitions based on build type
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(ST_DEBUG)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_definitions(ST_RELEASE)
elseif(CMAKE_BUILD_TYPE STREQUAL "Dist")
    add_compile_definitions(ST_DIST)
endif()

# Add the external directories
add_subdirectory(external/googletest)
# add_subdirectory(STRUCTURES)
add_subdirectory(SANDBOX)
add_subdirectory(TESTS)

# Print build type
message("Build type: ${CMAKE_BUILD_TYPE}")
