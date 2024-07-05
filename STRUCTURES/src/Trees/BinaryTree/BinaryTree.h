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

        void traverse(const std::function<void(const int&)>& func, TraversalType type = TraversalType::Inorder) const;
        void map(const std::function<int(int)>& func);

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

        void traverseRec(TreeNode* node, const std::function<void(const int&)>& func, TraversalType type) const;
        void mapRec(TreeNode* node, const std::function<int(int)>& func);

    };

}
