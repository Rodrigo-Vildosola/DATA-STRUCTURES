#include "Queue/LinkedListQueue.h"

namespace STRUCTS {

    template <typename T>
    LinkedListQueue<T>::LinkedListQueue() : head(nullptr), tail(nullptr), size(0) {}

    template <typename T>
    LinkedListQueue<T>::~LinkedListQueue() {
        clear();
    }

    template <typename T>
    LinkedListQueue<T>::LinkedListQueue(const LinkedListQueue& other) : LinkedListQueue() {
        copyFrom(other);
    }

    template <typename T>
    LinkedListQueue<T>::LinkedListQueue(LinkedListQueue&& other) noexcept : LinkedListQueue() {
        moveFrom(std::move(other));
    }

    template <typename T>
    LinkedListQueue<T>& LinkedListQueue<T>::operator=(const LinkedListQueue& other) {
        if (this != &other) {
            clear();
            copyFrom(other);
        }
        return *this;
    }

    template <typename T>
    LinkedListQueue<T>& LinkedListQueue<T>::operator=(LinkedListQueue&& other) noexcept {
        if (this != &other) {
            clear();
            moveFrom(std::move(other));
        }
        return *this;
    }

    template <typename T>
    bool LinkedListQueue<T>::operator==(const LinkedListQueue& other) const {
        if (size != other.size) {
            return false;
        }
        QueueNode<T>* current1 = head.get();
        QueueNode<T>* current2 = other.head.get();
        while (current1 && current2) {
            if (current1->data != current2->data) {
                return false;
            }
            current1 = current1->next.get();
            current2 = current2->next.get();
        }
        return true;
    }

    template <typename T>
    bool LinkedListQueue<T>::operator!=(const LinkedListQueue& other) const {
        return !(*this == other);
    }

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const LinkedListQueue<T>& queue) {
        QueueNode<T>* current = queue.head.get();
        while (current) {
            os << current->data << " ";
            current = current->next.get();
        }
        return os;
    }

    template <typename T>
    void LinkedListQueue<T>::enqueue(const T& value) {
        std::unique_ptr<QueueNode<T>> newNode = std::make_unique<QueueNode<T>>(value);
        if (isEmpty()) {
            head = std::move(newNode);
            tail = head.get();
        } else {
            tail->next = std::move(newNode);
            tail = tail->next.get();
        }
        ++size;
    }

    template <typename T>
    void LinkedListQueue<T>::dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Dequeue Error: Queue is empty.");
        }
        head = std::move(head->next);
        if (!head) {
            tail = nullptr;
        }
        --size;
    }

    template <typename T>
    T LinkedListQueue<T>::front() const {
        if (isEmpty()) {
            throw std::out_of_range("Front Error: Queue is empty.");
        }
        return head->data;
    }

    template <typename T>
    bool LinkedListQueue<T>::isEmpty() const {
        return size == 0;
    }

    template <typename T>
    int LinkedListQueue<T>::getSize() const {
        return size;
    }

    template <typename T>
    void LinkedListQueue<T>::clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    template <typename T>
    void LinkedListQueue<T>::copyFrom(const LinkedListQueue& other) {
        QueueNode<T>* current = other.head.get();
        while (current) {
            enqueue(current->data);
            current = current->next.get();
        }
    }

    template <typename T>
    void LinkedListQueue<T>::moveFrom(LinkedListQueue&& other) noexcept {
        head = std::move(other.head);
        tail = other.tail;
        size = other.size;
        other.tail = nullptr;
        other.size = 0;
    }

} // namespace STRUCTS
