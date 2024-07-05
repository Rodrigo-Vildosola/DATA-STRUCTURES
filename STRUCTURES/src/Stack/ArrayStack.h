#include <iostream>
#include <memory>
#include <stdexcept>

namespace STRUCTS {

    class ArrayStack {
    public:
        ArrayStack();
        ~ArrayStack();

        ArrayStack(const ArrayStack& other);
        ArrayStack(ArrayStack&& other) noexcept;

        ArrayStack& operator=(const ArrayStack& other);
        ArrayStack& operator=(ArrayStack&& other) noexcept;

        bool operator==(const ArrayStack& other) const;
        bool operator!=(const ArrayStack& other) const;

        friend std::ostream& operator<<(std::ostream& os, const ArrayStack& stack);

        void push(int value);
        void pop();
        int top() const;
        bool isEmpty() const;
        int getSize() const;

    private:
        void resize(int new_capacity);

        int size;
        int capacity;
        std::unique_ptr<int[]> data;
    };

}
