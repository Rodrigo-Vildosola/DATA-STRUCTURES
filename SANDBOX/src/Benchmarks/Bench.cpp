#include <iostream>
#include <chrono>
#include <Structs.h>
#include <DTypes.h>

using namespace std::chrono;

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

template <typename Container>
void benchmarkInsertAtPosition(Container& container, int numElements, int position) {
    auto start = high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i) {
        container.insert(position, Person("Name", i));
    }
    auto end = high_resolution_clock::now();
    std::cout << "Insert " << numElements << " elements at position " << position << ": " 
              << duration_cast<milliseconds>(end - start).count() 
              << "ms" << std::endl;
}

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

template <typename Container, typename T>
void benchmarkSearch(const Container& container, const T& value) {
    auto start = high_resolution_clock::now();
    bool found = container.search(Person("Name", value));
    auto end = high_resolution_clock::now();
    std::cout << "Search for value " << Person("Name", value) << ": " 
              << duration_cast<milliseconds>(end - start).count() 
              << " ms" << std::endl;
    std::cout << "Value " << (found ? "found" : "not found") << std::endl;
}

template <typename T>
size_t calculateMemoryUsage(const STRUCTS::Array<T>& array) {
    return sizeof(array) + static_cast<size_t>(array.getCapacity()) * sizeof(T);
}

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
    const int position = numElements / 2;

    STRUCTS::Array<Person> array;
    STRUCTS::LinkedList<Person> linkedList;

    std::cout << "Benchmarking Array" << std::endl;
    benchmarkAppend(array, numElements);
    benchmarkInsertAtPosition(array, numElements, position);
    benchmarkTraverse(array);
    benchmarkSearch(array, numElements / 2);
    std::cout << "Array Memory Usage: " << calculateMemoryUsage(array) << " bytes" << std::endl;

    std::cout << "Benchmarking LinkedList" << std::endl;
    benchmarkAppend(linkedList, numElements);
    benchmarkInsertAtPosition(linkedList, numElements, position);
    benchmarkTraverse(linkedList);
    benchmarkSearch(linkedList, numElements / 2);
    std::cout << "LinkedList Memory Usage: " << calculateMemoryUsage(linkedList) << " bytes" << std::endl;

    return 0;
}
