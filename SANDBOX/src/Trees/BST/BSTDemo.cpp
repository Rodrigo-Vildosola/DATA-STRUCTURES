// BinarySearchTreeDemo.cpp
#include <iostream>
#include <vector>
#include <string>
#include <Structs.h>
#include <DTypes.h>

void printNode(const int& value) {
    std::cout << value << " ";
}

void printStringNode(const std::string& value) {
    std::cout << value << " ";
}

void printPersonNode(const Person& person) {
    std::cout << person << " ";
}

void printVectorNode(const std::vector<int>& value) {
    std::cout << "{ ";
    for (const auto& v : value) {
        std::cout << v << " ";
    }
    std::cout << "} ";
}

template <typename T>
void testBinarySearchTree(STRUCTS::BinarySearchTree<T>& bst, const std::vector<T>& values) {
    // Insert values
    for (const auto& value : values) {
        bst.insert(value);
    }

    // Print traversals
    std::cout << "In-order traversal: ";
    bst.traverse(printNode, STRUCTS::TraversalType::Inorder);
    std::cout << std::endl;

    std::cout << "Pre-order traversal: ";
    bst.traverse(printNode, STRUCTS::TraversalType::Preorder);
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    bst.traverse(printNode, STRUCTS::TraversalType::Postorder);
    std::cout << std::endl;

    // Search for values
    std::cout << "Search " << values[0] << ": " << (bst.search(values[0]) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search " << values[1] << ": " << (bst.search(values[1]) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 100: " << (bst.search(100) ? "Found" : "Not Found") << std::endl;

    // Tree height
    std::cout << "Tree height: " << bst.getHeight() << std::endl;

    // Remove values
    bst.remove(values[1]);
    std::cout << "In-order traversal after removing " << values[1] << ": ";
    bst.traverse(printNode, STRUCTS::TraversalType::Inorder);
    std::cout << std::endl;

    bst.remove(values[0]);
    std::cout << "In-order traversal after removing " << values[0] << ": ";
    bst.traverse(printNode, STRUCTS::TraversalType::Inorder);
    std::cout << std::endl;

    // Traverse with a custom function
    std::cout << "Traverse with a custom function (multiply by 2): ";
    bst.map([](T value) { return value * 2; });
    std::cout << std::endl;

    std::cout << "In-order traversal after multiplying by 2: ";
    bst.traverse(printNode, STRUCTS::TraversalType::Inorder);
    std::cout << std::endl;
}

template <>
void testBinarySearchTree<std::string>(STRUCTS::BinarySearchTree<std::string>& bst, const std::vector<std::string>& values) {
    // Insert values
    for (const auto& value : values) {
        bst.insert(value);
    }

    // Print traversals
    std::cout << "In-order traversal: ";
    bst.traverse(printStringNode, STRUCTS::TraversalType::Inorder);
    std::cout << std::endl;

    std::cout << "Pre-order traversal: ";
    bst.traverse(printStringNode, STRUCTS::TraversalType::Preorder);
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    bst.traverse(printStringNode, STRUCTS::TraversalType::Postorder);
    std::cout << std::endl;

    // Search for values
    std::cout << "Search " << values[0] << ": " << (bst.search(values[0]) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search " << values[1] << ": " << (bst.search(values[1]) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 'Unknown': " << (bst.search("Unknown") ? "Found" : "Not Found") << std::endl;

    // Tree height
    std::cout << "Tree height: " << bst.getHeight() << std::endl;

    // Remove values
    bst.remove(values[1]);
    std::cout << "In-order traversal after removing " << values[1] << ": ";
    bst.traverse(printStringNode, STRUCTS::TraversalType::Inorder);
    std::cout << std::endl;

    bst.remove(values[0]);
    std::cout << "In-order traversal after removing " << values[0] << ": ";
    bst.traverse(printStringNode, STRUCTS::TraversalType::Inorder);
    std::cout << std::endl;

    // Traverse with a custom function
    std::cout << "Traverse with a custom function (append '_test'): ";
    bst.map([](std::string value) { return value + "_test"; });
    std::cout << std::endl;

    std::cout << "In-order traversal after appending '_test': ";
    bst.traverse(printStringNode, STRUCTS::TraversalType::Inorder);
    std::cout << std::endl;
}

template <>
void testBinarySearchTree<Person>(STRUCTS::BinarySearchTree<Person>& bst, const std::vector<Person>& values) {
    // Insert values
    for (const auto& value : values) {
        bst.insert(value);
    }

    // Print traversals
    std::cout << "In-order traversal: ";
    bst.traverse(printPersonNode, STRUCTS::TraversalType::Inorder);
    std::cout << std::endl;

    std::cout << "Pre-order traversal: ";
    bst.traverse(printPersonNode, STRUCTS::TraversalType::Preorder);
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    bst.traverse(printPersonNode, STRUCTS::TraversalType::Postorder);
    std::cout << std::endl;

    // Search for values
    std::cout << "Search " << values[0] << ": " << (bst.search(values[0]) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search " << values[1] << ": " << (bst.search(values[1]) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 'Unknown': " << (bst.search(Person("Unknown", 0)) ? "Found" : "Not Found") << std::endl;

    // Tree height
    std::cout << "Tree height: " << bst.getHeight() << std::endl;

    // Remove values
    bst.remove(values[1]);
    std::cout << "In-order traversal after removing " << values[1] << ": ";
    bst.traverse(printPersonNode, STRUCTS::TraversalType::Inorder);
    std::cout << std::endl;

    bst.remove(values[0]);
    std::cout << "In-order traversal after removing " << values[0] << ": ";
    bst.traverse(printPersonNode, STRUCTS::TraversalType::Inorder);
    std::cout << std::endl;

    // Traverse with a custom function
    std::cout << "Traverse with a custom function (increase age by 1): ";
    bst.map([](Person value) { value.age += 1; return value; });
    std::cout << std::endl;

    std::cout << "In-order traversal after increasing age by 1: ";
    bst.traverse(printPersonNode, STRUCTS::TraversalType::Inorder);
    std::cout << std::endl;
}

void testBinarySearchTreeInt() {
    std::cout << "Testing BinarySearchTree<int>..." << std::endl;
    STRUCTS::BinarySearchTree<int> bst;
    std::vector<int> values = {10, 20, 5, 3, 7, 15, 25};
    testBinarySearchTree(bst, values);
    std::cout << std::endl;
}

void testBinarySearchTreeString() {
    std::cout << "Testing BinarySearchTree<std::string>..." << std::endl;
    STRUCTS::BinarySearchTree<std::string> bst;
    std::vector<std::string> values = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape"};
    testBinarySearchTree(bst, values);
    std::cout << std::endl;
}

void testBinarySearchTreePerson() {
    std::cout << "Testing BinarySearchTree<Person>..." << std::endl;
    STRUCTS::BinarySearchTree<Person> bst;
    std::vector<Person> values = {Person("Alice", 30), Person("Bob", 25), Person("Charlie", 35)};
    testBinarySearchTree(bst, values);
    std::cout << std::endl;
}

int main() {
    testBinarySearchTreeInt();
    testBinarySearchTreeString();
    testBinarySearchTreePerson();
    return 0;
}
