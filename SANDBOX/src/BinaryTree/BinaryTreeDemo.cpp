// BinaryTreeDemo.cpp
#include <iostream>
#include <Structs.h>

void printNode(const int& value) {
    std::cout << value << " ";
}

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
    bt.traverse(printNode, STRUCTS::TraversalType::Inorder);
    std::cout << std::endl;

    std::cout << "Pre-order traversal: ";
    bt.traverse(printNode, STRUCTS::TraversalType::Preorder);
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    bt.traverse(printNode, STRUCTS::TraversalType::Postorder);
    std::cout << std::endl;

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
    bt.traverse(printNode, STRUCTS::TraversalType::Inorder);
    std::cout << std::endl;

    bt.remove(10);
    std::cout << "In-order traversal after removing 10: ";
    bt.traverse(printNode, STRUCTS::TraversalType::Inorder);
    std::cout << std::endl;

    // Traverse with a custom function
    std::cout << "Traverse with a custom function (multiply by 2): ";
    bt.map([](int value) { return value * 2; });
    std::cout << std::endl;

    std::cout << "In-order traversal after multiplying by 2: ";
    bt.traverse(printNode, STRUCTS::TraversalType::Inorder);
    std::cout << std::endl;
}

int main() {
    testBinaryTree();
    return 0;
}
