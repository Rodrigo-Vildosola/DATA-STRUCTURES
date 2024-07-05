#include "Hash/HashTable.h"
#include <iostream>

namespace STRUCTS {

    HashTable::HashTable(int initial_capacity) : capacity(initial_capacity), size(0) {
        table = std::make_unique<std::unique_ptr<HashNode>[]>(static_cast<size_t>(capacity));
        for (size_t i = 0; i < static_cast<size_t>(capacity); ++i) {
            table[i] = nullptr;
        }
    }

    HashTable::~HashTable() {
        // unique_ptr automatically handles memory deallocation
    }

    int HashTable::hashFunction(int key) const {
        return key % capacity;
    }

    void HashTable::resize(int new_capacity) {
        std::unique_ptr<std::unique_ptr<HashNode>[]> new_table = std::make_unique<std::unique_ptr<HashNode>[]>(static_cast<size_t>(new_capacity));
        for (size_t i = 0; i < static_cast<size_t>(new_capacity); ++i) {
            new_table[i] = nullptr;
        }

        for (size_t i = 0; i < static_cast<size_t>(capacity); ++i) {
            std::unique_ptr<HashNode>& node = table[i];
            while (node != nullptr) {
                int new_index = node->key % new_capacity;
                std::unique_ptr<HashNode> next_node = std::move(node->next);

                // Move the node to the new table
                node->next = std::move(new_table[static_cast<size_t>(new_index)]);
                new_table[static_cast<size_t>(new_index)] = std::move(node);
                node = std::move(next_node);
            }
        }

        table = std::move(new_table);
        capacity = new_capacity;
    }

    void HashTable::insert(int key, int value) {
        if (size >= static_cast<int>(capacity * 0.75)) {
            resize(capacity * 2);
        }

        int index = hashFunction(key);
        std::unique_ptr<HashNode>& node = table[static_cast<size_t>(index)];
        while (node != nullptr) {
            if (node->key == key) {
                node->value = value;
                return;
            }
            node = std::move(node->next);
        }

        auto new_node = std::make_unique<HashNode>(key, value);
        new_node->next = std::move(table[static_cast<size_t>(index)]);
        table[static_cast<size_t>(index)] = std::move(new_node);
        ++size;
    }

    void HashTable::remove(int key) {
        int index = hashFunction(key);
        std::unique_ptr<HashNode>& node = table[static_cast<size_t>(index)];
        std::unique_ptr<HashNode>* prev = &node;

        while (node != nullptr && node->key != key) {
            prev = &node->next;
            node = std::move(node->next);
        }

        if (node == nullptr) {
            throw std::runtime_error("Key not found");
        }

        *prev = std::move(node->next);
        --size;
    }

    int HashTable::search(int key) const {
        int index = hashFunction(key);
        const std::unique_ptr<HashNode>& node = table[static_cast<size_t>(index)];

        for (const HashNode* n = node.get(); n != nullptr; n = n->next.get()) {
            if (n->key == key) {
                return n->value;
            }
        }

        throw std::runtime_error("Key not found");
    }

    bool HashTable::contains(int key) const {
        int index = hashFunction(key);
        const std::unique_ptr<HashNode>& node = table[static_cast<size_t>(index)];

        for (const HashNode* n = node.get(); n != nullptr; n = n->next.get()) {
            if (n->key == key) {
                return true;
            }
        }

        return false;
    }

    int& HashTable::operator[](int key) {
        int index = hashFunction(key);
        std::unique_ptr<HashNode>& node = table[static_cast<size_t>(index)];
        while (node != nullptr) {
            if (node->key == key) {
                return node->value;
            }
            node = std::move(node->next);
        }

        // If key not found, insert a new node with default value 0
        insert(key, 0);
        return table[static_cast<size_t>(hashFunction(key))]->value;
    }

    bool HashTable::operator==(const HashTable& other) const {
        if (capacity != other.capacity || size != other.size) {
            return false;
        }
        for (size_t i = 0; i < static_cast<size_t>(capacity); ++i) {
            const std::unique_ptr<HashNode>& node1 = table[i];
            const std::unique_ptr<HashNode>& node2 = other.table[i];
            const HashNode* n1 = node1.get();
            const HashNode* n2 = node2.get();
            while (n1 != nullptr && n2 != nullptr) {
                if (n1->key != n2->key || n1->value != n2->value) {
                    return false;
                }
                n1 = n1->next.get();
                n2 = n2->next.get();
            }
            if (n1 != nullptr || n2 != nullptr) {
                return false;
            }
        }
        return true;
    }

    bool HashTable::operator!=(const HashTable& other) const {
        return !(*this == other);
    }
}
