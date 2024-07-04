#include <iostream>

#include <Structs.h>


namespace STRUCTS {

}


void demoArrayQueue() {
    std::cout << "Testing ArrayQueue..." << std::endl;

    STRUCTS::ArrayQueue queue;

    std::cout << "Enqueueing elements: 1, 2, 3" << std::endl;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << "Front element: " << queue.front() << std::endl;

    std::cout << "Dequeueing front element." << std::endl;
    queue.dequeue();
    std::cout << "New front element: " << queue.front() << std::endl;

    std::cout << "Queue size: " << queue.getSize() << std::endl;
    std::cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << std::endl;

    std::cout << "Dequeueing all elements." << std::endl;
    queue.dequeue();
    queue.dequeue();
    std::cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << std::endl;
}

void demoLinkedListQueue() {
    std::cout << "Testing LinkedListQueue..." << std::endl;

    STRUCTS::LinkedListQueue queue;

    std::cout << "Enqueueing elements: 1, 2, 3" << std::endl;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << "Front element: " << queue.front() << std::endl;

    std::cout << "Dequeueing front element." << std::endl;
    queue.dequeue();
    std::cout << "New front element: " << queue.front() << std::endl;

    std::cout << "Queue size: " << queue.getSize() << std::endl;
    std::cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << std::endl;

    std::cout << "Dequeueing all elements." << std::endl;
    queue.dequeue();
    queue.dequeue();
    std::cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << std::endl;
}


int main() {
    demoArrayQueue();
    std::cout << std::endl;
    demoLinkedListQueue();

    return 0;
}
