#pragma once

#include <memory>
#include <vector>
#include <functional>
#include <stdexcept>

namespace STRUCTS {

    template <typename KeyType, typename ValueType>
    struct HashNode {
        KeyType key;
        ValueType value;
        std::unique_ptr<HashNode> next;

        HashNode(KeyType k, ValueType v) : key(k), value(v), next(nullptr) {}
    };

    template <typename KeyType, typename ValueType, typename Hash = std::hash<KeyType>>
    class HashTable {
    public:
        HashTable(size_t initial_capacity = 10);
        ~HashTable();

        void insert(const KeyType& key, const ValueType& value);
        void remove(const KeyType& key);
        ValueType search(const KeyType& key) const;
        bool contains(const KeyType& key) const;

        // Operator overloads
        ValueType& operator[](const KeyType& key);
        bool operator==(const HashTable& other) const;
        bool operator!=(const HashTable& other) const;

        size_t getSize() const { return size; }
        size_t getCapacity() const { return capacity; }

    private:
        size_t hashFunction(const KeyType& key) const;
        void resize(size_t new_capacity);

        size_t capacity;
        size_t size;
        std::vector<std::unique_ptr<HashNode<KeyType, ValueType>>> table;
        Hash hasher;
    };

}

#include "Hash/HashTable.tpp"
