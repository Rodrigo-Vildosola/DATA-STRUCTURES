#pragma once
#include <memory>
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <sstream>

namespace STRUCTS {

    enum class TraversalType {
        Inorder,
        Preorder,
        Postorder
    }; 

    template <typename T, typename Tree>
    void prettyPrintTree(const Tree& tree, TraversalType type = TraversalType::Inorder) {
        std::vector<std::string> nodes;

        // Lambda function to capture and format nodes
        auto captureNode = [&nodes](const T& value) {
            std::stringstream ss;
            ss << value;
            nodes.push_back(ss.str());
        };

        // Traverse the tree and capture nodes
        tree.traverse(std::function<void(const T&)>(captureNode), type);

        // Print the captured nodes
        std::cout << "Tree (" << (type == TraversalType::Inorder ? "Inorder" : type == TraversalType::Preorder ? "Preorder" : "Postorder") << "): ";
        for (const auto& node : nodes) {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    }

    // Function to print tree structure level by level
    template <typename Node>
    void printLevel(std::vector<std::vector<std::string>>& levels, const std::unique_ptr<Node>& node, int level, int maxDepth) {
        if (!node) {
            if (level < maxDepth) {
                levels[static_cast<std::size_t>(level)].push_back(" ");
                printLevel(levels, node, level + 1, maxDepth);
                printLevel(levels, node, level + 1, maxDepth);
            }
            return;
        }

        std::stringstream ss;
        ss << node->data;
        levels[static_cast<std::size_t>(level)].push_back(ss.str());

        printLevel(levels, node->left, level + 1, maxDepth);
        printLevel(levels, node->right, level + 1, maxDepth);
    }

    template <typename Tree>
    void printTreeStructure(const Tree& tree) {
        using NodeType = typename std::remove_reference<decltype(*tree.getRoot())>::type;
        int maxDepth = tree.getHeight();
        std::vector<std::vector<std::string>> levels(static_cast<std::size_t>(maxDepth + 1));

        printLevel<NodeType>(levels, tree.getRoot(), 0, maxDepth);

        for (const auto& level : levels) {
            for (const auto& node : level) {
                std::cout << node << " ";
            }
            std::cout << std::endl;
        }
    }
}
