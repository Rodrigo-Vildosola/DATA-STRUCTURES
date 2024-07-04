#include "Queue/ArrayQueue.h"

namespace STRUCTS {

    ArrayQueue::ArrayQueue(int capacity)
        : capacity(capacity), size(0), frontIndex(0), rearIndex(-1) {
        data = std::make_unique<int[]>(capacity);
    }

    ArrayQueue::~ArrayQueue() {
        // unique_ptr automatically handles memory deallocation
    }

    void ArrayQueue::resize(int new_capacity) {
        std::unique_ptr<int[]> new_data = std::make_unique<int[]>(new_capacity);
        for (int i = 0; i < size; ++i) {
            new_data[i] = data[(frontIndex + i) % capacity];
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
        data[rearIndex] = value;
        ++size;
    }

    int ArrayQueue::dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Dequeue Error: Queue is empty.");
        }
        int value = data[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        --size;
        return value;
    }

    int ArrayQueue::front() const {
        if (isEmpty()) {
            throw std::out_of_range("Front Error: Queue is empty.");
        }
        return data[frontIndex];
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
