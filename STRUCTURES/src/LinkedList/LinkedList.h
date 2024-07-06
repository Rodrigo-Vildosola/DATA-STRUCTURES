#pragma once

#include <functional>
#include <memory>
#include <stdexcept>
#include <algorithm>
#include <type_traits>

namespace STRUCTS {

    template <typename T>
    struct Node {
        T data;
        std::unique_ptr<Node> next;

        Node(T initial_data) : data(initial_data), next(nullptr) {}
    };

    template <typename T>
    class LinkedList {
    public:
        LinkedList();
        ~LinkedList();

        LinkedList(const LinkedList& other);
        LinkedList& operator=(const LinkedList& other);
        LinkedList(LinkedList&& other) noexcept;
        LinkedList& operator=(LinkedList&& other) noexcept;

        void insertAtBeginning(const T& value); // O(1)
        void insertAtEnd(const T& value); // O(n)
        void insertAtPosition(int position, const T& value); // O(n)

        void deleteFromBeginning(); // O(1)
        void deleteFromEnd(); // O(n)
        void deleteFromPosition(int position); // O(n)

        void traverse(const std::function<void(const T&)>& func) const; // O(n)
        void map(const std::function<T(T)>& func); // O(n)
        bool search(const T& value) const; // O(n)
        void update(int position, const T& value); // O(n)

        int getSize() const { return size; } // O(1)
        bool isEmpty() const { return head == nullptr; } // O(1)

    private:
        std::unique_ptr<Node<T>> head;
        int size;

        void clear(); // O(n)
        void copyFrom(const LinkedList& other);

        static_assert(std::is_default_constructible<T>::value, "LinkedList elements must be default-constructible");
        static_assert(std::is_copy_constructible<T>::value, "LinkedList elements must be copy-constructible");
        static_assert(std::is_copy_assignable<T>::value, "LinkedList elements must be copy-assignable");
        static_assert(std::is_move_constructible<T>::value, "LinkedList elements must be move-constructible");
        static_assert(std::is_move_assignable<T>::value, "LinkedList elements must be move-assignable");
    };

}

#include "LinkedList/LinkedList.tpp"
