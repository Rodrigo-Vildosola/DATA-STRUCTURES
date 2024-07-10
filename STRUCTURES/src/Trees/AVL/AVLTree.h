#pragma once

#include <memory>
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <type_traits>

#include "Trees/Traversal.h"

namespace STRUCTS {

    template<typename T>
    struct AVLNode {
        T data;
        std::unique_ptr<AVLNode> left;
        std::unique_ptr<AVLNode> right;
        int height;

        AVLNode(const T& value) : data(value), left(nullptr), right(nullptr), height(1) {}
    };

    template<typename T, typename Compare = std::less<T>>
    class AVLTree {
    public:
        AVLTree();
        explicit AVLTree(Compare comp);
        ~AVLTree();

        void insert(const T& value);
        void remove(const T& value);
        bool search(const T& value) const;

        int getHeight() const;
        int getSize() const { return tree_size; }

        void traverse(const std::function<void(const T&)>& func, TraversalType type = TraversalType::Inorder) const;
        void map(const std::function<T(T)>& func);

        const std::unique_ptr<AVLNode<T>>& getRoot() const { return root; }

    private:
        std::unique_ptr<AVLNode<T>> root;
        int tree_size;
        Compare compare;

        std::unique_ptr<AVLNode<T>> insertRec(std::unique_ptr<AVLNode<T>> node, const T& value);
        std::unique_ptr<AVLNode<T>> removeRec(std::unique_ptr<AVLNode<T>> node, const T& value);
        bool searchRec(const AVLNode<T>* node, const T& value) const;
        int heightRec(const AVLNode<T>* node) const;

        int getNodeHeight(const AVLNode<T>* node) const;
        int getNodeBalance(const AVLNode<T>* node) const;
        std::unique_ptr<AVLNode<T>> rotateRight(std::unique_ptr<AVLNode<T>> y);
        std::unique_ptr<AVLNode<T>> rotateLeft(std::unique_ptr<AVLNode<T>> x);
        std::unique_ptr<AVLNode<T>> balance(std::unique_ptr<AVLNode<T>> node);

        void traverseRec(AVLNode<T>* node, const std::function<void(const T&)>& func, TraversalType type) const;
        void mapRec(AVLNode<T>* node, const std::function<T(T)>& func);

        static_assert(std::is_default_constructible<T>::value, "AVLTree elements must be default-constructible");
        static_assert(std::is_copy_constructible<T>::value, "AVLTree elements must be copy-constructible");
        static_assert(std::is_copy_assignable<T>::value, "AVLTree elements must be copy-assignable");
        static_assert(std::is_move_constructible<T>::value, "AVLTree elements must be move-constructible");
        static_assert(std::is_move_assignable<T>::value, "AVLTree elements must be move-assignable");
        static_assert(std::is_invocable_r<bool, Compare, T, T>::value, "Compare must be a callable that accepts two T parameters and returns bool");
    };

}

#include "Trees/AVL/AVLTree.tpp"
