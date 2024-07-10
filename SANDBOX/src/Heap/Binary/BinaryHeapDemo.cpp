#include <iostream>
#include <vector>
#include <string>
#include <DTypes.h>
#include <Structs.h>

void printIntHeap(STRUCTS::Heap<int>& heap) {
    std::cout << "Heap elements: ";
    while (!heap.isEmpty()) {
        std::cout << heap.extract() << " ";
    }
    std::cout << std::endl;
}

void printStringHeap(STRUCTS::Heap<std::string>& heap) {
    std::cout << "Heap elements: ";
    while (!heap.isEmpty()) {
        std::cout << heap.extract() << " ";
    }
    std::cout << std::endl;
}

void printPersonHeap(STRUCTS::Heap<Person>& heap) {
    std::cout << "Heap elements: ";
    while (!heap.isEmpty()) {
        std::cout << heap.extract() << " ";
    }
    std::cout << std::endl;
}

void testIntHeap() {
    std::cout << "Testing Heap<int>..." << std::endl;
    STRUCTS::Heap<int> minHeap(STRUCTS::HeapType::MinHeap);
    STRUCTS::Heap<int> maxHeap(STRUCTS::HeapType::MaxHeap);

    std::vector<int> values = {10, 20, 5, 3, 7, 15, 25};
    for (const auto& value : values) {
        minHeap.insert(value);
        maxHeap.insert(value);
    }

    std::cout << "Min-Heap: ";
    printIntHeap(minHeap);

    std::cout << "Max-Heap: ";
    printIntHeap(maxHeap);
}

void testStringHeap() {
    std::cout << "Testing Heap<std::string>..." << std::endl;
    STRUCTS::Heap<std::string> minHeap(STRUCTS::HeapType::MinHeap);
    STRUCTS::Heap<std::string> maxHeap(STRUCTS::HeapType::MaxHeap);

    std::vector<std::string> values = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape"};
    for (const auto& value : values) {
        minHeap.insert(value);
        maxHeap.insert(value);
    }

    std::cout << "Min-Heap: ";
    printStringHeap(minHeap);

    std::cout << "Max-Heap: ";
    printStringHeap(maxHeap);
}

void testPersonHeap() {
    std::cout << "Testing Heap<Person>..." << std::endl;
    STRUCTS::Heap<Person> minHeap(STRUCTS::HeapType::MinHeap);
    STRUCTS::Heap<Person> maxHeap(STRUCTS::HeapType::MaxHeap);

    std::vector<Person> values = {Person("Alice", 30), Person("Bob", 25), Person("Charlie", 35)};
    for (const auto& value : values) {
        minHeap.insert(value);
        maxHeap.insert(value);
    }

    std::cout << "Min-Heap: ";
    printPersonHeap(minHeap);

    std::cout << "Max-Heap: ";
    printPersonHeap(maxHeap);
}

int main() {
    testIntHeap();
    std::cout << std::endl;

    testStringHeap();
    std::cout << std::endl;

    testPersonHeap();

    return 0;
}
