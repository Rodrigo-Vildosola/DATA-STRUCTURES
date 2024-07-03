#pragma once

#include <memory>
#include <stdexcept>
#include <functional>

namespace STRUCTS {

    struct Node {
        int data;
        std::unique_ptr<Node> next;

        Node(int data) : data(data), next(nullptr) {}
    };

    class LinkedList {
    public:
        LinkedList();
        ~LinkedList();

        void insertAtBeginning(int value); // O(1)
        void insertAtEnd(int value); // O(n)
        void insertAtPosition(int position, int value); // O(n)

        void deleteFromBeginning(); // O(1)
        void deleteFromEnd(); // O(n)
        void deleteFromPosition(int position); // O(n)

        void traverse(const std::function<void(int)>& func) const; // O(n)
        bool search(int value) const; // O(n)
        void update(int position, int value); // O(n)

        int getSize() const { return size; } // O(1)
        bool isEmpty() const { return head == nullptr; } // O(1)

    private:
        std::unique_ptr<Node> head;
        int size;
        
        void clear(); // O(n)
    };

}
