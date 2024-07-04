#include <iostream>

#include <Structs.h>


namespace STRUCTS {

}


void demoArrayStack() {
    std::cout << "Testing ArrayStack..." << std::endl;

    STRUCTS::ArrayStack arrayStack;

    std::cout << "Pushing elements: 1, 2, 3" << std::endl;
    arrayStack.push(1);
    arrayStack.push(2);
    arrayStack.push(3);

    std::cout << "Top element: " << arrayStack.top() << std::endl;

    std::cout << "Popping top element." << std::endl;
    arrayStack.pop();
    std::cout << "New top element: " << arrayStack.top() << std::endl;

    std::cout << "Stack size: " << arrayStack.getSize() << std::endl;
    std::cout << "Is stack empty? " << (arrayStack.isEmpty() ? "Yes" : "No") << std::endl;

    std::cout << "Popping all elements." << std::endl;
    arrayStack.pop();
    arrayStack.pop();
    std::cout << "Is stack empty? " << (arrayStack.isEmpty() ? "Yes" : "No") << std::endl;
}

void demoLinkedListStack() {
    std::cout << "Testing LinkedListStack..." << std::endl;

    STRUCTS::LinkedListStack linkedListStack;

    std::cout << "Pushing elements: 1, 2, 3" << std::endl;
    linkedListStack.push(1);
    linkedListStack.push(2);
    linkedListStack.push(3);

    std::cout << "Top element: " << linkedListStack.top() << std::endl;

    std::cout << "Popping top element." << std::endl;
    linkedListStack.pop();
    std::cout << "New top element: " << linkedListStack.top() << std::endl;

    std::cout << "Stack size: " << linkedListStack.getSize() << std::endl;
    std::cout << "Is stack empty? " << (linkedListStack.isEmpty() ? "Yes" : "No") << std::endl;

    std::cout << "Popping all elements." << std::endl;
    linkedListStack.pop();
    linkedListStack.pop();
    std::cout << "Is stack empty? " << (linkedListStack.isEmpty() ? "Yes" : "No") << std::endl;
}

int main() {
    demoArrayStack();
    std::cout << std::endl;
    demoLinkedListStack();

    return 0;
}
