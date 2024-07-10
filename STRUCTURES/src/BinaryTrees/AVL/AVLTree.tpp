#include "BinaryTrees/AVL/AVLTree.h"

namespace STRUCTS {

    template<typename T, typename Compare>
    AVLTree<T, Compare>::AVLTree() : root(nullptr), tree_size(0), compare(Compare()) {}

    template<typename T, typename Compare>
    AVLTree<T, Compare>::AVLTree(Compare comp) : root(nullptr), tree_size(0), compare(comp) {}

    template<typename T, typename Compare>
    AVLTree<T, Compare>::~AVLTree() {
        // unique_ptr automatically handles memory deallocation
    }

    template<typename T, typename Compare>
    void AVLTree<T, Compare>::insert(const T& value) {
        root = insertRec(std::move(root), value);
        tree_size++;
    }

    template<typename T, typename Compare>
    std::unique_ptr<AVLNode<T>> AVLTree<T, Compare>::insertRec(std::unique_ptr<AVLNode<T>> node, const T& value) {
        if (node == nullptr) {
            return std::make_unique<AVLNode<T>>(value);
        }
        if (compare(value, node->data)) {
            node->left = insertRec(std::move(node->left), value);
        } else if (compare(node->data, value)) {
            node->right = insertRec(std::move(node->right), value);
        } else {
            return node;
        }

        node->height = 1 + std::max(getNodeHeight(node->left.get()), getNodeHeight(node->right.get()));
        return balance(std::move(node));
    }

    template<typename T, typename Compare>
    bool AVLTree<T, Compare>::search(const T& value) const {
        return searchRec(root.get(), value);
    }

    template<typename T, typename Compare>
    bool AVLTree<T, Compare>::searchRec(const AVLNode<T>* node, const T& value) const {
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
    void AVLTree<T, Compare>::remove(const T& value) {
        root = removeRec(std::move(root), value);
        tree_size--;
    }

    template<typename T, typename Compare>
    std::unique_ptr<AVLNode<T>> AVLTree<T, Compare>::removeRec(std::unique_ptr<AVLNode<T>> node, const T& value) {
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
            AVLNode<T>* minNode = node->right.get();
            while (minNode->left != nullptr) {
                minNode = minNode->left.get();
            }
            node->data = minNode->data;
            node->right = removeRec(std::move(node->right), minNode->data);
        }

        node->height = 1 + std::max(getNodeHeight(node->left.get()), getNodeHeight(node->right.get()));
        return balance(std::move(node));
    }

    template<typename T, typename Compare>
    int AVLTree<T, Compare>::getHeight() const {
        return heightRec(root.get());
    }

    template<typename T, typename Compare>
    int AVLTree<T, Compare>::heightRec(const AVLNode<T>* node) const {
        if (node == nullptr) {
            return -1;
        }
        int leftHeight = heightRec(node->left.get());
        int rightHeight = heightRec(node->right.get());
        return std::max(leftHeight, rightHeight) + 1;
    }

    template<typename T, typename Compare>
    void AVLTree<T, Compare>::traverse(const std::function<void(const T&)>& func, TraversalType type) const {
        traverseRec(root.get(), func, type);
    }

    template<typename T, typename Compare>
    void AVLTree<T, Compare>::traverseRec(AVLNode<T>* node, const std::function<void(const T&)>& func, TraversalType type) const {
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
    void AVLTree<T, Compare>::map(const std::function<T(T)>& func) {
        mapRec(root.get(), func);
    }

    template<typename T, typename Compare>
    void AVLTree<T, Compare>::mapRec(AVLNode<T>* node, const std::function<T(T)>& func) {
        if (node == nullptr) {
            return;
        }

        node->data = func(node->data);
        mapRec(node->left.get(), func);
        mapRec(node->right.get(), func);
    }

    template<typename T, typename Compare>
    int AVLTree<T, Compare>::getNodeHeight(const AVLNode<T>* node) const {
        return node ? node->height : 0;
    }

    template<typename T, typename Compare>
    int AVLTree<T, Compare>::getNodeBalance(const AVLNode<T>* node) const {
        return node ? getNodeHeight(node->left.get()) - getNodeHeight(node->right.get()) : 0;
    }

    template<typename T, typename Compare>
    std::unique_ptr<AVLNode<T>> AVLTree<T, Compare>::rotateRight(std::unique_ptr<AVLNode<T>> y) {
        std::unique_ptr<AVLNode<T>> x = std::move(y->left);
        y->left = std::move(x->right);
        x->right = std::move(y);

        x->right->height = 1 + std::max(getNodeHeight(x->right->left.get()), getNodeHeight(x->right->right.get()));
        x->height = 1 + std::max(getNodeHeight(x->left.get()), getNodeHeight(x->right.get()));

        return x;
    }

    template<typename T, typename Compare>
    std::unique_ptr<AVLNode<T>> AVLTree<T, Compare>::rotateLeft(std::unique_ptr<AVLNode<T>> x) {
        std::unique_ptr<AVLNode<T>> y = std::move(x->right);
        x->right = std::move(y->left);
        y->left = std::move(x);

        y->left->height = 1 + std::max(getNodeHeight(y->left->left.get()), getNodeHeight(y->left->right.get()));
        y->height = 1 + std::max(getNodeHeight(y->left.get()), getNodeHeight(y->right.get()));

        return y;
    }

    template<typename T, typename Compare>
    std::unique_ptr<AVLNode<T>> AVLTree<T, Compare>::balance(std::unique_ptr<AVLNode<T>> node) {
        int balanceFactor = getNodeBalance(node.get());

        if (balanceFactor > 1) {
            if (getNodeBalance(node->left.get()) < 0) {
                node->left = rotateLeft(std::move(node->left));
            }
            return rotateRight(std::move(node));
        }

        if (balanceFactor < -1) {
            if (getNodeBalance(node->right.get()) > 0) {
                node->right = rotateRight(std::move(node->right));
            }
            return rotateLeft(std::move(node));
        }

        return node;
    }

} // namespace STRUCTS
