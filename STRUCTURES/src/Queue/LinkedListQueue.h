#pragma once

#include <memory>
#include <stdexcept>
#include <iostream>

namespace STRUCTS {

    template <typename T>
    struct QueueNode {
        T data;
        std::unique_ptr<QueueNode<T>> next;

        QueueNode(const T& initial_data) : data(initial_data), next(nullptr) {}
    };

    template <typename T>
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

        void enqueue(const T& value);
        void dequeue();
        T front() const;
        bool isEmpty() const;
        int getSize() const;
        void clear();

        template <typename U>
        friend std::ostream& operator<<(std::ostream& os, const LinkedListQueue<U>& queue);

    private:
        std::unique_ptr<QueueNode<T>> head;
        QueueNode<T>* tail;
        int size;

        void copyFrom(const LinkedListQueue& other);
        void moveFrom(LinkedListQueue&& other) noexcept;
    };

}

#include "Queue/LinkedListQueue.tpp"
