#include "Heaps/Binary/Heap.h"

namespace STRUCTS {

    template<typename T>
    Heap<T>::Heap(HeapType type) : heapType(type) {}

    template<typename T>
    void Heap<T>::insert(const T& value) {
        data.append(value);
        heapifyUp(data.getSize() - 1);
    }

    template<typename T>
    T Heap<T>::extract() {
        if (isEmpty()) {
            throw std::runtime_error("Heap is empty");
        }
        T extractedValue = data[0];
        data[0] = data[data.getSize() - 1];
        data.remove(data.getSize() - 1);
        if (!isEmpty()) {
            heapifyDown(0);
        }
        return extractedValue;
    }

    template<typename T>
    const T& Heap<T>::top() const {
        if (isEmpty()) {
            throw std::runtime_error("Heap is empty");
        }
        return data[0];
    }

    template<typename T>
    void Heap<T>::heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (compare(data[index], data[parentIndex])) {
                std::swap(data[index], data[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    template<typename T>
    void Heap<T>::heapifyDown(int index) {
        int size = data.getSize();
        while (true) {
            int leftIndex = 2 * index + 1;
            int rightIndex = 2 * index + 2;
            int smallestOrLargest = index;

            if (leftIndex < size && compare(data[leftIndex], data[smallestOrLargest])) {
                smallestOrLargest = leftIndex;
            }
            if (rightIndex < size && compare(data[rightIndex], data[smallestOrLargest])) {
                smallestOrLargest = rightIndex;
            }
            if (smallestOrLargest != index) {
                std::swap(data[index], data[smallestOrLargest]);
                index = smallestOrLargest;
            } else {
                break;
            }
        }
    }

    template<typename T>
    bool Heap<T>::compare(const T& a, const T& b) const {
        if (heapType == HeapType::MinHeap) {
            return a < b;
        } else {
            return a > b;
        }
    }

}
