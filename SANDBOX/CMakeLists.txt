cmake_minimum_required(VERSION 3.14)
project(Sandbox)

include_directories(${CMAKE_SOURCE_DIR}/STRUCTURES/src)

# Automatically find all .cpp files in the src directory
file(GLOB_RECURSE SANDBOX_SOURCES "src/**/*.cpp")

# Loop through each source file and create an executable
foreach(SOURCE_FILE ${SANDBOX_SOURCES})
    get_filename_component(EXECUTABLE_NAME ${SOURCE_FILE} NAME_WE)
    add_executable(${EXECUTABLE_NAME} ${SOURCE_FILE})
    target_link_libraries(${EXECUTABLE_NAME} structures)
endforeach()
