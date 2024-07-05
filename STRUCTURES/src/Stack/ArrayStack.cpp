#include "Stack/ArrayStack.h"

namespace STRUCTS {

    ArrayStack::ArrayStack(int initial_capacity) : size(0), capacity(initial_capacity) {
        data = std::make_unique<int[]>(static_cast<size_t>(capacity));
    }

    ArrayStack::~ArrayStack() {
        // unique_ptr automatically handles memory deallocation
    }

    ArrayStack::ArrayStack(const ArrayStack& other) : size(other.size), capacity(other.capacity) {
        data = std::make_unique<int[]>(static_cast<size_t>(capacity));
        std::copy(&other.data[0], &other.data[static_cast<size_t>(size)], &data[0]);
    }

    ArrayStack::ArrayStack(ArrayStack&& other) noexcept : size(other.size), capacity(other.capacity), data(std::move(other.data)) {
        other.size = 0;
        other.capacity = 0;
    }

    ArrayStack& ArrayStack::operator=(const ArrayStack& other) {
        if (this == &other) {
            return *this;
        }
        size = other.size;
        capacity = other.capacity;
        data = std::make_unique<int[]>(static_cast<size_t>(capacity));
        std::copy(&other.data[0], &other.data[static_cast<size_t>(size)], &data[0]);
        return *this;
    }

    ArrayStack& ArrayStack::operator=(ArrayStack&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        size = other.size;
        capacity = other.capacity;
        data = std::move(other.data);
        other.size = 0;
        other.capacity = 0;
        return *this;
    }

    bool ArrayStack::operator==(const ArrayStack& other) const {
        if (size != other.size) {
            return false;
        }
        for (int i = 0; i < size; ++i) {
            if (data[static_cast<size_t>(i)] != other.data[static_cast<size_t>(i)]) {
                return false;
            }
        }
        return true;
    }

    bool ArrayStack::operator!=(const ArrayStack& other) const {
        return !(*this == other);
    }

    std::ostream& operator<<(std::ostream& os, const ArrayStack& stack) {
        for (int i = stack.size - 1; i >= 0; --i) {
            os << stack.data[static_cast<size_t>(i)] << " ";
        }
        return os;
    }

    void ArrayStack::resize(int new_capacity) {
        std::unique_ptr<int[]> new_data = std::make_unique<int[]>(static_cast<size_t>(new_capacity));
        std::copy(&data[0], &data[static_cast<size_t>(size)], &new_data[0]);
        data = std::move(new_data);
        capacity = new_capacity;
    }

    void ArrayStack::push(int value) {
        if (size >= capacity) {
            resize(capacity * 2);
        }
        data[static_cast<size_t>(size++)] = value;
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
        return data[static_cast<size_t>(size - 1)];
    }

    bool ArrayStack::isEmpty() const {
        return size == 0;
    }

    int ArrayStack::getSize() const {
        return size;
    }

}
