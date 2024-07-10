#include <iostream>
#include <chrono>
#include <Structs.h>
#include <DTypes.h>
#include <BinaryTrees/Traversal.h>
#include <vector>
#include <algorithm>
#include <random>

using namespace std::chrono;

std::vector<Person> generateRandomPersons(int numElements) {
    std::vector<Person> persons;
    for (int i = 0; i < numElements; ++i) {
        persons.emplace_back("Name", i);
    }
    // Shuffle the persons to randomize
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(persons.begin(), persons.end(), g);
    return persons;
}

template <typename Tree>
void benchmarkInsert(Tree& tree, const std::vector<Person>& persons) {
    auto start = high_resolution_clock::now();
    for (const auto& person : persons) {
        tree.insert(person);
    }
    auto end = high_resolution_clock::now();
    std::cout << "Insert " << persons.size() << " elements: " 
              << duration_cast<milliseconds>(end - start).count() 
              << "ms" << std::endl;
}

template <typename Tree>
void benchmarkTraverse(Tree& tree) {
    auto start = high_resolution_clock::now();
    tree.traverse([](const auto& value) {
        // Do nothing, just traverse
        (void)value;
    });
    auto end = high_resolution_clock::now();
    std::cout << "Traverse: " 
              << duration_cast<milliseconds>(end - start).count() 
              << "ms" << std::endl;
}

template <typename Tree, typename T>
void benchmarkSearch(const Tree& tree, const T& value) {
    auto start = high_resolution_clock::now();
    bool found = tree.search(Person("Name", static_cast<int>(value)));
    auto end = high_resolution_clock::now();
    std::cout << "Search for value " << Person("Name", static_cast<int>(value)) << ": " 
              << duration_cast<milliseconds>(end - start).count() 
              << "ms" << std::endl;
    std::cout << "Value " << (found ? "found" : "not found") << std::endl;
}

template <typename T>
size_t calculateMemoryUsage(const STRUCTS::BinarySearchTree<T>& tree) {
    // Placeholder implementation; actual memory calculation may be more complex
    return sizeof(tree) + static_cast<size_t>(tree.getSize()) * sizeof(STRUCTS::BSTNode<T>);
}

template <typename T>
size_t calculateMemoryUsage(const STRUCTS::AVLTree<T>& tree) {
    // Placeholder implementation; actual memory calculation may be more complex
    return sizeof(tree) + static_cast<size_t>(tree.getSize()) * sizeof(STRUCTS::AVLNode<T>);
}

template <typename T>
size_t calculateMemoryUsage(const STRUCTS::RBTree<T>& tree) {
    // Placeholder implementation; actual memory calculation may be more complex
    return sizeof(tree) + static_cast<size_t>(tree.getSize()) * sizeof(STRUCTS::RBNode<T>);
}

void testAVLTree(const std::vector<Person>& persons) {
    STRUCTS::AVLTree<Person> avlTree;

    std::cout << "Benchmarking AVL Tree" << std::endl;
    benchmarkInsert(avlTree, persons);
    benchmarkTraverse(avlTree);
    benchmarkSearch(avlTree, persons.size() / 2);

    // STRUCTS::printTreeStructure(avlTree);
    std::cout << "AVL Tree Memory Usage: " << calculateMemoryUsage(avlTree) << " bytes" << std::endl;
}

void testRedBlackTree(const std::vector<Person>& persons) {
    STRUCTS::RBTree<Person> rbt;

    std::cout << "Benchmarking Red Black Tree" << std::endl;
    benchmarkInsert(rbt, persons);
    benchmarkTraverse(rbt);
    benchmarkSearch(rbt, persons.size() / 2);

    // STRUCTS::printTreeStructure(bst);
    std::cout << "Red Black Tree Memory Usage: " << calculateMemoryUsage(rbt) << " bytes" << std::endl;
}

void testBinarySearchTree(const std::vector<Person>& persons) {
    STRUCTS::BinarySearchTree<Person> bst;

    std::cout << "Benchmarking Binary Search Tree" << std::endl;
    benchmarkInsert(bst, persons);
    benchmarkTraverse(bst);
    benchmarkSearch(bst, persons.size() / 2);

    // STRUCTS::printTreeStructure(bst);
    std::cout << "Binary Search Tree Memory Usage: " << calculateMemoryUsage(bst) << " bytes" << std::endl;
}

int main() {
    const int numElements = 20000;

    std::vector<Person> persons = generateRandomPersons(numElements);

    testAVLTree(persons);
    std::cout << std::endl;

    testRedBlackTree(persons);
    std::cout << std::endl;

    testBinarySearchTree(persons);

    return 0;
}
