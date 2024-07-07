#include "HashTable.h"

namespace STRUCTS {

    template <typename KeyType, typename ValueType, typename Hash>
    HashTable<KeyType, ValueType, Hash>::HashTable(size_t initial_capacity)
        : capacity(initial_capacity), size(0), table(initial_capacity), hasher(Hash()) {}

    template <typename KeyType, typename ValueType, typename Hash>
    HashTable<KeyType, ValueType, Hash>::~HashTable() {
        // unique_ptr automatically handles memory deallocation
    }

    template <typename KeyType, typename ValueType, typename Hash>
    size_t HashTable<KeyType, ValueType, Hash>::hashFunction(const KeyType& key) const {
        return hasher(key) % capacity;
    }

    template <typename KeyType, typename ValueType, typename Hash>
    void HashTable<KeyType, ValueType, Hash>::resize(size_t new_capacity) {
        std::vector<std::unique_ptr<HashNode<KeyType, ValueType>>> new_table(new_capacity);

        for (auto& node : table) {
            while (node) {
                size_t new_index = hasher(node->key) % new_capacity;
                auto new_node = std::make_unique<HashNode<KeyType, ValueType>>(node->key, node->value);
                new_node->next = std::move(new_table[new_index]);
                new_table[new_index] = std::move(new_node);

                node = std::move(node->next);
            }
        }

        table = std::move(new_table);
        capacity = new_capacity;
    }

    template <typename KeyType, typename ValueType, typename Hash>
    void HashTable<KeyType, ValueType, Hash>::insert(const KeyType& key, const ValueType& value) {
        if (size >= static_cast<size_t>(capacity * 0.75)) {
            resize(capacity * 2);
        }

        size_t index = hashFunction(key);
        auto& node = table[index];
        while (node) {
            if (node->key == key) {
                node->value = value;
                return;
            }
            node = node->next.get();
        }

        auto new_node = std::make_unique<HashNode<KeyType, ValueType>>(key, value);
        new_node->next = std::move(table[index]);
        table[index] = std::move(new_node);
        ++size;
    }

    template <typename KeyType, typename ValueType, typename Hash>
    void HashTable<KeyType, ValueType, Hash>::remove(const KeyType& key) {
        size_t index = hashFunction(key);
        auto& node = table[index];
        std::unique_ptr<HashNode<KeyType, ValueType>>* prev = &node;

        while (node && node->key != key) {
            prev = &node->next;
            node = node->next.get();
        }

        if (!node) {
            throw std::runtime_error("Key not found");
        }

        *prev = std::move(node->next);
        --size;
    }

    template <typename KeyType, typename ValueType, typename Hash>
    ValueType HashTable<KeyType, ValueType, Hash>::search(const KeyType& key) const {
        size_t index = hashFunction(key);
        const auto& node = table[index];

        for (auto* n = node.get(); n != nullptr; n = n->next.get()) {
            if (n->key == key) {
                return n->value;
            }
        }

        throw std::runtime_error("Key not found");
    }

    template <typename KeyType, typename ValueType, typename Hash>
    bool HashTable<KeyType, ValueType, Hash>::contains(const KeyType& key) const {
        size_t index = hashFunction(key);
        const auto& node = table[index];

        for (auto* n = node.get(); n != nullptr; n = n->next.get()) {
            if (n->key == key) {
                return true;
            }
        }

        return false;
    }

    template <typename KeyType, typename ValueType, typename Hash>
    ValueType& HashTable<KeyType, ValueType, Hash>::operator[](const KeyType& key) {
        size_t index = hashFunction(key);
        auto& node = table[index];
        while (node) {
            if (node->key == key) {
                return node->value;
            }
            node = node->next.get();
        }

        insert(key, ValueType());
        return table[hashFunction(key)]->value;
    }

    template <typename KeyType, typename ValueType, typename Hash>
    bool HashTable<KeyType, ValueType, Hash>::operator==(const HashTable& other) const {
        if (capacity != other.capacity || size != other.size) {
            return false;
        }
        for (size_t i = 0; i < capacity; ++i) {
            const auto& node1 = table[i];
            const auto& node2 = other.table[i];
            auto* n1 = node1.get();
            auto* n2 = node2.get();
            while (n1 && n2) {
                if (n1->key != n2->key || n1->value != n2->value) {
                    return false;
                }
                n1 = n1->next.get();
                n2 = n2->next.get();
            }
            if (n1 || n2) {
                return false;
            }
        }
        return true;
    }

    template <typename KeyType, typename ValueType, typename Hash>
    bool HashTable<KeyType, ValueType, Hash>::operator!=(const HashTable& other) const {
        return !(*this == other);
    }

}
