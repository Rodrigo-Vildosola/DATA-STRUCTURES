#!/bin/bash

# Define the build directory
BUILD_DIR="build"

# Default build type
BUILD_TYPE="Release"

# Allowed build types
ALLOWED_BUILD_TYPES=("Debug" "Release" "Dist")

# Function to display usage
function usage() {
    echo "Usage: $0 [clean|build|run|recreate] [Debug|Release|Dist] [array|linked_list]"
    echo "  clean         - Remove the build directory"
    echo "  build         - Create the build directory and compile the project"
    echo "  run           - Build and run the project (default array)"
    echo "  recreate      - Remove the build directory and rebuild"
    echo "  Debug|Release|Dist - Optional: specify build type (default is Release)"
    echo "  array|linked_list - Optional: specify program to run (default is array)"
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

PROGRAM="array"

# Check arguments
if [ $# -lt 1 ] || [ $# -gt 3 ]; then
    usage
    exit 1
fi

if [ $# -ge 2 ]; then
    BUILD_TYPE=$2
fi

if [ $# -ge 3 ]; then
    PROGRAM=$3
fi

if ! is_valid_build_type "$BUILD_TYPE"; then
    echo "Error: Invalid build type '$BUILD_TYPE'"
    usage
    exit 1
fi

case $1 in
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
    *)
        usage
        exit 1
        ;;
esac
