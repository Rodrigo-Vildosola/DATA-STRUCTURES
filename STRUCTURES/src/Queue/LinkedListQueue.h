#pragma once

#include <memory>
#include <stdexcept>
#include <iostream>

namespace STRUCTS {

    struct QueueNode {
        int data;
        std::unique_ptr<QueueNode> next;

        QueueNode(int initial_data) : data(initial_data), next(nullptr) {}
    };

    class LinkedListQueue {
    public:
        LinkedListQueue();
        ~LinkedListQueue();

        LinkedListQueue(const LinkedListQueue& other);
        LinkedListQueue(LinkedListQueue&& other) noexcept;

        LinkedListQueue& operator=(const LinkedListQueue& other);
        LinkedListQueue& operator=(LinkedListQueue&& other) noexcept;

        bool operator==(const LinkedListQueue& other) const;
        bool operator!=(const LinkedListQueue& other) const;

        friend std::ostream& operator<<(std::ostream& os, const LinkedListQueue& queue);

        void enqueue(int value);
        int dequeue();
        int front() const;
        bool isEmpty() const;
        int getSize() const;

    private:
        std::unique_ptr<QueueNode> head;
        QueueNode* tail;
        int size;

        void copyFrom(const LinkedListQueue& other);
        void moveFrom(LinkedListQueue&& other) noexcept;
    };

}
