#include "Array/Array.h"

namespace STRUCTS {

    Array::Array() : size(0), capacity(1) {
        data = std::make_unique<int[]>(static_cast<size_t>(capacity));
    }

    Array::Array(int initial_capacity) : size(0), capacity(initial_capacity) {
        data = std::make_unique<int[]>(static_cast<size_t>(capacity));
    }

    Array::~Array() {
        // unique_ptr automatically handles memory deallocation
    }

    Array::Array(const Array& other) : size(other.size), capacity(other.capacity) {
        data = std::make_unique<int[]>(static_cast<size_t>(capacity));
        std::copy(&other.data[0], &other.data[static_cast<size_t>(size)], &data[0]);
    }

    Array::Array(Array&& other) noexcept : size(other.size), capacity(other.capacity), data(std::move(other.data)) {
        other.size = 0;
        other.capacity = 0;
    }

    Array& Array::operator=(const Array& other) {
        if (this == &other) {
            return *this;
        }
        size = other.size;
        capacity = other.capacity;
        data = std::make_unique<int[]>(static_cast<size_t>(capacity));
        std::copy(&other.data[0], &other.data[static_cast<size_t>(size)], &data[0]);
        return *this;
    }

    Array& Array::operator=(Array&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        size = other.size;
        capacity = other.capacity;
        data = std::move(other.data);
        other.size = 0;
        other.capacity = 0;
        return *this;
    }

    int& Array::operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[static_cast<size_t>(index)];
    }

    const int& Array::operator[](int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[static_cast<size_t>(index)];
    }

    bool Array::operator==(const Array& other) const {
        if (size != other.size) {
            return false;
        }
        for (int i = 0; i < size; ++i) {
            if (data[static_cast<size_t>(i)] != other.data[static_cast<size_t>(i)]) {
                return false;
            }
        }
        return true;
    }

    bool Array::operator!=(const Array& other) const {
        return !(*this == other);
    }

    void Array::resize(int new_capacity) {
        std::unique_ptr<int[]> new_data = std::make_unique<int[]>(static_cast<size_t>(new_capacity));
        std::copy(&data[0], &data[static_cast<size_t>(size)], &new_data[0]);
        data = std::move(new_data);
        capacity = new_capacity;
    }

    void Array::append(int value) {
        if (size >= capacity) {
            resize(capacity * 2);
        }
        data[static_cast<size_t>(size++)] = value;
    }

    void Array::insert(int index, int value) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Insert Error: Index out of bounds.");
        }
        if (size >= capacity) {
            resize(capacity * 2);
        }
        for (int i = size; i > index; --i) {
            data[static_cast<size_t>(i)] = data[static_cast<size_t>(i - 1)];
        }
        data[static_cast<size_t>(index)] = value;
        ++size;
    }

    int Array::get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Get Error: Index out of bounds.");
        }
        return data[static_cast<size_t>(index)];
    }

    void Array::update(int index, int value) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Update Error: Index out of bounds.");
        }
        data[static_cast<size_t>(index)] = value;
    }

    void Array::remove(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Remove Error: Index out of bounds.");
        }
        for (int i = index; i < size - 1; ++i) {
            data[static_cast<size_t>(i)] = data[static_cast<size_t>(i + 1)];
        }
        --size;
        if (size <= capacity / 4 && capacity > 10) {
            resize(capacity / 2);
        }
    }

    void Array::traverse(const std::function<void(int)>& func) const {
        for (int i = 0; i < size; ++i) {
            func(data[static_cast<size_t>(i)]);
        }
    }

    bool Array::search(int value) const {
        for (int i = 0; i < size; ++i) {
            if (data[static_cast<size_t>(i)] == value) {
                return true;
            }
        }
        return false;
    }

    bool Array::isEmpty() const {
        return size == 0;
    }

}
