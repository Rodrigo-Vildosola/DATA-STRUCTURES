#include <iostream>
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

int increment_element(int value) {
    return value + 1;
}

double increment_element_double(double value) {
    return value + 1.0;
}

std::string append_string(const std::string& value) {
    return value + " World";
}

Person increment_person_age(Person person) {
    person.age += 1;
    return person;
}

int main() {
    std::cout << "Demo with int type:" << std::endl;
    STRUCTS::LinkedList<int> list_int;
    list_int.insertAtEnd(1);
    list_int.insertAtEnd(2);
    list_int.insertAtEnd(3);
    list_int.insertAtBeginning(0);
    list_int.insertAtPosition(2, 5);

    std::cout << "List elements after insertions: ";
    list_int.traverse(print_element);
    std::cout << std::endl;

    list_int.update(2, 10);
    std::cout << "List elements after update: ";
    list_int.traverse(print_element);
    std::cout << std::endl;

    list_int.map(increment_element);
    std::cout << "List elements after map (increment): ";
    list_int.traverse(print_element);
    std::cout << std::endl;

    list_int.deleteFromBeginning();
    std::cout << "List elements after deleting from beginning: ";
    list_int.traverse(print_element);
    std::cout << std::endl;

    list_int.deleteFromEnd();
    std::cout << "List elements after deleting from end: ";
    list_int.traverse(print_element);
    std::cout << std::endl;

    list_int.deleteFromPosition(1);
    std::cout << "List elements after deleting from position 1: ";
    list_int.traverse(print_element);
    std::cout << std::endl;

    std::cout << "List size: " << list_int.getSize() << std::endl;
    std::cout << "Is list empty? " << (list_int.isEmpty() ? "Yes" : "No") << std::endl;

    std::cout << "\nDemo with double type:" << std::endl;
    STRUCTS::LinkedList<double> list_double;
    list_double.insertAtEnd(1.1);
    list_double.insertAtEnd(2.2);
    list_double.insertAtEnd(3.3);
    list_double.insertAtBeginning(0.0);
    list_double.insertAtPosition(2, 4.4);

    std::cout << "List elements after insertions: ";
    list_double.traverse(print_element_double);
    std::cout << std::endl;

    list_double.map(increment_element_double);
    std::cout << "List elements after map (increment): ";
    list_double.traverse(print_element_double);
    std::cout << std::endl;

    std::cout << "\nDemo with std::string type:" << std::endl;
    STRUCTS::LinkedList<std::string> list_string;
    list_string.insertAtEnd("Hello");
    list_string.insertAtEnd("World");
    list_string.insertAtEnd("!");
    list_string.insertAtBeginning("Hi");
    list_string.insertAtPosition(2, "C++");

    std::cout << "List elements after insertions: ";
    list_string.traverse(print_element_string);
    std::cout << std::endl;

    list_string.map(append_string);
    std::cout << "List elements after map (append 'World'): ";
    list_string.traverse(print_element_string);
    std::cout << std::endl;

    std::cout << "\nDemo with custom Person struct:" << std::endl;
    STRUCTS::LinkedList<Person> list_person;
    list_person.insertAtEnd(Person{"Alice", 30});
    list_person.insertAtEnd(Person{"Bob", 25});
    list_person.insertAtEnd(Person{"Charlie", 35});
    list_person.insertAtBeginning(Person{"Diana", 28});
    list_person.insertAtPosition(2, Person{"Eve", 22});

    std::cout << "List elements after insertions: ";
    list_person.traverse(print_element_person);
    std::cout << std::endl;

    list_person.map(increment_person_age);
    std::cout << "List elements after map (increment age): ";
    list_person.traverse(print_element_person);
    std::cout << std::endl;

    return 0;
}
