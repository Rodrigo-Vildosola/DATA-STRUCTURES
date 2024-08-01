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

void priorityQueueExample() {
    std::cout << "Priority Queue Example with Heap<int>..." << std::endl;
    STRUCTS::Heap<int> maxHeap(STRUCTS::HeapType::MaxHeap);

    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(5);
    maxHeap.insert(30);
    maxHeap.insert(15);

    std::cout << "Max Priority Queue elements: ";
    while (!maxHeap.isEmpty()) {
        std::cout << maxHeap.extract() << " ";
    }
    std::cout << std::endl;
}

void heapSortExample() {
    std::cout << "Heap Sort Example with Heap<int>..." << std::endl;
    std::vector<int> values = {10, 20, 5, 3, 7, 15, 25};

    STRUCTS::Heap<int> minHeap(STRUCTS::HeapType::MinHeap);
    for (const auto& value : values) {
        minHeap.insert(value);
    }

    std::cout << "Sorted elements using Min-Heap: ";
    while (!minHeap.isEmpty()) {
        std::cout << minHeap.extract() << " ";
    }
    std::cout << std::endl;

    STRUCTS::Heap<int> maxHeap(STRUCTS::HeapType::MaxHeap);
    for (const auto& value : values) {
        maxHeap.insert(value);
    }

    std::cout << "Sorted elements using Max-Heap: ";
    while (!maxHeap.isEmpty()) {
        std::cout << maxHeap.extract() << " ";
    }
    std::cout << std::endl;
}

void medianMaintenanceExample() {
    std::cout << "Median Maintenance Example with Heaps..." << std::endl;
    STRUCTS::Heap<int> maxHeap(STRUCTS::HeapType::MaxHeap); // Max-heap for the lower half
    STRUCTS::Heap<int> minHeap(STRUCTS::HeapType::MinHeap); // Min-heap for the upper half

    auto insertNumber = [&](int num) {
        if (maxHeap.isEmpty() || num <= maxHeap.top()) {
            maxHeap.insert(num);
        } else {
            minHeap.insert(num);
        }

        if (maxHeap.getSize() > minHeap.getSize() + 1) {
            minHeap.insert(maxHeap.extract());
        } else if (minHeap.getSize() > maxHeap.getSize()) {
            maxHeap.insert(minHeap.extract());
        }
    };

    auto getMedian = [&]() -> double {
        if (maxHeap.getSize() > minHeap.getSize()) {
            return maxHeap.top();
        } else {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    };

    std::vector<int> numbers = {5, 15, 1, 3, 8, 7, 9, 10};
    for (const auto& num : numbers) {
        insertNumber(num);
        std::cout << "Inserted: " << num << ", Current Median: " << getMedian() << std::endl;
    }
}


int main() {
    testIntHeap();
    std::cout << std::endl;

    testStringHeap();
    std::cout << std::endl;

    testPersonHeap();
    std::cout << std::endl;


    priorityQueueExample();
    std::cout << std::endl;

    heapSortExample();
    std::cout << std::endl;

    medianMaintenanceExample();


    return 0;
}
