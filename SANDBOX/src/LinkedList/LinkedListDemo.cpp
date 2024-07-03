#include <iostream>

#include <Structs.h>


namespace STRUCTS {


}

void print_element(int value) {
    std::cout << value << " ";
}

int main() {
    STRUCTS::LinkedList list;

    // Insert elements at the end
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);

    // Insert element at the beginning
    list.insertAtBeginning(0);

    // Insert element at position 2
    list.insertAtPosition(2, 5);

    std::cout << "List elements after insertions: ";
    list.traverse(print_element);
    std::cout << std::endl;

    // Update element at position 2
    list.update(2, 10);
    std::cout << "List elements after update: ";
    list.traverse(print_element);
    std::cout << std::endl;

    // Search for elements
    int searchValue = 10;
    std::cout << "Is value " << searchValue << " in the list? "
              << (list.search(searchValue) ? "Yes" : "No") << std::endl;

    searchValue = 4;
    std::cout << "Is value " << searchValue << " in the list? "
              << (list.search(searchValue) ? "Yes" : "No") << std::endl;

    // Delete element from the beginning
    list.deleteFromBeginning();
    std::cout << "List elements after deleting from beginning: ";
    list.traverse(print_element);
    std::cout << std::endl;

    // Delete element from the end
    list.deleteFromEnd();
    std::cout << "List elements after deleting from end: ";
    list.traverse(print_element);
    std::cout << std::endl;

    // Delete element from position 1
    list.deleteFromPosition(1);
    std::cout << "List elements after deleting from position 1: ";
    list.traverse(print_element);
    std::cout << std::endl;

    std::cout << "List size: " << list.getSize() << std::endl;
    std::cout << "Is list empty? " << (list.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
