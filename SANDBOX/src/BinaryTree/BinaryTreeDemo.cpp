// BinaryTreeDemo.cpp
#include <iostream>
#include "BinaryTree/BinaryTree.h"

void testBinaryTree() {
    STRUCTS::BinaryTree bt;

    // Insert values
    bt.insert(10);
    bt.insert(20);
    bt.insert(5);
    bt.insert(3);
    bt.insert(7);
    bt.insert(15);
    bt.insert(25);

    // Print traversals
    std::cout << "In-order traversal: ";
    bt.inorder();

    std::cout << "Pre-order traversal: ";
    bt.preorder();

    std::cout << "Post-order traversal: ";
    bt.postorder();

    // Search for values
    std::cout << "Search 10: " << (bt.search(10) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 20: " << (bt.search(20) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 100: " << (bt.search(100) ? "Found" : "Not Found") << std::endl;

    // Find min and max
    std::cout << "Min value: " << bt.findMin() << std::endl;
    std::cout << "Max value: " << bt.findMax() << std::endl;

    // Tree height
    std::cout << "Tree height: " << bt.height() << std::endl;

    // Remove values
    bt.remove(20);
    std::cout << "In-order traversal after removing 20: ";
    bt.inorder();

    bt.remove(10);
    std::cout << "In-order traversal after removing 10: ";
    bt.inorder();

    // Traverse with a custom function
    std::cout << "Traverse with a custom function (multiply by 2): ";
    bt.traverse([](int value) { std::cout << value * 2 << " "; });
    std::cout << std::endl;
    bt.inorder();

}

int main() {
    testBinaryTree();
    return 0;
}
