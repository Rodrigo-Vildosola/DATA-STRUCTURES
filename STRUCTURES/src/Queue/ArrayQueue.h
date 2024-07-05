#include <iostream>
#include <memory>
#include <stdexcept>

namespace STRUCTS {

    class ArrayQueue {
    public:
        ArrayQueue(int initial_capacity = 10);
        ~ArrayQueue();

        ArrayQueue(const ArrayQueue& other);
        ArrayQueue(ArrayQueue&& other) noexcept;

        ArrayQueue& operator=(const ArrayQueue& other);
        ArrayQueue& operator=(ArrayQueue&& other) noexcept;

        bool operator==(const ArrayQueue& other) const;
        bool operator!=(const ArrayQueue& other) const;

        // Stream insertion operator
        friend std::ostream& operator<<(std::ostream& os, const ArrayQueue& queue);

        void enqueue(int value);
        int dequeue();
        int front() const;
        bool isEmpty() const;
        bool isFull() const;
        int getSize() const;

    private:
        void resize(int new_capacity);

        int size;
        int capacity;
        int frontIndex;
        int rearIndex;
        std::unique_ptr<int[]> data;
    };

    // Implementations...
}
