#pragma once

#include <memory>
#include <stdexcept>

namespace STRUCTS {

    class ArrayStack {
    public:
        ArrayStack();
        ~ArrayStack();

        void push(int value);
        void pop();
        int top() const;
        bool isEmpty() const;
        int getSize() const;

    private:
        void resize(int new_capacity);

        std::unique_ptr<int[]> data;
        int size;
        int capacity;
    };

}
