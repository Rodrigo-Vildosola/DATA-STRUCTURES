// AVLTreeDemo.cpp
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
void testAVLTree(STRUCTS::AVLTree<T>& avl, const std::vector<T>& values) {
    // Insert values
    for (const auto& value : values) {
        avl.insert(value);
    }

    // Print traversals
    std::cout << "In-order traversal: ";
    avl.traverse(printNode, STRUCTS::TraversalType::Inorder);
    std::cout << std::endl;

    std::cout << "Pre-order traversal: ";
    avl.traverse(printNode, STRUCTS::TraversalType::Preorder);
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    avl.traverse(printNode, STRUCTS::TraversalType::Postorder);
    std::cout << std::endl;

    // Search for values
    std::cout << "Search " << values[0] << ": " << (avl.search(values[0]) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search " << values[1] << ": " << (avl.search(values[1]) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 100: " << (avl.search(100) ? "Found" : "Not Found") << std::endl;

    // Tree height
    std::cout << "Tree height: " << avl.getHeight() << std::endl;

    // Remove values
    avl.remove(values[1]);
    std::cout << "In-order traversal after removing " << values[1] << ": ";
    avl.traverse(printNode, STRUCTS::TraversalType::Inorder);
    std::cout << std::endl;

    avl.remove(values[0]);
    std::cout << "In-order traversal after removing " << values[0] << ": ";
    avl.traverse(printNode, STRUCTS::TraversalType::Inorder);
    std::cout << std::endl;

    // Traverse with a custom function
    std::cout << "Traverse with a custom function (multiply by 2): ";
    avl.map([](T value) { return value * 2; });
    std::cout << std::endl;

    std::cout << "In-order traversal after multiplying by 2: ";
    avl.traverse(printNode, STRUCTS::TraversalType::Inorder);
    std::cout << std::endl;
}

template <>
void testAVLTree<std::string>(STRUCTS::AVLTree<std::string>& avl, const std::vector<std::string>& values) {
    // Insert values
    for (const auto& value : values) {
        avl.insert(value);
    }

    // Print traversals
    std::cout << "In-order traversal: ";
    avl.traverse(printStringNode, STRUCTS::TraversalType::Inorder);
    std::cout << std::endl;

    std::cout << "Pre-order traversal: ";
    avl.traverse(printStringNode, STRUCTS::TraversalType::Preorder);
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    avl.traverse(printStringNode, STRUCTS::TraversalType::Postorder);
    std::cout << std::endl;

    // Search for values
    std::cout << "Search " << values[0] << ": " << (avl.search(values[0]) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search " << values[1] << ": " << (avl.search(values[1]) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 'Unknown': " << (avl.search("Unknown") ? "Found" : "Not Found") << std::endl;

    // Tree height
    std::cout << "Tree height: " << avl.getHeight() << std::endl;

    // Remove values
    avl.remove(values[1]);
    std::cout << "In-order traversal after removing " << values[1] << ": ";
    avl.traverse(printStringNode, STRUCTS::TraversalType::Inorder);
    std::cout << std::endl;

    avl.remove(values[0]);
    std::cout << "In-order traversal after removing " << values[0] << ": ";
    avl.traverse(printStringNode, STRUCTS::TraversalType::Inorder);
    std::cout << std::endl;

    // Traverse with a custom function
    std::cout << "Traverse with a custom function (append '_test'): ";
    avl.map([](std::string value) { return value + "_test"; });
    std::cout << std::endl;

    std::cout << "In-order traversal after appending '_test': ";
    avl.traverse(printStringNode, STRUCTS::TraversalType::Inorder);
    std::cout << std::endl;
}

template <>
void testAVLTree<Person>(STRUCTS::AVLTree<Person>& avl, const std::vector<Person>& values) {
    // Insert values
    for (const auto& value : values) {
        avl.insert(value);
    }

    // Print traversals
    std::cout << "In-order traversal: ";
    avl.traverse(printPersonNode, STRUCTS::TraversalType::Inorder);
    std::cout << std::endl;

    std::cout << "Pre-order traversal: ";
    avl.traverse(printPersonNode, STRUCTS::TraversalType::Preorder);
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    avl.traverse(printPersonNode, STRUCTS::TraversalType::Postorder);
    std::cout << std::endl;

    // Search for values
    std::cout << "Search " << values[0] << ": " << (avl.search(values[0]) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search " << values[1] << ": " << (avl.search(values[1]) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 'Unknown': " << (avl.search(Person("Unknown", 0)) ? "Found" : "Not Found") << std::endl;

    // Tree height
    std::cout << "Tree height: " << avl.getHeight() << std::endl;

    // Remove values
    avl.remove(values[1]);
    std::cout << "In-order traversal after removing " << values[1] << ": ";
    avl.traverse(printPersonNode, STRUCTS::TraversalType::Inorder);
    std::cout << std::endl;

    avl.remove(values[0]);
    std::cout << "In-order traversal after removing " << values[0] << ": ";
    avl.traverse(printPersonNode, STRUCTS::TraversalType::Inorder);
    std::cout << std::endl;

    // Traverse with a custom function
    std::cout << "Traverse with a custom function (increase age by 1): ";
    avl.map([](Person value) { value.age += 1; return value; });
    std::cout << std::endl;

    std::cout << "In-order traversal after increasing age by 1: ";
    avl.traverse(printPersonNode, STRUCTS::TraversalType::Inorder);
    std::cout << std::endl;
}

void testAVLTreeInt() {
    std::cout << "Testing AVLTree<int>..." << std::endl;
    STRUCTS::AVLTree<int> avl;
    std::vector<int> values = {10, 20, 5, 3, 7, 15, 25};
    testAVLTree(avl, values);
    std::cout << std::endl;
}

void testAVLTreeString() {
    std::cout << "Testing AVLTree<std::string>..." << std::endl;
    STRUCTS::AVLTree<std::string> avl;
    std::vector<std::string> values = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape"};
    testAVLTree(avl, values);
    std::cout << std::endl;
}

void testAVLTreePerson() {
    std::cout << "Testing AVLTree<Person>..." << std::endl;
    STRUCTS::AVLTree<Person> avl;
    std::vector<Person> values = {Person("Alice", 30), Person("Bob", 25), Person("Charlie", 35)};
    testAVLTree(avl, values);
    std::cout << std::endl;
}

int main() {
    testAVLTreeInt();
    testAVLTreeString();
    testAVLTreePerson();
    return 0;
}
