#pragma once

#include <memory>
#include <functional>
#include <stdexcept>

namespace STRUCTS {

    enum class HeapType {
        MinHeap,
        MaxHeap
    };

    template<typename T>
    struct HeapNode {
        T data;
        std::unique_ptr<HeapNode> left;
        std::unique_ptr<HeapNode> right;

        HeapNode(const T& value) : data(value), left(nullptr), right(nullptr) {}
    };

    template<typename T>
    class Heap {
    public:
        explicit Heap(HeapType type);
        ~Heap();

        void insert(const T& value);
        T extract();
        const T& top() const;

        bool isEmpty() const { return size == 0; }
        int getSize() const { return size; }

    private:
        std::unique_ptr<HeapNode<T>> root;
        int size;
        HeapType heapType;

        std::unique_ptr<HeapNode<T>> insertRec(std::unique_ptr<HeapNode<T>> node, const T& value);
        std::unique_ptr<HeapNode<T>> extractRec(std::unique_ptr<HeapNode<T>>& node, T& extractedValue);
        void heapifyDown(std::unique_ptr<HeapNode<T>>& node);
        void heapifyUp(std::unique_ptr<HeapNode<T>>& node);

        void swap(T& a, T& b) {
            T temp = std::move(a);
            a = std::move(b);
            b = std::move(temp);
        }

        bool compare(const T& a, const T& b) const;
    };

}

#include "Heaps/Binary/Heap.tpp"
