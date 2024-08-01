#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <algorithm>
#include "Structs.h" // Ensure this header contains necessary includes and definitions
#include "DTypes.h"  // Ensure this header contains necessary includes and definitions

using namespace std::chrono;

// Function to generate a list of random positions
std::vector<size_t> generateRandomPositions(int numElements, int range) {
    std::vector<size_t> positions(numElements);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dis(0, range - 1);

    std::generate(positions.begin(), positions.end(), [&]() { return dis(gen); });
    return positions;
}

// Template function to benchmark append operation
template <typename Container>
void benchmarkAppend(Container& container, int numElements) {
    auto start = high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i) {
        container.append(Person("Name", i));
    }
    auto end = high_resolution_clock::now();
    std::cout << "Append " << numElements << " elements: " 
              << duration_cast<milliseconds>(end - start).count() 
              << "ms" << std::endl;
}

// Template function to benchmark insert at random positions
template <typename Container>
void benchmarkInsertAtRandomPositions(Container& container, int numElements, const std::vector<size_t>& positions) {
    auto start = high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i) {
        container.insert(static_cast<int>(positions[i]), Person("Name", i));
    }
    auto end = high_resolution_clock::now();
    std::cout << "Insert " << numElements << " elements at random positions: " 
              << duration_cast<milliseconds>(end - start).count() 
              << "ms" << std::endl;
}

// Template function to benchmark traverse operation
template <typename Container>
void benchmarkTraverse(Container& container) {
    auto start = high_resolution_clock::now();
    container.traverse([](const auto& value) {
        // Do nothing, just traverse
        (void)value;
    });
    auto end = high_resolution_clock::now();
    std::cout << "Traverse: " 
              << duration_cast<milliseconds>(end - start).count() 
              << "ms" << std::endl;
}

// Template function to benchmark search operation
template <typename Container, typename T>
void benchmarkSearch(const Container& container, const T& value) {
    auto start = high_resolution_clock::now();
    bool found = container.search(Person("Name", value));
    auto end = high_resolution_clock::now();
    std::cout << "Search for value " << Person("Name", value) << ": " 
              << duration_cast<milliseconds>(end - start).count() 
              << "ms" << std::endl;
    std::cout << "Value " << (found ? "found" : "not found") << std::endl;
}

// Template function to benchmark delete operation at random positions
template <typename Container>
void benchmarkDeleteAtRandomPositions(Container& container, int numElements, const std::vector<size_t>& positions) {
    auto start = high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i) {
        container.remove(static_cast<int>(positions[i]));
    }
    auto end = high_resolution_clock::now();
    std::cout << "Delete " << numElements << " elements at random positions: " 
              << duration_cast<milliseconds>(end - start).count() 
              << "ms" << std::endl;
}

// Template function to calculate memory usage for arrays
template <typename T>
size_t calculateMemoryUsage(const STRUCTS::Array<T>& array) {
    return sizeof(array) + static_cast<size_t>(array.getCapacity()) * sizeof(T);
}

// Template function to calculate memory usage for linked lists
template <typename T>
size_t calculateMemoryUsage(const STRUCTS::LinkedList<T>& list) {
    size_t memoryUsage = sizeof(list);
    list.traverse([&memoryUsage](const T& value) {
        memoryUsage += sizeof(STRUCTS::Node<T>); // Size of the node
        (void)value;
    });
    return memoryUsage;
}

int main() {
    const int numElements = 10000;

    // Generate random positions for insertion and deletion
    std::vector<size_t> randomPositions = generateRandomPositions(numElements, numElements);

    // Create instances of Array and LinkedList
    STRUCTS::Array<Person> array;
    STRUCTS::LinkedList<Person> linkedList;

    std::cout << "Benchmarking Array" << std::endl;
    benchmarkAppend(array, numElements);
    benchmarkInsertAtRandomPositions(array, numElements, randomPositions);
    benchmarkTraverse(array);
    benchmarkSearch(array, numElements / 2);
    benchmarkDeleteAtRandomPositions(array, numElements, randomPositions);
    std::cout << "Array Memory Usage: " << calculateMemoryUsage(array) << " bytes" << std::endl;

    std::cout << std::endl;
    std::cout << "Benchmarking LinkedList" << std::endl;
    benchmarkAppend(linkedList, numElements);
    benchmarkInsertAtRandomPositions(linkedList, numElements, randomPositions);
    benchmarkTraverse(linkedList);
    benchmarkSearch(linkedList, numElements / 2);
    benchmarkDeleteAtRandomPositions(linkedList, numElements, randomPositions);
    std::cout << "LinkedList Memory Usage: " << calculateMemoryUsage(linkedList) << " bytes" << std::endl;

    return 0;
}
