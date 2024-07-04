#include "Queue/LinkedListQueue.h"

namespace STRUCTS {

    LinkedListQueue::LinkedListQueue() : head(nullptr), tail(nullptr), size(0) {}

    LinkedListQueue::~LinkedListQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void LinkedListQueue::enqueue(int value) {
        std::unique_ptr<QueueNode> newNode = std::make_unique<QueueNode>(value);
        if (isEmpty()) {
            head = std::move(newNode);
            tail = head.get();
        } else {
            tail->next = std::move(newNode);
            tail = tail->next.get();
        }
        ++size;
    }

    int LinkedListQueue::dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Dequeue Error: Queue is empty.");
        }
        int value = head->data;
        head = std::move(head->next);
        if (!head) {
            tail = nullptr;
        }
        --size;
        return value;
    }

    int LinkedListQueue::front() const {
        if (isEmpty()) {
            throw std::out_of_range("Front Error: Queue is empty.");
        }
        return head->data;
    }

    bool LinkedListQueue::isEmpty() const {
        return size == 0;
    }

    int LinkedListQueue::getSize() const {
        return size;
    }

}
