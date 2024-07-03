
#include "Array/Array.h"
#include <memory>
#include <stdexcept>
#include <iostream>


namespace STRUCTS {

    Array::Array() : size(0), capacity(1) {
        data = std::make_unique<int[]> (capacity);
    }

    Array::Array(int capacity) : size(0), capacity(capacity) {
        data = std::make_unique<int[]> (capacity);
    }

    Array::~Array() {
        // unique_ptr automatically handles memory deallocation
    }

    void Array::resize(int new_capacity) {
        std::cout << "Resizing array from: " << capacity << " to: " << new_capacity << std::endl;
        std::unique_ptr<int[]> new_data = std::make_unique<int[]>(new_capacity);
        std::copy(&data[0], &data[size], &new_data[0]);
        data = std::move(new_data);
        capacity = new_capacity;
    }

    void Array::append(int value) {
        if (size >= capacity) {
            resize(capacity * 2);
        }
        data[size++] = value;
    }

    void Array::insert(int index, int value) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Insert Error: Index out of bounds.");
        }
        if (size >= capacity) {
            resize(capacity * 2);
        }
        for (int i = size; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++size;
    }

    int Array::get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Get Error: Index out of bounds.");
        }
        return data[index];
    }

    void Array::update(int index, int value) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Update Error: Index out of bounds.");
        }
        data[index] = value;
    }

    void Array::remove(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Remove Error: Index out of bounds.");
        }
        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
        if (size <= capacity / 4 && capacity > 10) {
            resize(capacity / 2);
        }
    }

    void Array::traverse(const std::function<void(int)>& func) const {
        for (int i = 0; i < size; ++i) {
            func(data[i]);
        }
    }

    bool Array::search(int value) const {
        for (int i = 0; i < size; ++i) {
            if (data[i] == value) {
                return true;
            }
        }
        return false;
    }

    bool Array::isEmpty() const {
        return size == 0;
    }

}
