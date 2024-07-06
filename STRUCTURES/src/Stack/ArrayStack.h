#pragma once

#include <memory>
#include <stdexcept>
#include <iostream>

namespace STRUCTS {

    template <typename T>
    class ArrayStack {
    public:
        ArrayStack(int initial_capacity = 10);
        ~ArrayStack();

        ArrayStack(const ArrayStack& other);
        ArrayStack(ArrayStack&& other) noexcept;

        ArrayStack& operator=(const ArrayStack& other);
        ArrayStack& operator=(ArrayStack&& other) noexcept;

        bool operator==(const ArrayStack& other) const;
        bool operator!=(const ArrayStack& other) const;

        void push(const T& value);
        void pop();
        T top() const;
        bool isEmpty() const;
        int getSize() const;
        void clear();

        template <typename U>
        friend std::ostream& operator<<(std::ostream& os, const ArrayStack<U>& stack);

    private:
        void resize(int new_capacity);

        int size;
        int capacity;
        std::unique_ptr<T[]> data;
    };

}


#include "Stack/ArrayStack.tpp"
