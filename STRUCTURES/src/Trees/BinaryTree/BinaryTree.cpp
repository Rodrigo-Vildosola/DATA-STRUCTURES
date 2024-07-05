// #include "Trees/BinaryTree/BinaryTree.h"
// #include <climits>

// namespace STRUCTS {

//     BinaryTree::BinaryTree() : root(nullptr), tree_size(0), tree_height(-1), tree_min(INT_MAX), tree_max(INT_MIN) {}

//     BinaryTree::~BinaryTree() {
//         // unique_ptr automatically handles memory deallocation
//     }

//     void BinaryTree::insert(int value) {
//         root = insertRec(std::move(root), value);
//         tree_size++;
//         tree_height = height();
//         tree_min = findMin();
//         tree_max = findMax();
//     }

//     std::unique_ptr<TreeNode> BinaryTree::insertRec(std::unique_ptr<TreeNode> node, int value) {
//         if (node == nullptr) {
//             return std::make_unique<TreeNode>(value);
//         }
//         if (value < node->data) {
//             node->left = insertRec(std::move(node->left), value);
//         } else if (value > node->data) {
//             node->right = insertRec(std::move(node->right), value);
//         }
//         return node;
//     }

//     bool BinaryTree::search(int value) const {
//         return searchRec(root.get(), value);
//     }

//     bool BinaryTree::searchRec(const TreeNode* node, int value) const {
//         if (node == nullptr) {
//             return false;
//         }
//         if (value < node->data) {
//             return searchRec(node->left.get(), value);
//         } else if (value > node->data) {
//             return searchRec(node->right.get(), value);
//         } else {
//             return true;
//         }
//     }

//     void BinaryTree::remove(int value) {
//         root = removeRec(std::move(root), value);
//         tree_size--;
//         tree_height = height();
//         if (tree_size > 0) {
//             tree_min = findMin();
//             tree_max = findMax();
//         } else {
//             tree_min = INT_MAX;
//             tree_max = INT_MIN;
//         }
//     }

//     std::unique_ptr<TreeNode> BinaryTree::removeRec(std::unique_ptr<TreeNode> node, int value) {
//         if (node == nullptr) {
//             return node;
//         }
//         if (value < node->data) {
//             node->left = removeRec(std::move(node->left), value);
//         } else if (value > node->data) {
//             node->right = removeRec(std::move(node->right), value);
//         } else {
//             if (node->left == nullptr) {
//                 return std::move(node->right);
//             } else if (node->right == nullptr) {
//                 return std::move(node->left);
//             }
//             TreeNode* minNode = findMinRec(node->right.get());
//             node->data = minNode->data;
//             node->right = removeRec(std::move(node->right), minNode->data);
//         }
//         return node;
//     }

//     TreeNode* BinaryTree::findMinRec(TreeNode* node) const {
//         while (node->left != nullptr) {
//             node = node->left.get();
//         }
//         return node;
//     }

//     int BinaryTree::findMin() const {
//         if (root == nullptr) {
//             throw std::runtime_error("Tree is empty");
//         }
//         return findMinRec(root.get())->data;
//     }

//     TreeNode* BinaryTree::findMaxRec(TreeNode* node) const {
//         while (node->right != nullptr) {
//             node = node->right.get();
//         }
//         return node;
//     }

//     int BinaryTree::findMax() const {
//         if (root == nullptr) {
//             throw std::runtime_error("Tree is empty");
//         }
//         return findMaxRec(root.get())->data;
//     }

//     int BinaryTree::height() const {
//         return heightRec(root.get());
//     }

//     int BinaryTree::heightRec(const TreeNode* node) const {
//         if (node == nullptr) {
//             return -1;
//         }
//         int leftHeight = heightRec(node->left.get());
//         int rightHeight = heightRec(node->right.get());
//         return std::max(leftHeight, rightHeight) + 1;
//     }

//     void BinaryTree::traverse(const std::function<void(const int&)>& func, TraversalType type) const {
//         traverseRec(root.get(), func, type);
//     }

//     void BinaryTree::traverseRec(TreeNode* node, const std::function<void(const int&)>& func, TraversalType type) const {
//         if (node == nullptr) {
//             return;
//         }

//         if (type == TraversalType::Preorder) {
//             func(node->data);
//         }

//         traverseRec(node->left.get(), func, type);

//         if (type == TraversalType::Inorder) {
//             func(node->data);
//         }

//         traverseRec(node->right.get(), func, type);

//         if (type == TraversalType::Postorder) {
//             func(node->data);
//         }
//     }


//     void BinaryTree::map(const std::function<int(int)>& func) {
//         mapRec(root.get(), func);
//     }

//     void BinaryTree::mapRec(TreeNode* node, const std::function<int(int)>& func) {
//         if (node == nullptr) {
//             return;
//         }

//         node->data = func(node->data);
//         mapRec(node->left.get(), func);
//         mapRec(node->right.get(), func);
//     }
// }
