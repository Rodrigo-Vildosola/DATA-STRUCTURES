#include <iostream>
#include <climits>
#include <Structs.h>
#include <DTypes.h>
#include <string>


void print_element(int value) {
    std::cout << value << " ";
}

void print_element_double(double value) {
    std::cout << value << " ";
}

void print_element_string(const std::string& value) {
    std::cout << value << " ";
}

void print_element_person(const Person& person) {
    std::cout << person << " ";
}

void sum_elements(int value, int& sum) {
    sum += value;
}

void find_min_max(int value, int& min, int& max) {
    if (value < min) min = value;
    if (value > max) max = value;
}

int increment_element(int value) {
    return value + 1;
}

double increment_element_double(double value) {
    return value + 1.0;
}

std::string add_exclamation(const std::string& value) {
    return value + "!";
}

Person increase_age(Person person) {
    person.age += 1;
    return person;
}

int main() {
    std::cout << "Demo with int type:" << std::endl;
    STRUCTS::Array<int> array_int;
    array_int.append(1);
    array_int.append(2);
    array_int.append(3);
    array_int.insert(1, 4); // Insert 4 at index 1
    array_int.traverse(print_element);
    std::cout << std::endl;

    int sum = 0;
    array_int.traverse([&sum](int value) { sum_elements(value, sum); });
    std::cout << "Sum of elements: " << sum << std::endl;

    int min = INT_MAX, max = INT_MIN;
    array_int.traverse([&](int value) { find_min_max(value, min, max); });
    std::cout << "Minimum element: " << min << ", Maximum element: " << max << std::endl;

    array_int.map(increment_element);
    array_int.traverse(print_element);
    std::cout << std::endl;

    array_int.update(2, 5); // Update element at index 2 to 5
    array_int.traverse(print_element);
    std::cout << std::endl;

    array_int.remove(1); // Remove element at index 1
    array_int.traverse(print_element);
    std::cout << std::endl;

    std::cout << "Array size: " << array_int.getSize() << std::endl;
    std::cout << "Array capacity: " << array_int.getCapacity() << std::endl;
    std::cout << "Is array empty? " << (array_int.isEmpty() ? "Yes" : "No") << std::endl;

    int search_value = 5;
    std::cout << "Is value " << search_value << " in the array? " 
              << (array_int.search(search_value) ? "Yes" : "No") << std::endl;

    for (int i = 0; i < 20; ++i) {
        array_int.append(i + 10);
    }
    array_int.traverse(print_element);
    std::cout << std::endl;

    for (int i = 0; i < 18; ++i) {
        array_int.remove(0);
    }
    array_int.traverse(print_element);
    std::cout << std::endl;
    std::cout << "Array size after removals: " << array_int.getSize() << std::endl;
    std::cout << "Array capacity after removals: " << array_int.getCapacity() << std::endl;

    std::cout << "\nDemo with double type:" << std::endl;
    STRUCTS::Array<double> array_double;
    array_double.append(1.1);
    array_double.append(2.2);
    array_double.append(3.3);
    array_double.insert(1, 4.4);
    array_double.traverse(print_element_double);
    std::cout << std::endl;

    array_double.map(increment_element_double);
    array_double.traverse(print_element_double);
    std::cout << std::endl;

    std::cout << "\nDemo with std::string type:" << std::endl;
    STRUCTS::Array<std::string> array_string;
    array_string.append("Hello");
    array_string.append("World");
    array_string.append("!");
    array_string.insert(1, "C++");
    array_string.traverse(print_element_string);
    std::cout << std::endl;

    array_string.map(add_exclamation);
    array_string.traverse(print_element_string);
    std::cout << std::endl;

    std::cout << "\nDemo with custom Person struct:" << std::endl;
    STRUCTS::Array<Person> array_person;
    array_person.append(Person{"Alice", 30});
    array_person.append(Person{"Bob", 25});
    array_person.append(Person{"Charlie", 35});
    array_person.insert(1, Person{"Diana", 28});
    array_person.traverse(print_element_person);
    std::cout << std::endl;

    array_person.map(increase_age);
    array_person.traverse(print_element_person);
    std::cout << std::endl;

    return 0;
}
