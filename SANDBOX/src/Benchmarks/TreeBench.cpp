#include <iostream>
#include <chrono>
#include <Structs.h>
#include <DTypes.h>
#include <Trees/Traversal.h>

using namespace std::chrono;

template <typename Tree>
void benchmarkInsert(Tree& tree, int numElements) {
    auto start = high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i) {
        tree.insert(Person("Name", i));
    }
    auto end = high_resolution_clock::now();
    std::cout << "Insert " << numElements << " elements: " 
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
    bool found = tree.search(Person("Name", value));
    auto end = high_resolution_clock::now();
    std::cout << "Search for value " << Person("Name", value) << ": " 
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

void testAVLTree() {
    const int numElements = 20;
    STRUCTS::AVLTree<Person> avlTree;

    std::cout << "Benchmarking AVL Tree" << std::endl;
    benchmarkInsert(avlTree, numElements);
    benchmarkTraverse(avlTree);
    benchmarkSearch(avlTree, numElements / 2);

    STRUCTS::printTreeStructure(avlTree);
    std::cout << "AVL Tree Memory Usage: " << calculateMemoryUsage(avlTree) << " bytes" << std::endl;
}

void testBinarySearchTree() {
    const int numElements = 10;
    STRUCTS::BinarySearchTree<Person> bst;

    std::cout << "Benchmarking Binary Search Tree" << std::endl;
    benchmarkInsert(bst, numElements);
    benchmarkTraverse(bst);
    benchmarkSearch(bst, numElements / 2);

    STRUCTS::printTreeStructure(bst);
    std::cout << "Binary Search Tree Memory Usage: " << calculateMemoryUsage(bst) << " bytes" << std::endl;
}

int main() {
    testAVLTree();
    std::cout << std::endl;
    testBinarySearchTree();

    return 0;
}
