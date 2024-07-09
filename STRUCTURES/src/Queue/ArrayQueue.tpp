#include "Queue/ArrayQueue.h"

namespace STRUCTS {

    template <typename T>
    ArrayQueue<T>::ArrayQueue(int initial_capacity)
        : size(0), capacity(initial_capacity), frontIndex(0), rearIndex(-1) {
        data = std::make_unique<T[]>(static_cast<size_t>(capacity));
    }

    template <typename T>
    ArrayQueue<T>::~ArrayQueue() {
        // unique_ptr automatically handles memory deallocation
    }

    template <typename T>
    ArrayQueue<T>::ArrayQueue(const ArrayQueue& other)
        : size(other.size), capacity(other.capacity), frontIndex(other.frontIndex), rearIndex(other.rearIndex) {
        data = std::make_unique<T[]>(static_cast<size_t>(capacity));
        std::copy(&other.data[0], &other.data[static_cast<size_t>(capacity)], &data[0]);
    }

    template <typename T>
    ArrayQueue<T>::ArrayQueue(ArrayQueue&& other) noexcept
        : size(other.size), capacity(other.capacity), frontIndex(other.frontIndex), rearIndex(other.rearIndex), data(std::move(other.data)) {
        other.size = 0;
        other.capacity = 0;
        other.frontIndex = 0;
        other.rearIndex = -1;
    }

    template <typename T>
    ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue& other) {
        if (this == &other) {
            return *this;
        }
        size = other.size;
        capacity = other.capacity;
        frontIndex = other.frontIndex;
        rearIndex = other.rearIndex;
        data = std::make_unique<T[]>(static_cast<size_t>(capacity));
        std::copy(&other.data[0], &other.data[static_cast<size_t>(capacity)], &data[0]);
        return *this;
    }

    template <typename T>
    ArrayQueue<T>& ArrayQueue<T>::operator=(ArrayQueue&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        size = other.size;
        capacity = other.capacity;
        frontIndex = other.frontIndex;
        rearIndex = other.rearIndex;
        data = std::move(other.data);
        other.size = 0;
        other.capacity = 0;
        other.frontIndex = 0;
        other.rearIndex = -1;
        return *this;
    }

    template <typename T>
    bool ArrayQueue<T>::operator==(const ArrayQueue& other) const {
        if (size != other.size || capacity != other.capacity || frontIndex != other.frontIndex || rearIndex != other.rearIndex) {
            return false;
        }
        for (size_t i = 0; i < static_cast<size_t>(size); ++i) {
            if (data[(static_cast<size_t>(frontIndex) + i) % static_cast<size_t>(capacity)] != 
                other.data[(static_cast<size_t>(other.frontIndex) + i) % static_cast<size_t>(other.capacity)]) {
                return false;
            }
        }
        return true;
    }

    template <typename T>
    bool ArrayQueue<T>::operator!=(const ArrayQueue& other) const {
        return !(*this == other);
    }

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const ArrayQueue<T>& queue) {
        for (size_t i = 0; i < static_cast<size_t>(queue.size); ++i) {
            os << queue.data[(static_cast<size_t>(queue.frontIndex) + i) % static_cast<size_t>(queue.capacity)] << " ";
        }
        return os;
    }

    template <typename T>
    void ArrayQueue<T>::resize(int new_capacity) {
        std::unique_ptr<T[]> new_data = std::make_unique<T[]>(static_cast<size_t>(new_capacity));
        for (size_t i = 0; i < static_cast<size_t>(size); ++i) {
            new_data[i] = data[(static_cast<size_t>(frontIndex) + i) % static_cast<size_t>(capacity)];
        }
        data = std::move(new_data);
        capacity = new_capacity;
        frontIndex = 0;
        rearIndex = size - 1;
    }

    template <typename T>
    void ArrayQueue<T>::enqueue(const T& value) {
        if (size >= capacity) {
            resize(capacity * 2);
        }
        rearIndex = (rearIndex + 1) % capacity;
        data[static_cast<size_t>(rearIndex)] = value;
        ++size;
    }

    template <typename T>
    void ArrayQueue<T>::dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Dequeue Error: Queue is empty.");
        }
        frontIndex = (frontIndex + 1) % capacity;
        --size;
        if (size <= capacity / 4 && capacity > 10) {
            resize(capacity / 2);
        }
    }

    template <typename T>
    T ArrayQueue<T>::front() const {
        if (isEmpty()) {
            throw std::out_of_range("Front Error: Queue is empty.");
        }
        return data[static_cast<size_t>(frontIndex)];
    }

    template <typename T>
    bool ArrayQueue<T>::isEmpty() const {
        return size == 0;
    }

    template <typename T>
    int ArrayQueue<T>::getSize() const {
        return size;
    }

    template <typename T>
    void ArrayQueue<T>::clear() {
        data.reset();
        size = 0;
        capacity = 10;
        frontIndex = 0;
        rearIndex = -1;
        data = std::make_unique<T[]>(static_cast<size_t>(capacity));
    }

} // namespace STRUCTS
