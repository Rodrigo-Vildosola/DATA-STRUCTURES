# StructsForge

StructsForge is a library of fundamental data structures implemented in C++. The project includes a variety of data structures, along with testing and examples. The library aims to provide efficient and easy-to-use implementations that can be integrated into other projects.

## Features

- **Data Structures**:
  - Dynamic Array
  - Linked List
  - (More to be added)

- **Testing**:
  - Comprehensive unit tests for all data structures using Google Test.

- **Examples**:
  - Example programs demonstrating the usage of each data structure.

## Dependencies

- **CMake**: A cross-platform tool to manage the build process.
- **Google Test**: A testing framework for C++.
- **Ninja** (optional): A small build system with a focus on speed.

## Directory Structure
```
.
├── CMakeLists.txt
├── README.md
├── SANDBOX
│   ├── CMakeLists.txt
│   └── src
│       ├── Array
│       │   └── ArrayDemo.cpp
│       └── LinkedList
│           └── LinkedListDemo.cpp
├── STRUCTURES
│   ├── CMakeLists.txt
│   └── src
│       ├── Array
│       │   ├── Array.cpp
│       │   └── Array.h
│       ├── LinkedList
│       │   ├── LinkedList.cpp
│       │   └── LinkedList.h
│       └── Structs.h
├── TESTS
│   ├── ArrayTest.cpp
│   └── CMakeLists.txt
└── build.sh
```

## Building the Project

### Prerequisites

Make sure you have the following tools installed:

- **CMake** (version 3.14 or higher)
- **GCC** or **Clang**
- **Ninja** (optional but recommended for faster builds)
- **Google Test** (added as a submodule)

### Clone the Repository

```sh
git clone --recurse-submodules https://github.com/yourusername/StructsForge.git
cd StructsForge
```

### Build Steps

1. **Build the Project**

    ```sh
    ./build.sh build Debug
    ```

    This command will create a build directory, run CMake, and compile the project.

2. **Run Examples**

    To run the array demo:

    ```sh
    ./build.sh run Debug Array
    ```

    To run the linked list demo:

    ```sh
    ./build.sh run Debug LinkedList
    ```

3. **Run All Tests**

    ```sh
    ./build.sh test Debug
    ```

    This command will build the project and run all tests using CTest.



## Contributing

Contributions are welcome! Please fork the repository and submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
```
