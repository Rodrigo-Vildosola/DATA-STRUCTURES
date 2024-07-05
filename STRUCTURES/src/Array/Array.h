#pragma once

#include <functional>
#include <memory>
#include <stdexcept>
#include <algorithm>

namespace STRUCTS {

    class Array {
    public:
        Array();
        Array(int initial_capacity);
        ~Array();

        Array(const Array& other); 
        Array& operator=(const Array& other); 
        Array(Array&& other) noexcept; 
        Array& operator=(Array&& other) noexcept;

        void append(int value);
        void insert(int index, int value);
        int get(int index) const;
        void update(int index, int value);
        void remove(int index);
        void traverse(const std::function<void(int)>& func) const;
        bool search(int value) const;

        int getSize() const { return size; }
        int getCapacity() const { return capacity; }
        bool isEmpty() const;

        int& operator[](int index); 
        const int& operator[](int index) const; 

        bool operator==(const Array& other) const; 
        bool operator!=(const Array& other) const; 

    private:
        void resize(int new_capacity);
        void copyFrom(const Array& other);

        int size;
        int capacity;
        std::unique_ptr<int[]> data;
    };

}
