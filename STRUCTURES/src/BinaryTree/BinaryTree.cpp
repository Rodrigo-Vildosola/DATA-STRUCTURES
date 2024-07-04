#include "BinaryTree/BinaryTree.h"

namespace STRUCTS {

    BinaryTree::BinaryTree() : root(nullptr) {}

    BinaryTree::~BinaryTree() {
        // unique_ptr automatically handles memory deallocation
    }

    void BinaryTree::insert(int value) {
        root = insertRec(std::move(root), value);
    }

    std::unique_ptr<TreeNode> BinaryTree::insertRec(std::unique_ptr<TreeNode> node, int value) {
        if (node == nullptr) {
            return std::make_unique<TreeNode>(value);
        }
        if (value < node->data) {
            node->left = insertRec(std::move(node->left), value);
        } else if (value > node->data) {
            node->right = insertRec(std::move(node->right), value);
        }
        return node;
    }

    void BinaryTree::inorder() const {
        inorderRec(root.get());
        std::cout << std::endl;
    }

    void BinaryTree::inorderRec(const TreeNode* node) const {
        if (node == nullptr) {
            return;
        }
        inorderRec(node->left.get());
        std::cout << node->data << " ";
        inorderRec(node->right.get());
    }

}
