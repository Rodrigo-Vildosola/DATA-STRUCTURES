#pragma once

#include <memory>
#include <stdexcept>
#include <iostream>

namespace STRUCTS {

    template <typename T>
    class ArrayQueue {
    public:
        ArrayQueue(int initial_capacity = 10);
        ~ArrayQueue();

        ArrayQueue(const ArrayQueue& other);
        ArrayQueue(ArrayQueue&& other) noexcept;

        ArrayQueue& operator=(const ArrayQueue& other);
        ArrayQueue& operator=(ArrayQueue&& other) noexcept;

        bool operator==(const ArrayQueue& other) const;
        bool operator!=(const ArrayQueue& other) const;

        void enqueue(const T& value);
        void dequeue();
        T front() const;
        bool isEmpty() const;
        int getSize() const;
        void clear();

        template <typename U>
        friend std::ostream& operator<<(std::ostream& os, const ArrayQueue<U>& queue);

    private:
        void resize(int new_capacity);

        int size;
        int capacity;
        int frontIndex;
        int rearIndex;
        std::unique_ptr<T[]> data;
    };

} // namespace STRUCTS

#include "Queue/ArrayQueue.tpp"
