#include "Heaps/Binary/Heap.h"

namespace STRUCTS {

    template<typename T>
    Heap<T>::Heap(HeapType type) : root(nullptr), size(0), heapType(type) {}

    template<typename T>
    Heap<T>::~Heap() {
        // unique_ptr automatically handles memory deallocation
    }

    template<typename T>
    void Heap<T>::insert(const T& value) {
        root = insertRec(std::move(root), value);
        size++;
        heapifyUp(root);
    }

    template<typename T>
    std::unique_ptr<HeapNode<T>> Heap<T>::insertRec(std::unique_ptr<HeapNode<T>> node, const T& value) {
        if (!node) {
            return std::make_unique<HeapNode<T>>(value);
        }
        if (compare(value, node->data)) {
            swap(node->data, value);
        }
        if (!node->left) {
            node->left = insertRec(std::move(node->left), value);
        } else if (!node->right) {
            node->right = insertRec(std::move(node->right), value);
        } else if (node->left->right) {
            node->left = insertRec(std::move(node->left), value);
        } else {
            node->right = insertRec(std::move(node->right), value);
        }
        return node;
    }

    template<typename T>
    T Heap<T>::extract() {
        if (isEmpty()) {
            throw std::runtime_error("Heap is empty");
        }
        T extractedValue = root->data;
        root = extractRec(root, extractedValue);
        size--;
        if (!isEmpty()) {
            heapifyDown(root);
        }
        return extractedValue;
    }

    template<typename T>
    std::unique_ptr<HeapNode<T>> Heap<T>::extractRec(std::unique_ptr<HeapNode<T>>& node, T& extractedValue) {
        if (!node->left && !node->right) {
            return nullptr;
        }
        if (node->left && (!node->right || compare(node->left->data, node->right->data))) {
            node->data = node->left->data;
            node->left = extractRec(node->left, extractedValue);
        } else {
            node->data = node->right->data;
            node->right = extractRec(node->right, extractedValue);
        }
        return node;
    }

    template<typename T>
    void Heap<T>::heapifyDown(std::unique_ptr<HeapNode<T>>& node) {
        if (!node->left && !node->right) {
            return;
        }
        std::unique_ptr<HeapNode<T>>& child = (node->left && (!node->right || compare(node->left->data, node->right->data))) ? node->left : node->right;
        if (compare(child->data, node->data)) {
            swap(node->data, child->data);
            heapifyDown(child);
        }
    }

    template<typename T>
    void Heap<T>::heapifyUp(std::unique_ptr<HeapNode<T>>& node) {
        if (!node || (!node->left && !node->right)) {
            return;
        }
        std::unique_ptr<HeapNode<T>>& child = (node->left && (!node->right || compare(node->left->data, node->right->data))) ? node->left : node->right;
        if (compare(child->data, node->data)) {
            swap(node->data, child->data);
            heapifyUp(child);
        }
    }

    template<typename T>
    const T& Heap<T>::top() const {
        if (isEmpty()) {
            throw std::runtime_error("Heap is empty");
        }
        return root->data;
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
