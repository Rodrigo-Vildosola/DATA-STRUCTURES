#include "BinaryTrees/RBT/RBTree.h"

namespace STRUCTS {

    template<typename T, typename Compare>
    RBTree<T, Compare>::RBTree() : root(nullptr), tree_size(0), compare(Compare()) {}

    template<typename T, typename Compare>
    RBTree<T, Compare>::RBTree(Compare comp) : root(nullptr), tree_size(0), compare(comp) {}

    template<typename T, typename Compare>
    RBTree<T, Compare>::~RBTree() {
        // unique_ptr automatically handles memory deallocation
    }

    template<typename T, typename Compare>
    void RBTree<T, Compare>::insert(const T& value) {
        root = insertRec(std::move(root), value);
        root->color = Color::BLACK;
        tree_size++;
    }

    template<typename T, typename Compare>
    std::unique_ptr<RBNode<T>> RBTree<T, Compare>::insertRec(std::unique_ptr<RBNode<T>> node, const T& value) {
        if (node == nullptr) {
            return std::make_unique<RBNode<T>>(value);
        }
        if (compare(value, node->data)) {
            node->left = insertRec(std::move(node->left), value);
        } else if (compare(node->data, value)) {
            node->right = insertRec(std::move(node->right), value);
        } else {
            return node;
        }

        if (isRed(node->right.get()) && !isRed(node->left.get())) node = rotateLeft(std::move(node));
        if (isRed(node->left.get()) && isRed(node->left->left.get())) node = rotateRight(std::move(node));
        if (isRed(node->left.get()) && isRed(node->right.get())) flipColors(node.get());

        return node;
    }

    template<typename T, typename Compare>
    bool RBTree<T, Compare>::search(const T& value) const {
        return searchRec(root.get(), value);
    }

    template<typename T, typename Compare>
    bool RBTree<T, Compare>::searchRec(const RBNode<T>* node, const T& value) const {
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
    void RBTree<T, Compare>::remove(const T& value) {
        if (!search(value)) return; // Node not found, do nothing
        if (!isRed(root->left.get()) && !isRed(root->right.get())) root->color = Color::RED;
        root = removeRec(std::move(root), value);
        if (root != nullptr) root->color = Color::BLACK;
        tree_size--;
    }

    template<typename T, typename Compare>
    std::unique_ptr<RBNode<T>> RBTree<T, Compare>::removeRec(std::unique_ptr<RBNode<T>> node, const T& value) {
        if (compare(value, node->data)) {
            if (!isRed(node->left.get()) && !isRed(node->left->left.get())) {
                node = moveRedLeft(std::move(node));
            }
            node->left = removeRec(std::move(node->left), value);
        } else {
            if (isRed(node->left.get())) {
                node = rotateRight(std::move(node));
            }
            if (compare(node->data, value) && (node->right == nullptr)) {
                return nullptr;
            }
            if (!isRed(node->right.get()) && !isRed(node->right->left.get())) {
                node = moveRedRight(std::move(node));
            }
            if (compare(node->data, value)) {
                RBNode<T>* minNode = node->right.get();
                while (minNode->left != nullptr) {
                    minNode = minNode->left.get();
                }
                node->data = minNode->data;
                node->right = deleteMin(std::move(node->right));
            } else {
                node->right = removeRec(std::move(node->right), value);
            }
        }

        return balance(std::move(node));
    }

    template<typename T, typename Compare>
    int RBTree<T, Compare>::getHeight() const {
        return heightRec(root.get());
    }

    template<typename T, typename Compare>
    int RBTree<T, Compare>::heightRec(const RBNode<T>* node) const {
        if (node == nullptr) {
            return -1;
        }
        int leftHeight = heightRec(node->left.get());
        int rightHeight = heightRec(node->right.get());
        return std::max(leftHeight, rightHeight) + 1;
    }

    template<typename T, typename Compare>
    void RBTree<T, Compare>::traverse(const std::function<void(const T&)>& func, TraversalType type) const {
        traverseRec(root.get(), func, type);
    }

    template<typename T, typename Compare>
    void RBTree<T, Compare>::traverseRec(RBNode<T>* node, const std::function<void(const T&)>& func, TraversalType type) const {
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
    void RBTree<T, Compare>::map(const std::function<T(T)>& func) {
        mapRec(root.get(), func);
    }

    template<typename T, typename Compare>
    void RBTree<T, Compare>::mapRec(RBNode<T>* node, const std::function<T(T)>& func) {
        if (node == nullptr) {
            return;
        }

        node->data = func(node->data);
        mapRec(node->left.get(), func);
        mapRec(node->right.get(), func);
    }

    template<typename T, typename Compare>
    std::unique_ptr<RBNode<T>> RBTree<T, Compare>::rotateLeft(std::unique_ptr<RBNode<T>> node) {
        std::unique_ptr<RBNode<T>> x = std::move(node->right);
        node->right = std::move(x->left);
        x->left = std::move(node);
        x->color = x->left->color;
        x->left->color = Color::RED;
        return x;
    }

    template<typename T, typename Compare>
    std::unique_ptr<RBNode<T>> RBTree<T, Compare>::rotateRight(std::unique_ptr<RBNode<T>> node) {
        std::unique_ptr<RBNode<T>> x = std::move(node->left);
        node->left = std::move(x->right);
        x->right = std::move(node);
        x->color = x->right->color;
        x->right->color = Color::RED;
        return x;
    }

    template<typename T, typename Compare>
    void RBTree<T, Compare>::flipColors(RBNode<T>* node) {
        node->color = (node->color == Color::RED) ? Color::BLACK : Color::RED;
        if (node->left != nullptr) {
            node->left->color = (node->left->color == Color::RED) ? Color::BLACK : Color::RED;
        }
        if (node->right != nullptr) {
            node->right->color = (node->right->color == Color::RED) ? Color::BLACK : Color::RED;
        }
    }

    template<typename T, typename Compare>
    bool RBTree<T, Compare>::isRed(const RBNode<T>* node) const {
        return node != nullptr && node->color == Color::RED;
    }

    template<typename T, typename Compare>
    std::unique_ptr<RBNode<T>> RBTree<T, Compare>::balance(std::unique_ptr<RBNode<T>> node) {
        if (isRed(node->right.get())) node = rotateLeft(std::move(node));
        if (isRed(node->left.get()) && isRed(node->left->left.get())) node = rotateRight(std::move(node));
        if (isRed(node->left.get()) && isRed(node->right.get())) flipColors(node.get());

        return node;
    }

} // namespace STRUCTS
