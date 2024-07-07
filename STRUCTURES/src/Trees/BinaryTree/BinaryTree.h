#pragma once

#include <memory>
#include <functional>
#include <stdexcept>
#include <algorithm>

#include "Trees/Traversal.h"

namespace STRUCTS {


    template<typename T>
    struct BTNode {
        T data;
        std::unique_ptr<BTNode> left;
        std::unique_ptr<BTNode> right;

        BTNode(const T& value) : data(value), left(nullptr), right(nullptr) {}
    };

    template<typename T, typename Compare = std::less<T>>
    class BinaryTree {
    public:
        BinaryTree();
        explicit BinaryTree(Compare comp);
        ~BinaryTree();

        void insert(const T& value);
        void remove(const T& value);
        bool search(const T& value) const;

        int height() const;
        int size() const { return tree_size; }

        void traverse(const std::function<void(const T&)>& func, TraversalType type = TraversalType::Inorder) const;
        void map(const std::function<T(T)>& func);

    private:
        std::unique_ptr<BTNode<T>> root;
        int tree_size;
        int tree_height;
        Compare compare;

        std::unique_ptr<BTNode<T>> insertRec(std::unique_ptr<BTNode<T>> node, const T& value);
        std::unique_ptr<BTNode<T>> removeRec(std::unique_ptr<BTNode<T>> node, const T& value);
        bool searchRec(const BTNode<T>* node, const T& value) const;
        int heightRec(const BTNode<T>* node) const;

        void traverseRec(BTNode<T>* node, const std::function<void(const T&)>& func, TraversalType type) const;
        void mapRec(BTNode<T>* node, const std::function<T(T)>& func);
    };

}

// Include the implementation file for template definitions
#include "Trees/BinaryTree/BinaryTree.tpp"
