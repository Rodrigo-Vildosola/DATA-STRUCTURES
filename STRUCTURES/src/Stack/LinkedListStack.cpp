#include "Stack/LinkedListStack.h"

namespace STRUCTS {

    LinkedListStack::LinkedListStack() : head(nullptr), size(0) {}

    LinkedListStack::~LinkedListStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    LinkedListStack::LinkedListStack(const LinkedListStack& other) : LinkedListStack() {
        copyFrom(other);
    }

    LinkedListStack::LinkedListStack(LinkedListStack&& other) noexcept : LinkedListStack() {
        moveFrom(std::move(other));
    }

    LinkedListStack& LinkedListStack::operator=(const LinkedListStack& other) {
        if (this != &other) {
            while (!isEmpty()) {
                pop();
            }
            copyFrom(other);
        }
        return *this;
    }

    LinkedListStack& LinkedListStack::operator=(LinkedListStack&& other) noexcept {
        if (this != &other) {
            while (!isEmpty()) {
                pop();
            }
            moveFrom(std::move(other));
        }
        return *this;
    }

    bool LinkedListStack::operator==(const LinkedListStack& other) const {
        if (size != other.size) {
            return false;
        }
        StackNode* current1 = head.get();
        StackNode* current2 = other.head.get();
        while (current1 && current2) {
            if (current1->data != current2->data) {
                return false;
            }
            current1 = current1->next.get();
            current2 = current2->next.get();
        }
        return true;
    }

    bool LinkedListStack::operator!=(const LinkedListStack& other) const {
        return !(*this == other);
    }

    std::ostream& operator<<(std::ostream& os, const LinkedListStack& stack) {
        StackNode* current = stack.head.get();
        while (current) {
            os << current->data << " ";
            current = current->next.get();
        }
        return os;
    }

    void LinkedListStack::push(int value) {
        std::unique_ptr<StackNode> newNode = std::make_unique<StackNode>(value);
        newNode->next = std::move(head);
        head = std::move(newNode);
        ++size;
    }

    void LinkedListStack::pop() {
        if (isEmpty()) {
            throw std::out_of_range("Pop Error: Stack is empty.");
        }
        head = std::move(head->next);
        --size;
    }

    int LinkedListStack::top() const {
        if (isEmpty()) {
            throw std::out_of_range("Top Error: Stack is empty.");
        }
        return head->data;
    }

    bool LinkedListStack::isEmpty() const {
        return size == 0;
    }

    int LinkedListStack::getSize() const {
        return size;
    }

    void LinkedListStack::copyFrom(const LinkedListStack& other) {
        if (other.head) {
            head = std::make_unique<StackNode>(other.head->data);
            StackNode* current = head.get();
            StackNode* otherCurrent = other.head->next.get();
            while (otherCurrent) {
                current->next = std::make_unique<StackNode>(otherCurrent->data);
                current = current->next.get();
                otherCurrent = otherCurrent->next.get();
            }
        }
        size = other.size;
    }

    void LinkedListStack::moveFrom(LinkedListStack&& other) noexcept {
        head = std::move(other.head);
        size = other.size;
        other.size = 0;
    }

}
