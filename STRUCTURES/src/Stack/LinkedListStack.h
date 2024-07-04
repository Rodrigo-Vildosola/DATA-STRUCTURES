#pragma once

#include <memory>
#include <stdexcept>

namespace STRUCTS {

    struct StackNode {
        int data;
        std::unique_ptr<StackNode> next;

        StackNode(int data) : data(data), next(nullptr) {}
    };

    class LinkedListStack {
    public:
        LinkedListStack();
        ~LinkedListStack();

        void push(int value);
        void pop();
        int top() const;
        bool isEmpty() const;
        int getSize() const;

    private:
        std::unique_ptr<StackNode> head;
        int size;
    };

}
