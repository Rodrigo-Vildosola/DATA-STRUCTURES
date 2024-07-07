#pragma once

#include <memory>
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <type_traits>

#include "Trees/Traversal.h"

namespace STRUCTS {

    template<typename T>
    struct BSTNode {
        T data;
        std::unique_ptr<BSTNode> left;
        std::unique_ptr<BSTNode> right;

        BSTNode(const T& value) : data(value), left(nullptr), right(nullptr) {}
    };

    template<typename T, typename Compare = std::less<T>>
    class BinarySearchTree {
    public:
        BinarySearchTree();
        explicit BinarySearchTree(Compare comp);
        ~BinarySearchTree();

        void insert(const T& value);
        void remove(const T& value);
        bool search(const T& value) const;

        int height() const;
        int size() const { return tree_size; }

        void traverse(const std::function<void(const T&)>& func, TraversalType type = TraversalType::Inorder) const;
        void map(const std::function<T(T)>& func);

    private:
        std::unique_ptr<BSTNode<T>> root;
        int tree_size;
        Compare compare;

        std::unique_ptr<BSTNode<T>> insertRec(std::unique_ptr<BSTNode<T>> node, const T& value);
        std::unique_ptr<BSTNode<T>> removeRec(std::unique_ptr<BSTNode<T>> node, const T& value);
        bool searchRec(const BSTNode<T>* node, const T& value) const;
        int heightRec(const BSTNode<T>* node) const;

        void traverseRec(BSTNode<T>* node, const std::function<void(const T&)>& func, TraversalType type) const;
        void mapRec(BSTNode<T>* node, const std::function<T(T)>& func);
    };

}

#include "Trees/BST/BinarySearchTree.tpp"
