#pragma once

#include <memory>
#include <vector>
#include <functional>
#include <stdexcept>

namespace STRUCTS {

    struct HashNode {
        int key;
        int value;
        std::unique_ptr<HashNode> next;

        HashNode(int k, int v) : key(k), value(v), next(nullptr) {}
    };

    class HashTable {
    public:
        HashTable(int initial_capacity = 10);
        ~HashTable();

        void insert(int key, int value);
        void remove(int key);
        int search(int key) const;
        bool contains(int key) const;

        // Operator overloads
        int& operator[](int key);
        bool operator==(const HashTable& other) const;
        bool operator!=(const HashTable& other) const;

        int getSize() { return size; }
        int getCapacity() { return capacity; }

    private:
        int hashFunction(int key) const;
        void resize(int new_capacity);

        int capacity;
        int size;
        std::unique_ptr<std::unique_ptr<HashNode>[]> table;
    };

}
