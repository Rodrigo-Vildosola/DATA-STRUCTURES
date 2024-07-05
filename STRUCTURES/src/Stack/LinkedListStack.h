#pragma once

#include <memory>
#include <stdexcept>
#include <iostream>

namespace STRUCTS {

    struct StackNode {
        int data;
        std::unique_ptr<StackNode> next;

        StackNode(int initial_data) : data(initial_data), next(nullptr) {}
    };

    class LinkedListStack {
    public:
        LinkedListStack();
        ~LinkedListStack();

        LinkedListStack(const LinkedListStack& other);
        LinkedListStack(LinkedListStack&& other) noexcept;

        LinkedListStack& operator=(const LinkedListStack& other);
        LinkedListStack& operator=(LinkedListStack&& other) noexcept;

        bool operator==(const LinkedListStack& other) const;
        bool operator!=(const LinkedListStack& other) const;

        friend std::ostream& operator<<(std::ostream& os, const LinkedListStack& stack);

        void push(int value);
        void pop();
        int top() const;
        bool isEmpty() const;
        int getSize() const;

    private:
        std::unique_ptr<StackNode> head;
        int size;

        void copyFrom(const LinkedListStack& other);
        void moveFrom(LinkedListStack&& other) noexcept;
    };

}
