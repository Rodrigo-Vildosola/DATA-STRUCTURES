#pragma once

#include <stdexcept>
#include <functional>
#include "Array/Array.h"

namespace STRUCTS {

    enum class HeapType {
        MinHeap,
        MaxHeap
    };

    template<typename T>
    class Heap {
    public:
        explicit Heap(HeapType type);
        ~Heap() = default;

        void insert(const T& value);
        T extract();
        const T& top() const;

        bool isEmpty() const { return data.isEmpty(); }
        int getSize() const { return data.getSize(); }

    private:
        Array<T> data;
        HeapType heapType;

        void heapifyUp(int index);
        void heapifyDown(int index);

        bool compare(const T& a, const T& b) const;
    };

}

#include "Heaps/Binary/Heap.tpp"
