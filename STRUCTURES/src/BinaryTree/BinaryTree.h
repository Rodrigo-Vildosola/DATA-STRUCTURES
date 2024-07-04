#pragma once

#include <memory>
#include <functional>
#include <stdexcept>
#include <iostream>
#include <algorithm>

namespace STRUCTS {

    struct TreeNode {
        int data;
        std::unique_ptr<TreeNode> left;
        std::unique_ptr<TreeNode> right;

        TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    class BinaryTree {
    public:
        BinaryTree();
        ~BinaryTree();

        void insert(int value);
        void remove(int value);
        bool search(int value) const;

        int findMin() const;
        int findMax() const;
        int height() const;
        int size() const { return tree_size; }

        void inorder() const;
        void preorder() const;
        void postorder() const;

        void traverse(const std::function<void(int&)>& func);

    private:
        std::unique_ptr<TreeNode> root;
        int tree_size;
        int tree_height;
        int tree_min;
        int tree_max;

        std::unique_ptr<TreeNode> insertRec(std::unique_ptr<TreeNode> node, int value);
        std::unique_ptr<TreeNode> removeRec(std::unique_ptr<TreeNode> node, int value);
        bool searchRec(const TreeNode* node, int value) const;
        TreeNode* findMinRec(TreeNode* node) const;
        TreeNode* findMaxRec(TreeNode* node) const;
        int heightRec(const TreeNode* node) const;

        void inorderRec(const TreeNode* node) const;
        void preorderRec(const TreeNode* node) const;
        void postorderRec(const TreeNode* node) const;

        void traverseRec(TreeNode* node, const std::function<void(int&)>& func);
    };

}
