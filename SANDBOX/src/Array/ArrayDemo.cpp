#include <iostream>

#include <Structs.h>


namespace STRUCTS {


}


void print_element(int value) {
    std::cout << value << " ";
}

int main() {
    STRUCTS::Array array(4);

    array.insert(0, 1);
    array.insert(1, 2);
    array.insert(2, 3);
    array.insert(1, 4); // Insert 4 at index 1

    std::cout << "Array elements after insertion: ";
    array.traverse(print_element);
    std::cout << std::endl;

    std::cout << "Element at index 2: " << array.get(2) << std::endl;

    array.update(2, 5); // Update element at index 2 to 5
    std::cout << "Array elements after update: ";
    array.traverse(print_element);
    std::cout << std::endl;

    array.remove(1); // Remove element at index 1
    std::cout << "Array elements after removal: ";
    array.traverse(print_element);
    std::cout << std::endl;

    return 0;
}
