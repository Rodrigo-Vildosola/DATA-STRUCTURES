#include "Queue/LinkedListQueue.h"

namespace STRUCTS {

    LinkedListQueue::LinkedListQueue() : head(nullptr), tail(nullptr), size(0) {}

    LinkedListQueue::~LinkedListQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    LinkedListQueue::LinkedListQueue(const LinkedListQueue& other) : LinkedListQueue() {
        copyFrom(other);
    }

    LinkedListQueue::LinkedListQueue(LinkedListQueue&& other) noexcept : LinkedListQueue() {
        moveFrom(std::move(other));
    }

    LinkedListQueue& LinkedListQueue::operator=(const LinkedListQueue& other) {
        if (this != &other) {
            while (!isEmpty()) {
                dequeue();
            }
            copyFrom(other);
        }
        return *this;
    }

    LinkedListQueue& LinkedListQueue::operator=(LinkedListQueue&& other) noexcept {
        if (this != &other) {
            while (!isEmpty()) {
                dequeue();
            }
            moveFrom(std::move(other));
        }
        return *this;
    }

    bool LinkedListQueue::operator==(const LinkedListQueue& other) const {
        if (size != other.size) {
            return false;
        }
        QueueNode* current1 = head.get();
        QueueNode* current2 = other.head.get();
        while (current1 && current2) {
            if (current1->data != current2->data) {
                return false;
            }
            current1 = current1->next.get();
            current2 = current2->next.get();
        }
        return true;
    }

    bool LinkedListQueue::operator!=(const LinkedListQueue& other) const {
        return !(*this == other);
    }

    std::ostream& operator<<(std::ostream& os, const LinkedListQueue& queue) {
        QueueNode* current = queue.head.get();
        while (current) {
            os << current->data << " ";
            current = current->next.get();
        }
        return os;
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

    void LinkedListQueue::copyFrom(const LinkedListQueue& other) {
        QueueNode* current = other.head.get();
        while (current) {
            enqueue(current->data);
            current = current->next.get();
        }
    }

    void LinkedListQueue::moveFrom(LinkedListQueue&& other) noexcept {
        head = std::move(other.head);
        tail = other.tail;
        size = other.size;
        other.tail = nullptr;
        other.size = 0;
    }

}
