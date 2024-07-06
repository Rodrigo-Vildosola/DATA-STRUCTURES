#include "Stack/ArrayStack.h"

namespace STRUCTS {

    template <typename T>
    ArrayStack<T>::ArrayStack(int initial_capacity) : size(0), capacity(initial_capacity) {
        data = std::make_unique<T[]>(static_cast<size_t>(capacity));
    }

    template <typename T>
    ArrayStack<T>::~ArrayStack() {
        // unique_ptr automatically handles memory deallocation
    }

    template <typename T>
    ArrayStack<T>::ArrayStack(const ArrayStack& other) : size(other.size), capacity(other.capacity) {
        data = std::make_unique<T[]>(static_cast<size_t>(capacity));
        std::copy(&other.data[0], &other.data[static_cast<size_t>(size)], &data[0]);
    }

    template <typename T>
    ArrayStack<T>::ArrayStack(ArrayStack&& other) noexcept : size(other.size), capacity(other.capacity), data(std::move(other.data)) {
        other.size = 0;
        other.capacity = 0;
    }

    template <typename T>
    ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack& other) {
        if (this == &other) {
            return *this;
        }
        size = other.size;
        capacity = other.capacity;
        data = std::make_unique<T[]>(static_cast<size_t>(capacity));
        std::copy(&other.data[0], &other.data[static_cast<size_t>(size)], &data[0]);
        return *this;
    }

    template <typename T>
    ArrayStack<T>& ArrayStack<T>::operator=(ArrayStack&& other) noexcept {
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

    template <typename T>
    bool ArrayStack<T>::operator==(const ArrayStack& other) const {
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

    template <typename T>
    bool ArrayStack<T>::operator!=(const ArrayStack& other) const {
        return !(*this == other);
    }

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const ArrayStack<T>& stack) {
        for (int i = stack.size - 1; i >= 0; --i) {
            os << stack.data[static_cast<size_t>(i)] << " ";
        }
        return os;
    }

    template <typename T>
    void ArrayStack<T>::resize(int new_capacity) {
        std::unique_ptr<T[]> new_data = std::make_unique<T[]>(static_cast<size_t>(new_capacity));
        std::copy(&data[0], &data[static_cast<size_t>(size)], &new_data[0]);
        data = std::move(new_data);
        capacity = new_capacity;
    }

    template <typename T>
    void ArrayStack<T>::push(const T& value) {
        if (size >= capacity) {
            resize(capacity * 2);
        }
        data[static_cast<size_t>(size++)] = value;
    }

    template <typename T>
    void ArrayStack<T>::pop() {
        if (isEmpty()) {
            throw std::out_of_range("Pop Error: Stack is empty.");
        }
        --size;
        if (size <= capacity / 4 && capacity > 10) {
            resize(capacity / 2);
        }
    }

    template <typename T>
    T ArrayStack<T>::top() const {
        if (isEmpty()) {
            throw std::out_of_range("Top Error: Stack is empty.");
        }
        return data[static_cast<size_t>(size - 1)];
    }

    template <typename T>
    bool ArrayStack<T>::isEmpty() const {
        return size == 0;
    }

    template <typename T>
    int ArrayStack<T>::getSize() const {
        return size;
    }

    template <typename T>
    void ArrayStack<T>::clear() {
        data.reset();
        size = 0;
        capacity = 10;
        data = std::make_unique<T[]>(static_cast<size_t>(capacity));
    }

} // namespace STRUCTS
