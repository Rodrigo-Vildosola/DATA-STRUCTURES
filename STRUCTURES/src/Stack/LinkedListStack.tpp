#include "Stack/LinkedListStack.h"

namespace STRUCTS {

    template <typename T>
    LinkedListStack<T>::LinkedListStack() : head(nullptr), size(0) {}

    template <typename T>
    LinkedListStack<T>::~LinkedListStack() {
        clear();
    }

    template <typename T>
    LinkedListStack<T>::LinkedListStack(const LinkedListStack& other) : LinkedListStack() {
        copyFrom(other);
    }

    template <typename T>
    LinkedListStack<T>::LinkedListStack(LinkedListStack&& other) noexcept : LinkedListStack() {
        moveFrom(std::move(other));
    }

    template <typename T>
    LinkedListStack<T>& LinkedListStack<T>::operator=(const LinkedListStack& other) {
        if (this != &other) {
            clear();
            copyFrom(other);
        }
        return *this;
    }

    template <typename T>
    LinkedListStack<T>& LinkedListStack<T>::operator=(LinkedListStack&& other) noexcept {
        if (this != &other) {
            clear();
            moveFrom(std::move(other));
        }
        return *this;
    }

    template <typename T>
    bool LinkedListStack<T>::operator==(const LinkedListStack& other) const {
        if (size != other.size) {
            return false;
        }
        StackNode<T>* current1 = head.get();
        StackNode<T>* current2 = other.head.get();
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
    bool LinkedListStack<T>::operator!=(const LinkedListStack& other) const {
        return !(*this == other);
    }

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const LinkedListStack<T>& stack) {
        StackNode<T>* current = stack.head.get();
        while (current) {
            os << current->data << " ";
            current = current->next.get();
        }
        return os;
    }

    template <typename T>
    void LinkedListStack<T>::push(const T& value) {
        std::unique_ptr<StackNode<T>> newNode = std::make_unique<StackNode<T>>(value);
        newNode->next = std::move(head);
        head = std::move(newNode);
        ++size;
    }

    template <typename T>
    void LinkedListStack<T>::pop() {
        if (isEmpty()) {
            throw std::out_of_range("Pop Error: Stack is empty.");
        }
        head = std::move(head->next);
        --size;
    }

    template <typename T>
    T LinkedListStack<T>::top() const {
        if (isEmpty()) {
            throw std::out_of_range("Top Error: Stack is empty.");
        }
        return head->data;
    }

    template <typename T>
    bool LinkedListStack<T>::isEmpty() const {
        return size == 0;
    }

    template <typename T>
    int LinkedListStack<T>::getSize() const {
        return size;
    }

    template <typename T>
    void LinkedListStack<T>::clear() {
        while (!isEmpty()) {
            pop();
        }
    }

    template <typename T>
    void LinkedListStack<T>::copyFrom(const LinkedListStack& other) {
        if (other.head) {
            head = std::make_unique<StackNode<T>>(other.head->data);
            StackNode<T>* current = head.get();
            StackNode<T>* otherCurrent = other.head->next.get();
            while (otherCurrent) {
                current->next = std::make_unique<StackNode<T>>(otherCurrent->data);
                current = current->next.get();
                otherCurrent = otherCurrent->next.get();
            }
        }
        size = other.size;
    }

    template <typename T>
    void LinkedListStack<T>::moveFrom(LinkedListStack&& other) noexcept {
        head = std::move(other.head);
        size = other.size;
        other.size = 0;
    }

} // namespace STRUCTS
