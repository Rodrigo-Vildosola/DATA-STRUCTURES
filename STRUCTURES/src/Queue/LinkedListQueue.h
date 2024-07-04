#pragma once

#include <memory>
#include <stdexcept>

namespace STRUCTS {

    struct QueueNode {
        int data;
        std::unique_ptr<QueueNode> next;

        QueueNode(int data) : data(data), next(nullptr) {}
    };

    class LinkedListQueue {
    public:
        LinkedListQueue();
        ~LinkedListQueue();

        void enqueue(int value);
        int dequeue();
        int front() const;
        bool isEmpty() const;
        int getSize() const;

    private:
        std::unique_ptr<QueueNode> head;
        QueueNode* tail;
        int size;
    };

}
