#!/bin/bash

# Define the build directory
BUILD_DIR="build"

# Default build type
BUILD_TYPE="Release"

# Allowed build types
ALLOWED_BUILD_TYPES=("Debug" "Release" "Dist")

# Function to display usage
function usage() {
    echo "Usage: $0 [clean|build|run|recreate|test] [array|linked_list] [Debug|Release|Dist]"
    echo "  clean                - Remove the build directory"
    echo "  build                - Create the build directory and compile the project"
    echo "  run                  - Build and run the project (default array)"
    echo "  recreate             - Remove the build directory and rebuild"
    echo "  test                 - Build and run tests"
    echo "  Array|LinkedList     - Optional: specify program to run (default is array)"
    echo "  Debug|Release|Dist   - Optional: specify build type (default is Release)"
}

# Check if the build type is allowed
function is_valid_build_type() {
    local build_type=$1
    for type in "${ALLOWED_BUILD_TYPES[@]}"; do
        if [[ "$type" == "$build_type" ]]; then
            return 0
        fi
    done
    return 1
}

# Default program to run
PROGRAM="ArrayDemo"

# Parse arguments
ACTION=$1
shift

while (( "$#" )); do
    case "$1" in
        Debug|Release|Dist)
            BUILD_TYPE=$1
            ;;
        *)
            PROGRAM=$1
            ;;
    esac
    shift
done

if ! is_valid_build_type "$BUILD_TYPE"; then
    echo "Error: Invalid build type '$BUILD_TYPE'"
    usage
    exit 1
fi

case $ACTION in
    clean)
        echo "Cleaning build directory..."
        rm -rf $BUILD_DIR
        echo "Build directory removed."
        ;;
    build)
        echo "Creating build directory..."
        mkdir -p $BUILD_DIR/$BUILD_TYPE
        cd $BUILD_DIR/$BUILD_TYPE || exit
        echo "Running cmake..."
        cmake -G Ninja -DCMAKE_BUILD_TYPE=$BUILD_TYPE ../..
        echo "Building the project..."
        if ninja; then
            echo "Build complete."
        else
            echo "Build failed."
            exit 1
        fi
        ;;
    run)
        echo "Creating build directory if it does not exist..."
        mkdir -p $BUILD_DIR/$BUILD_TYPE
        cd $BUILD_DIR/$BUILD_TYPE || exit
        echo "Running cmake..."
        cmake -G Ninja -DCMAKE_BUILD_TYPE=$BUILD_TYPE ../..
        echo "Building the project..."
        if ninja; then
            echo "Build complete. Running the project..."
            echo ""
            ./bin/$PROGRAM
        else
            echo "Build failed. Not running the project."
            exit 1
        fi
        ;;
    recreate)
        echo "Removing build directory..."
        rm -rf $BUILD_DIR/$BUILD_TYPE
        echo "Creating build directory..."
        mkdir -p $BUILD_DIR/$BUILD_TYPE
        cd $BUILD_DIR/$BUILD_TYPE || exit
        echo "Running cmake..."
        cmake -G Ninja -DCMAKE_BUILD_TYPE=$BUILD_TYPE ../..
        echo "Building the project..."
        if ninja; then
            echo "Rebuild complete."
        else
            echo "Build failed."
            exit 1
        fi
        ;;
    test)
        echo "Creating build directory if it does not exist..."
        mkdir -p $BUILD_DIR/$BUILD_TYPE
        cd $BUILD_DIR/$BUILD_TYPE || exit
        echo "Running cmake..."
        cmake -G Ninja -DCMAKE_BUILD_TYPE=$BUILD_TYPE ../..
        echo "Building the project..."
        if ninja; then
            echo "Build of tests complete."
        else
            echo "Build failed. Not running tests."
            exit 1
        fi
        echo "Running tests..."
        ctest --output-on-failure
        ;;
    *)
        usage
        exit 1
        ;;
esac
