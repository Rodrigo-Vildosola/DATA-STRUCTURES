#pragma once

#include <memory>
#include <iostream>

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
        void inorder() const;

    private:
    
        std::unique_ptr<TreeNode> root;
        std::unique_ptr<TreeNode> insertRec(std::unique_ptr<TreeNode> node, int value);
        void inorderRec(const TreeNode* node) const;
    };

}
