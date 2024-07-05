#pragma once

#include <functional>
#include <memory>
#include <stdexcept>
#include <algorithm>
#include <type_traits>


namespace STRUCTS {

    template <typename T>
    class Array {
    public:
        Array();
        Array(int initial_capacity);
        ~Array();

        Array(const Array& other); 
        Array& operator=(const Array& other); 
        Array(Array&& other) noexcept; 
        Array& operator=(Array&& other) noexcept;

        void append(const T& value);
        void insert(int index, const T& value);
        T get(int index) const;
        void update(int index, const T& value);
        void remove(int index);
        void traverse(const std::function<void(const T&)>& func) const;
        void map(const std::function<T(T)>& func);
        bool search(const T& value) const;

        int getSize() const { return size; }
        int getCapacity() const { return capacity; }
        bool isEmpty() const;

        T& operator[](int index); 
        const T& operator[](int index) const; 

        bool operator==(const Array& other) const; 
        bool operator!=(const Array& other) const; 

    private:
        void resize(int new_capacity);
        void copyFrom(const Array& other);

        int size;
        int capacity;
        std::unique_ptr<T[]> data;

        static_assert(std::is_default_constructible<T>::value, "Array elements must be default-constructible");
        static_assert(std::is_copy_constructible<T>::value, "Array elements must be copy-constructible");
        static_assert(std::is_copy_assignable<T>::value, "Array elements must be copy-assignable");
        static_assert(std::is_move_constructible<T>::value, "Array elements must be move-constructible");
        static_assert(std::is_move_assignable<T>::value, "Array elements must be move-assignable");
    };

}

#include "Array/Array.tpp"
