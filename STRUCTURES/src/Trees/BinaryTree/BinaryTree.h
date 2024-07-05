#pragma once

#include <memory>
#include <functional>
#include <stdexcept>
#include <algorithm>

namespace STRUCTS {

    enum class TraversalType {
        Inorder,
        Preorder,
        Postorder
    }; 

    template<typename T>
    struct TreeNode {
        T data;
        std::unique_ptr<TreeNode> left;
        std::unique_ptr<TreeNode> right;

        TreeNode(const T& value) : data(value), left(nullptr), right(nullptr) {}
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
        std::unique_ptr<TreeNode<T>> root;
        int tree_size;
        int tree_height;
        Compare compare;

        std::unique_ptr<TreeNode<T>> insertRec(std::unique_ptr<TreeNode<T>> node, const T& value);
        std::unique_ptr<TreeNode<T>> removeRec(std::unique_ptr<TreeNode<T>> node, const T& value);
        bool searchRec(const TreeNode<T>* node, const T& value) const;
        int heightRec(const TreeNode<T>* node) const;

        void traverseRec(TreeNode<T>* node, const std::function<void(const T&)>& func, TraversalType type) const;
        void mapRec(TreeNode<T>* node, const std::function<T(T)>& func);
    };

}

// Include the implementation file for template definitions
#include "Trees/BinaryTree/BinaryTree.tpp"
