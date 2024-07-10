#pragma once
#include <memory>
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iostream>
#include <iomanip>

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

    template <typename Node>
    void collectLevels(std::vector<std::string>& levels, const std::unique_ptr<Node>& node, int level, size_t maxNodeWidth) {
        if (static_cast<size_t>(level) == levels.size()) {
            levels.push_back("");
        }

        if (node) {
            std::stringstream ss;
            ss << to_string(node->data);
            std::string nodeStr = ss.str();
            levels[static_cast<size_t>(level)] += nodeStr + " ";
            collectLevels(levels, node->left, level + 1, maxNodeWidth);
            collectLevels(levels, node->right, level + 1, maxNodeWidth);
        } else {
            // Add spaces for a missing node
            std::string spaces(maxNodeWidth, ' ');
            levels[static_cast<size_t>(level)] += spaces + " ";
        }
    }

    template <typename Tree>
    void printTreeStructure(const Tree& tree) {
        using NodeType = typename std::remove_reference<decltype(*tree.getRoot())>::type;
        std::vector<std::string> levels;

        // Find the maximum width of any node's string representation
        size_t maxNodeWidth = 0;
        tree.traverse([&maxNodeWidth](const auto& value) {
            std::stringstream ss;
            ss << to_string(value);
            maxNodeWidth = std::max(maxNodeWidth, ss.str().size());
        }, STRUCTS::TraversalType::Inorder);

        collectLevels<NodeType>(levels, tree.getRoot(), 0, maxNodeWidth);

        // Calculate the maximum width needed for the bottom level
        // size_t maxWidth = levels.back().size();

        // Pad each level to the maximum width
        // for (auto& level : levels) {
        //     while (level.size() < maxWidth) {
        //         level = " " + level + " ";
        //     }
        // }

        // Print each level with appropriate spacing
        for (const auto& level : levels) {
            std::cout << level << std::endl;
        }
    }

}
