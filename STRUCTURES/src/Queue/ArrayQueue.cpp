#include "Queue/ArrayQueue.h"

namespace STRUCTS {

    ArrayQueue::ArrayQueue(int capacity)
        : size(0), capacity(capacity), frontIndex(0), rearIndex(-1) {
        data = std::make_unique<int[]>(static_cast<size_t>(capacity));
    }

    ArrayQueue::~ArrayQueue() {
        // unique_ptr automatically handles memory deallocation
    }

    ArrayQueue::ArrayQueue(const ArrayQueue& other)
        : size(other.size), capacity(other.capacity), frontIndex(other.frontIndex), rearIndex(other.rearIndex) {
        data = std::make_unique<int[]>(static_cast<size_t>(capacity));
        std::copy(&other.data[0], &other.data[static_cast<size_t>(capacity)], &data[0]);
    }

    ArrayQueue::ArrayQueue(ArrayQueue&& other) noexcept
        : size(other.size), capacity(other.capacity), frontIndex(other.frontIndex), rearIndex(other.rearIndex), data(std::move(other.data)) {
        other.size = 0;
        other.capacity = 0;
        other.frontIndex = 0;
        other.rearIndex = -1;
    }

    ArrayQueue& ArrayQueue::operator=(const ArrayQueue& other) {
        if (this == &other) {
            return *this;
        }
        capacity = other.capacity;
        size = other.size;
        frontIndex = other.frontIndex;
        rearIndex = other.rearIndex;
        data = std::make_unique<int[]>(static_cast<size_t>(capacity));
        std::copy(&other.data[0], &other.data[static_cast<size_t>(capacity)], &data[0]);
        return *this;
    }

    ArrayQueue& ArrayQueue::operator=(ArrayQueue&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        capacity = other.capacity;
        size = other.size;
        frontIndex = other.frontIndex;
        rearIndex = other.rearIndex;
        data = std::move(other.data);
        other.capacity = 0;
        other.size = 0;
        other.frontIndex = 0;
        other.rearIndex = -1;
        return *this;
    }

    bool ArrayQueue::operator==(const ArrayQueue& other) const {
        if (size != other.size || capacity != other.capacity || frontIndex != other.frontIndex || rearIndex != other.rearIndex) {
            return false;
        }
        for (int i = 0; i < size; ++i) {
            if (data[(static_cast<size_t>(frontIndex) + static_cast<size_t>(i)) % static_cast<size_t>(capacity)] != 
                other.data[(static_cast<size_t>(other.frontIndex) + static_cast<size_t>(i)) % static_cast<size_t>(other.capacity)]) {
                return false;
            }
        }
        return true;
    }

    bool ArrayQueue::operator!=(const ArrayQueue& other) const {
        return !(*this == other);
    }

    std::ostream& operator<<(std::ostream& os, const ArrayQueue& queue) {
        for (int i = 0; i < queue.size; ++i) {
            os << queue.data[(static_cast<size_t>(queue.frontIndex) + static_cast<size_t>(i)) % static_cast<size_t>(queue.capacity)] << " ";
        }
        return os;
    }

    void ArrayQueue::resize(int new_capacity) {
        std::unique_ptr<int[]> new_data = std::make_unique<int[]>(static_cast<size_t>(new_capacity));
        for (int i = 0; i < size; ++i) {
            new_data[static_cast<size_t>(i)] = data[(static_cast<size_t>(frontIndex) + static_cast<size_t>(i)) % static_cast<size_t>(capacity)];
        }
        data = std::move(new_data);
        capacity = new_capacity;
        frontIndex = 0;
        rearIndex = size - 1;
    }

    void ArrayQueue::enqueue(int value) {
        if (isFull()) {
            resize(capacity * 2);
        }
        rearIndex = (rearIndex + 1) % capacity;
        data[static_cast<size_t>(rearIndex)] = value;
        ++size;
    }

    int ArrayQueue::dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Dequeue Error: Queue is empty.");
        }
        int value = data[static_cast<size_t>(frontIndex)];
        frontIndex = (frontIndex + 1) % capacity;
        --size;
        return value;
    }

    int ArrayQueue::front() const {
        if (isEmpty()) {
            throw std::out_of_range("Front Error: Queue is empty.");
        }
        return data[static_cast<size_t>(frontIndex)];
    }

    bool ArrayQueue::isEmpty() const {
        return size == 0;
    }

    bool ArrayQueue::isFull() const {
        return size == capacity;
    }

    int ArrayQueue::getSize() const {
        return size;
    }

}
