#include "BinaryTree.h"

namespace STRUCTS {

    template<typename T>
    BinaryTree<T>::BinaryTree() : root(nullptr), tree_size(0), tree_height(-1) {}

    template<typename T>
    BinaryTree<T>::~BinaryTree() {
        // unique_ptr automatically handles memory deallocation
    }

    template<typename T>
    void BinaryTree<T>::insert(const T& value) {
        root = insertRec(std::move(root), value);
        tree_size++;
        tree_height = height();
    }

    template<typename T>
    std::unique_ptr<TreeNode<T>> BinaryTree<T>::insertRec(std::unique_ptr<TreeNode<T>> node, const T& value) {
        if (node == nullptr) {
            return std::make_unique<TreeNode<T>>(value);
        }
        if (value < node->data) {
            node->left = insertRec(std::move(node->left), value);
        } else if (value > node->data) {
            node->right = insertRec(std::move(node->right), value);
        }
        return node;
    }

    template<typename T>
    bool BinaryTree<T>::search(const T& value) const {
        return searchRec(root.get(), value);
    }

    template<typename T>
    bool BinaryTree<T>::searchRec(const TreeNode<T>* node, const T& value) const {
        if (node == nullptr) {
            return false;
        }
        if (value < node->data) {
            return searchRec(node->left.get(), value);
        } else if (value > node->data) {
            return searchRec(node->right.get(), value);
        } else {
            return true;
        }
    }

    template<typename T>
    void BinaryTree<T>::remove(const T& value) {
        root = removeRec(std::move(root), value);
        tree_size--;
        tree_height = height();
    }

    template<typename T>
    std::unique_ptr<TreeNode<T>> BinaryTree<T>::removeRec(std::unique_ptr<TreeNode<T>> node, const T& value) {
        if (node == nullptr) {
            return node;
        }
        if (value < node->data) {
            node->left = removeRec(std::move(node->left), value);
        } else if (value > node->data) {
            node->right = removeRec(std::move(node->right), value);
        } else {
            if (node->left == nullptr) {
                return std::move(node->right);
            } else if (node->right == nullptr) {
                return std::move(node->left);
            }
            TreeNode<T>* minNode = node->right.get();
            while (minNode->left != nullptr) {
                minNode = minNode->left.get();
            }
            node->data = minNode->data;
            node->right = removeRec(std::move(node->right), minNode->data);
        }
        return node;
    }

    template<typename T>
    int BinaryTree<T>::height() const {
        return heightRec(root.get());
    }

    template<typename T>
    int BinaryTree<T>::heightRec(const TreeNode<T>* node) const {
        if (node == nullptr) {
            return -1;
        }
        int leftHeight = heightRec(node->left.get());
        int rightHeight = heightRec(node->right.get());
        return std::max(leftHeight, rightHeight) + 1;
    }

    template<typename T>
    void BinaryTree<T>::traverse(const std::function<void(const T&)>& func, TraversalType type) const {
        traverseRec(root.get(), func, type);
    }

    template<typename T>
    void BinaryTree<T>::traverseRec(TreeNode<T>* node, const std::function<void(const T&)>& func, TraversalType type) const {
        if (node == nullptr) {
            return;
        }

        if (type == TraversalType::Preorder) {
            func(node->data);
        }

        traverseRec(node->left.get(), func, type);

        if (type == TraversalType::Inorder) {
            func(node->data);
        }

        traverseRec(node->right.get(), func, type);

        if (type == TraversalType::Postorder) {
            func(node->data);
        }
    }

    template<typename T>
    void BinaryTree<T>::map(const std::function<T(T)>& func) {
        mapRec(root.get(), func);
    }

    template<typename T>
    void BinaryTree<T>::mapRec(TreeNode<T>* node, const std::function<T(T)>& func) {
        if (node == nullptr) {
            return;
        }

        node->data = func(node->data);
        mapRec(node->left.get(), func);
        mapRec(node->right.get(), func);
    }

}
