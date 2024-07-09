#include <iostream>
#include <string>
#include <DTypes.h>
#include <Structs.h>


namespace STRUCTS {

}




template <typename Stack>
void demoStack(Stack& stack) {
    std::cout << "Pushing elements: 1, 2, 3" << std::endl;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top element: " << stack.top() << std::endl;

    std::cout << "Popping top element." << std::endl;
    stack.pop();
    std::cout << "New top element: " << stack.top() << std::endl;

    std::cout << "Stack size: " << stack.getSize() << std::endl;
    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    std::cout << "Popping all elements." << std::endl;
    stack.pop();
    stack.pop();
    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;
}

template <typename Stack, typename T>
void demoStackGeneric(Stack& stack, const T& value1, const T& value2, const T& value3) {
    std::cout << "Pushing elements: " << value1 << ", " << value2 << ", " << value3 << std::endl;
    stack.push(value1);
    stack.push(value2);
    stack.push(value3);

    std::cout << "Top element: " << stack.top() << std::endl;

    std::cout << "Popping top element." << std::endl;
    stack.pop();
    std::cout << "New top element: " << stack.top() << std::endl;

    std::cout << "Stack size: " << stack.getSize() << std::endl;
    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    std::cout << "Popping all elements." << std::endl;
    stack.pop();
    stack.pop();
    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;
}

void demoArrayStack() {
    std::cout << "Testing ArrayStack<int>..." << std::endl;
    STRUCTS::ArrayStack<int> intArrayStack;
    demoStack(intArrayStack);

    std::cout << "\nTesting ArrayStack<std::string>..." << std::endl;
    STRUCTS::ArrayStack<std::string> stringArrayStack;
    demoStackGeneric(stringArrayStack, std::string("one"), std::string("two"), std::string("three"));

    std::cout << "\nTesting ArrayStack<Person>..." << std::endl;
    STRUCTS::ArrayStack<Person> personArrayStack;
    demoStackGeneric(personArrayStack, Person("Alice", 30), Person("Bob", 25), Person("Charlie", 35));
}

void demoLinkedListStack() {
    std::cout << "Testing LinkedListStack<int>..." << std::endl;
    STRUCTS::LinkedListStack<int> intLinkedListStack;
    demoStack(intLinkedListStack);

    std::cout << "\nTesting LinkedListStack<std::string>..." << std::endl;
    STRUCTS::LinkedListStack<std::string> stringLinkedListStack;
    demoStackGeneric(stringLinkedListStack, std::string("one"), std::string("two"), std::string("three"));

    std::cout << "\nTesting LinkedListStack<Person>..." << std::endl;
    STRUCTS::LinkedListStack<Person> personLinkedListStack;
    demoStackGeneric(personLinkedListStack, Person("Alice", 30), Person("Bob", 25), Person("Charlie", 35));
}

int main() {
    demoArrayStack();
    std::cout << std::endl;
    demoLinkedListStack();

    return 0;
}
