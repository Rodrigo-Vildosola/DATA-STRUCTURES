#pragma once

#include <functional>
#include <memory>

namespace STRUCTS {


    class Array {
    public:
        Array();
        Array(int capacity);
        ~Array();


        void append(int value);
        void insert(int index, int value);
        int get(int index) const;
        void update(int index, int value);
        void remove(int index);
        void traverse(const std::function<void(int)>& func) const;
        bool search(int value) const;


        int getSize() { return size; }
        int getCapacity() { return capacity; }

        bool isEmpty() const;
    private:

        void resize(int new_capacity);

        std::unique_ptr<int[]> data;
        int size;
        int capacity;
    };


}
