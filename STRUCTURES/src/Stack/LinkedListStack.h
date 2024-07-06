#pragma once

#include <memory>
#include <iostream>
#include <stdexcept>

namespace STRUCTS {

    template <typename T>
    struct StackNode {
        T data;
        std::unique_ptr<StackNode<T>> next;

        StackNode(const T& initial_data) : data(initial_data), next(nullptr) {}
    };

    template <typename T>
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

        void push(const T& value);
        void pop();
        T top() const;
        bool isEmpty() const;
        int getSize() const;
        void clear();

        template <typename U>
        friend std::ostream& operator<<(std::ostream& os, const LinkedListStack<U>& stack);

    private:
        std::unique_ptr<StackNode<T>> head;
        int size;

        void copyFrom(const LinkedListStack& other);
        void moveFrom(LinkedListStack&& other) noexcept;
    };

}

#include "Stack/LinkedListStack.tpp"

