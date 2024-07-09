#include <iostream>
#include <string>
#include <DTypes.h>
#include <Structs.h>

namespace STRUCTS {

}

template <typename Queue>
void demoQueue(Queue& queue) {
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

template <typename Queue, typename T>
void demoQueueGeneric(Queue& queue, const T& value1, const T& value2, const T& value3) {
    std::cout << "Enqueueing elements: " << value1 << ", " << value2 << ", " << value3 << std::endl;
    queue.enqueue(value1);
    queue.enqueue(value2);
    queue.enqueue(value3);

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

void demoArrayQueue() {
    std::cout << "Testing ArrayQueue<int>..." << std::endl;
    STRUCTS::ArrayQueue<int> intArrayQueue;
    demoQueue(intArrayQueue);

    std::cout << "\nTesting ArrayQueue<std::string>..." << std::endl;
    STRUCTS::ArrayQueue<std::string> stringArrayQueue;
    demoQueueGeneric(stringArrayQueue, std::string("one"), std::string("two"), std::string("three"));

    std::cout << "\nTesting ArrayQueue<Person>..." << std::endl;
    STRUCTS::ArrayQueue<Person> personArrayQueue;
    demoQueueGeneric(personArrayQueue, Person("Alice", 30), Person("Bob", 25), Person("Charlie", 35));
}

void demoLinkedListQueue() {
    std::cout << "Testing LinkedListQueue<int>..." << std::endl;
    STRUCTS::LinkedListQueue<int> intLinkedListQueue;
    demoQueue(intLinkedListQueue);

    std::cout << "\nTesting LinkedListQueue<std::string>..." << std::endl;
    STRUCTS::LinkedListQueue<std::string> stringLinkedListQueue;
    demoQueueGeneric(stringLinkedListQueue, std::string("one"), std::string("two"), std::string("three"));

    std::cout << "\nTesting LinkedListQueue<Person>..." << std::endl;
    STRUCTS::LinkedListQueue<Person> personLinkedListQueue;
    demoQueueGeneric(personLinkedListQueue, Person("Alice", 30), Person("Bob", 25), Person("Charlie", 35));
}

int main() {
    demoArrayQueue();
    std::cout << std::endl;
    demoLinkedListQueue();

    return 0;
}
