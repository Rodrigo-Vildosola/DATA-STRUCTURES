#pragma once

#include <memory>
#include <stdexcept>

namespace STRUCTS {

    class ArrayQueue {
    public:
        ArrayQueue(int capacity = 10);
        ~ArrayQueue();

        void enqueue(int value);
        int dequeue();
        int front() const;
        bool isEmpty() const;
        bool isFull() const;
        int getSize() const;

    private:
        void resize(int new_capacity);

        std::unique_ptr<int[]> data;
        int capacity;
        int size;
        int frontIndex;
        int rearIndex;
    };

}
