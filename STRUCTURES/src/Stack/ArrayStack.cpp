#include "Stack/ArrayStack.h"

namespace STRUCTS {

    ArrayStack::ArrayStack() : size(0), capacity(10) {
        data = std::make_unique<int[]>(capacity);
    }

    ArrayStack::~ArrayStack() {
        // unique_ptr automatically handles memory deallocation
    }

    void ArrayStack::resize(int new_capacity) {
        std::unique_ptr<int[]> new_data = std::make_unique<int[]>(new_capacity);
        std::copy(&data[0], &data[size], &new_data[0]);
        data = std::move(new_data);
        capacity = new_capacity;
    }

    void ArrayStack::push(int value) {
        if (size >= capacity) {
            resize(capacity * 2);
        }
        data[size++] = value;
    }

    void ArrayStack::pop() {
        if (isEmpty()) {
            throw std::out_of_range("Pop Error: Stack is empty.");
        }
        --size;
    }

    int ArrayStack::top() const {
        if (isEmpty()) {
            throw std::out_of_range("Top Error: Stack is empty.");
        }
        return data[size - 1];
    }

    bool ArrayStack::isEmpty() const {
        return size == 0;
    }

    int ArrayStack::getSize() const {
        return size;
    }

}
