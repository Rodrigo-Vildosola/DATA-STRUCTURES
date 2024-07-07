#include "Array/Array.h"

namespace STRUCTS {

    template <typename T>
    Array<T>::Array() : size(0), capacity(1) {
        data = std::make_unique<T[]>(static_cast<size_t>(capacity));
    }

    template <typename T>
    Array<T>::Array(int initial_capacity) : size(0), capacity(initial_capacity) {
        data = std::make_unique<T[]>(static_cast<size_t>(capacity));
    }

    template <typename T>
    Array<T>::~Array() {
        // unique_ptr automatically handles memory deallocation
    }

    template <typename T>
    Array<T>::Array(const Array& other) : size(other.size), capacity(other.capacity) {
        data = std::make_unique<T[]>(static_cast<size_t>(capacity));
        std::copy(&other.data[0], &other.data[static_cast<size_t>(size)], &data[0]);
    }

    template <typename T>
    Array<T>::Array(Array&& other) noexcept : size(other.size), capacity(other.capacity), data(std::move(other.data)) {
        other.size = 0;
        other.capacity = 0;
    }

    template <typename T>
    Array<T>& Array<T>::operator=(const Array& other) {
        if (this == &other) {
            return *this;
        }
        size = other.size;
        capacity = other.capacity;
        data = std::make_unique<T[]>(static_cast<size_t>(capacity));
        std::copy(&other.data[0], &other.data[static_cast<size_t>(size)], &data[0]);
        return *this;
    }

    template <typename T>
    Array<T>& Array<T>::operator=(Array&& other) noexcept {
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

    template <typename T>
    T& Array<T>::operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[static_cast<size_t>(index)];
    }

    template <typename T>
    const T& Array<T>::operator[](int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[static_cast<size_t>(index)];
    }

    template <typename T>
    bool Array<T>::operator==(const Array& other) const {
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

    template <typename T>
    bool Array<T>::operator!=(const Array& other) const {
        return !(*this == other);
    }

    template <typename T>
    void Array<T>::resize(int new_capacity) {
        std::unique_ptr<T[]> new_data = std::make_unique<T[]>(static_cast<size_t>(new_capacity));
        std::move(&data[0], &data[static_cast<size_t>(size)], &new_data[0]); // Use std::move for better performance
        data = std::move(new_data);
        capacity = new_capacity;
    }

    template <typename T>
    void Array<T>::append(const T& value) {
        if (size >= capacity) {
            resize(capacity * 2);
        }
        data[static_cast<size_t>(size++)] = value;
    }

    template <typename T>
    void Array<T>::insert(int index, const T& value) {
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

    template <typename T>
    T Array<T>::get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Get Error: Index out of bounds.");
        }
        return data[static_cast<size_t>(index)];
    }

    template <typename T>
    void Array<T>::update(int index, const T& value) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Update Error: Index out of bounds.");
        }
        data[static_cast<size_t>(index)] = value;
    }

    template <typename T>
    void Array<T>::remove(int index) {
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

    template <typename T>
    void Array<T>::traverse(const std::function<void(const T&)>& func) const {
        for (int i = 0; i < size; ++i) {
            func(data[static_cast<size_t>(i)]);
        }
    }

    template <typename T>
    void Array<T>::map(const std::function<T(T)>& func) {
        for (int i = 0; i < size; ++i) {
            data[static_cast<size_t>(i)] = func(data[static_cast<size_t>(i)]);
        }
    }

    template <typename T>
    bool Array<T>::search(const T& value) const {
        return std::find(&data[0], &data[static_cast<size_t>(size)], value) != &data[static_cast<size_t>(size)];
    }

    template <typename T>
    bool Array<T>::isEmpty() const {
        return size == 0;
    }

} // namespace STRUCTS
