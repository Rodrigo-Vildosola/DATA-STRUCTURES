#include "Trees/BST/BinarySearchTree.h"

namespace STRUCTS {

    template<typename T, typename Compare>
    BinarySearchTree<T, Compare>::BinarySearchTree() : root(nullptr), tree_size(0), compare(Compare()) {}

    template<typename T, typename Compare>
    BinarySearchTree<T, Compare>::BinarySearchTree(Compare comp) : root(nullptr), tree_size(0), compare(comp) {}

    template<typename T, typename Compare>
    BinarySearchTree<T, Compare>::~BinarySearchTree() {
        // unique_ptr automatically handles memory deallocation
    }

    template<typename T, typename Compare>
    void BinarySearchTree<T, Compare>::insert(const T& value) {
        root = insertRec(std::move(root), value);
        tree_size++;
    }

    template<typename T, typename Compare>
    std::unique_ptr<BSTNode<T>> BinarySearchTree<T, Compare>::insertRec(std::unique_ptr<BSTNode<T>> node, const T& value) {
        if (node == nullptr) {
            return std::make_unique<BSTNode<T>>(value);
        }
        if (compare(value, node->data)) {
            node->left = insertRec(std::move(node->left), value);
        } else if (compare(node->data, value)) {
            node->right = insertRec(std::move(node->right), value);
        }
        return node;
    }

    template<typename T, typename Compare>
    bool BinarySearchTree<T, Compare>::search(const T& value) const {
        return searchRec(root.get(), value);
    }

    template<typename T, typename Compare>
    bool BinarySearchTree<T, Compare>::searchRec(const BSTNode<T>* node, const T& value) const {
        if (node == nullptr) {
            return false;
        }
        if (compare(value, node->data)) {
            return searchRec(node->left.get(), value);
        } else if (compare(node->data, value)) {
            return searchRec(node->right.get(), value);
        } else {
            return true;
        }
    }

    template<typename T, typename Compare>
    void BinarySearchTree<T, Compare>::remove(const T& value) {
        root = removeRec(std::move(root), value);
        tree_size--;
    }

    template<typename T, typename Compare>
    std::unique_ptr<BSTNode<T>> BinarySearchTree<T, Compare>::removeRec(std::unique_ptr<BSTNode<T>> node, const T& value) {
        if (node == nullptr) {
            return node;
        }
        if (compare(value, node->data)) {
            node->left = removeRec(std::move(node->left), value);
        } else if (compare(node->data, value)) {
            node->right = removeRec(std::move(node->right), value);
        } else {
            if (node->left == nullptr) {
                return std::move(node->right);
            } else if (node->right == nullptr) {
                return std::move(node->left);
            }
            BSTNode<T>* minNode = node->right.get();
            while (minNode->left != nullptr) {
                minNode = minNode->left.get();
            }
            node->data = minNode->data;
            node->right = removeRec(std::move(node->right), minNode->data);
        }
        return node;
    }

    template<typename T, typename Compare>
    int BinarySearchTree<T, Compare>::getHeight() const {
        return heightRec(root.get());
    }

    template<typename T, typename Compare>
    int BinarySearchTree<T, Compare>::heightRec(const BSTNode<T>* node) const {
        if (node == nullptr) {
            return -1;
        }
        int leftHeight = heightRec(node->left.get());
        int rightHeight = heightRec(node->right.get());
        return std::max(leftHeight, rightHeight) + 1;
    }

    template<typename T, typename Compare>
    void BinarySearchTree<T, Compare>::traverse(const std::function<void(const T&)>& func, TraversalType type) const {
        traverseRec(root.get(), func, type);
    }

    template<typename T, typename Compare>
    void BinarySearchTree<T, Compare>::traverseRec(BSTNode<T>* node, const std::function<void(const T&)>& func, TraversalType type) const {
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

    template<typename T, typename Compare>
    void BinarySearchTree<T, Compare>::map(const std::function<T(T)>& func) {
        mapRec(root.get(), func);
    }

    template<typename T, typename Compare>
    void BinarySearchTree<T, Compare>::mapRec(BSTNode<T>* node, const std::function<T(T)>& func) {
        if (node == nullptr) {
            return;
        }

        node->data = func(node->data);
        mapRec(node->left.get(), func);
        mapRec(node->right.get(), func);
    }

}
