#include <iostream>

#include <Structs.h>


namespace STRUCTS {


}


void print_element(int value) {
    std::cout << value << " ";
}

void sum_elements(int value, int& sum) {
    sum += value;
}

void find_min_max(int value, int& min, int& max) {
    if (value < min) min = value;
    if (value > max) max = value;
}

void increment_element(int& value) {
    value += 1;
}

int main() {
    STRUCTS::Array array;

    array.append(1);
    array.append(2);
    array.append(3);
    array.insert(1, 4); // Insert 4 at index 1

    std::cout << "Array elements after insertion: ";
    array.traverse(print_element);
    std::cout << std::endl;

    // Sum of elements
    int sum = 0;
    array.traverse([&sum](int value) { sum_elements(value, sum); });
    std::cout << "Sum of elements: " << sum << std::endl;

    // Find min and max
    int min = INT_MAX, max = INT_MIN;
    array.traverse([&min, &max](int value) { find_min_max(value, min, max); });
    std::cout << "Minimum element: " << min << ", Maximum element: " << max << std::endl;

    // Increment each element
    array.traverse([](int value) { increment_element(value); });
    std::cout << "Array elements after increment: ";
    array.traverse(print_element);
    std::cout << std::endl;

    // Update and remove elements
    array.update(2, 5); // Update element at index 2 to 5
    std::cout << "Array elements after update: ";
    array.traverse(print_element);
    std::cout << std::endl;

    array.remove(1); // Remove element at index 1
    std::cout << "Array elements after removal: ";
    array.traverse(print_element);
    std::cout << std::endl;

    std::cout << "Array size: " << array.getSize() << std::endl;
    std::cout << "Array capacity: " << array.getCapacity() << std::endl;
    std::cout << "Is array empty? " << (array.isEmpty() ? "Yes" : "No") << std::endl;

    int search_value = 5;
    std::cout << "Is value " << search_value << " in the array? " 
              << (array.search(search_value) ? "Yes" : "No") << std::endl;

    // Test resizing during removal
    for (int i = 0; i < 20; ++i) {
        array.append(i + 10);
    }
    std::cout << "Array elements after adding more elements: ";
    array.traverse(print_element);
    std::cout << std::endl;

    for (int i = 0; i < 18; ++i) {
        array.remove(0);
    }
    std::cout << "Array elements after removing many elements: ";
    array.traverse(print_element);
    std::cout << std::endl;
    std::cout << "Array size after removals: " << array.getSize() << std::endl;
    std::cout << "Array capacity after removals: " << array.getCapacity() << std::endl;

    return 0;
}
