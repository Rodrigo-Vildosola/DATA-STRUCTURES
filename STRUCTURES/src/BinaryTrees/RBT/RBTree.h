#pragma once

#include <memory>
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <type_traits>

#include "BinaryTrees/Traversal.h"

namespace STRUCTS {

    enum class Color { RED, BLACK };

    template<typename T>
    struct RBNode {
        T data;
        std::unique_ptr<RBNode> left;
        std::unique_ptr<RBNode> right;
        Color color;

        RBNode(const T& value) : data(value), left(nullptr), right(nullptr), color(Color::RED) {}
    };

    template<typename T, typename Compare = std::less<T>>
    class RBTree {
    public:
        RBTree();
        explicit RBTree(Compare comp);
        ~RBTree();

        void insert(const T& value);
        void remove(const T& value);
        bool search(const T& value) const;

        int getHeight() const;
        int getSize() const { return tree_size; }

        void traverse(const std::function<void(const T&)>& func, TraversalType type = TraversalType::Inorder) const;
        void map(const std::function<T(T)>& func);

        const std::unique_ptr<RBNode<T>>& getRoot() const { return root; }

    private:
        std::unique_ptr<RBNode<T>> root;
        int tree_size;
        Compare compare;

        std::unique_ptr<RBNode<T>> insertRec(std::unique_ptr<RBNode<T>> node, const T& value);
        std::unique_ptr<RBNode<T>> removeRec(std::unique_ptr<RBNode<T>> node, const T& value);
        bool searchRec(const RBNode<T>* node, const T& value) const;
        int heightRec(const RBNode<T>* node) const;

        std::unique_ptr<RBNode<T>> rotateLeft(std::unique_ptr<RBNode<T>> node);
        std::unique_ptr<RBNode<T>> rotateRight(std::unique_ptr<RBNode<T>> node);
        void flipColors(RBNode<T>* node);
        bool isRed(const RBNode<T>* node) const;
        std::unique_ptr<RBNode<T>> balance(std::unique_ptr<RBNode<T>> node);

        void traverseRec(RBNode<T>* node, const std::function<void(const T&)>& func, TraversalType type) const;
        void mapRec(RBNode<T>* node, const std::function<T(T)>& func);
    };

}

#include "BinaryTrees/RBT/RBTree.tpp"
