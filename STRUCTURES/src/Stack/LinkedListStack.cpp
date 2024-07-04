#include "Stack/LinkedListStack.h"

namespace STRUCTS {

    LinkedListStack::LinkedListStack() : head(nullptr), size(0) {}

    LinkedListStack::~LinkedListStack() {
        while (!isEmpty()) {
            pop();
        }
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
        return head == nullptr;
    }

    int LinkedListStack::getSize() const {
        return size;
    }

}
