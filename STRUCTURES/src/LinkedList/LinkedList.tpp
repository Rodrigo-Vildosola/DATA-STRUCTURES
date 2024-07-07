#include "LinkedList/LinkedList.h"

namespace STRUCTS {

    template <typename T>
    LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), size(0), cacheNode(nullptr), cachePosition(-1) {}

    template <typename T>
    LinkedList<T>::~LinkedList() {
        clear();
    }

    template <typename T>
    LinkedList<T>::LinkedList(const LinkedList& other) {
        copyFrom(other);
    }

    template <typename T>
    LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other) {
        if (this != &other) {
            clear();
            copyFrom(other);
        }
        return *this;
    }

    template <typename T>
    LinkedList<T>::LinkedList(LinkedList&& other) noexcept
        : head(std::move(other.head)), tail(other.tail), size(other.size), cacheNode(other.cacheNode), cachePosition(other.cachePosition) {
        other.tail = nullptr;
        other.cacheNode = nullptr;
        other.cachePosition = -1;
        other.size = 0;
    }

    template <typename T>
    LinkedList<T>& LinkedList<T>::operator=(LinkedList&& other) noexcept {
        if (this != &other) {
            clear();
            head = std::move(other.head);
            tail = other.tail;
            size = other.size;
            cacheNode = other.cacheNode;
            cachePosition = other.cachePosition;
            other.tail = nullptr;
            other.cacheNode = nullptr;
            other.cachePosition = -1;
            other.size = 0;
        }
        return *this;
    }

    template <typename T>
    void LinkedList<T>::clear() {
        while (head != nullptr) {
            deleteFromBeginning();
        }
        tail = nullptr;
        cacheNode = nullptr;
        cachePosition = -1;
    }

    template <typename T>
    void LinkedList<T>::insertAtBeginning(const T& value) {
        std::unique_ptr<Node<T>> newNode = std::make_unique<Node<T>>(value);
        newNode->next = std::move(head);
        if (newNode->next) {
            newNode->next->prev = newNode.get();
        }
        head = std::move(newNode);
        if (!tail) {
            tail = head.get();
        }
        ++size;
        cacheNode = head.get();
        cachePosition = 0;
    }

    template <typename T>
    void LinkedList<T>::insertAtEnd(const T& value) {
        std::unique_ptr<Node<T>> newNode = std::make_unique<Node<T>>(value);
        if (tail) {
            tail->next = std::move(newNode);
            tail->next->prev = tail;
            tail = tail->next.get();
        } else {
            head = std::move(newNode);
            tail = head.get();
        }
        ++size;
        cacheNode = tail;
        cachePosition = size - 1;
    }

    template <typename T>
    void LinkedList<T>::insertAtPosition(int position, const T& value) {
        if (position < 0 || position > size) {
            throw std::out_of_range("Insert Error: Position out of bounds.");
        }
        if (position == 0) {
            insertAtBeginning(value);
        } else if (position == size) {
            insertAtEnd(value);
        } else {
            Node<T>* temp = getNodeAtPosition(position - 1);
            std::unique_ptr<Node<T>> newNode = std::make_unique<Node<T>>(value);
            newNode->next = std::move(temp->next);
            if (newNode->next) {
                newNode->next->prev = newNode.get();
            }
            temp->next = std::move(newNode);
            temp->next->prev = temp;
            ++size;
            cacheNode = temp->next.get();
            cachePosition = position;
        }
    }

    template <typename T>
    void LinkedList<T>::deleteFromBeginning() {
        if (head == nullptr) {
            throw std::out_of_range("Delete Error: List is empty.");
        }
        head = std::move(head->next);
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        --size;
        cacheNode = head.get();
        cachePosition = 0;
    }

    template <typename T>
    void LinkedList<T>::deleteFromEnd() {
        if (tail == nullptr) {
            throw std::out_of_range("Delete Error: List is empty.");
        }
        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            head = nullptr;
            tail = nullptr;
        }
        --size;
        cacheNode = tail;
        cachePosition = size - 1;
    }

    template <typename T>
    void LinkedList<T>::deleteFromPosition(int position) {
        if (position < 0 || position >= size) {
            throw std::out_of_range("Delete Error: Position out of bounds.");
        }
        if (position == 0) {
            deleteFromBeginning();
        } else if (position == size - 1) {
            deleteFromEnd();
        } else {
            Node<T>* temp = getNodeAtPosition(position - 1);
            temp->next = std::move(temp->next->next);
            if (temp->next) {
                temp->next->prev = temp;
            }
            --size;
            cacheNode = temp;
            cachePosition = position - 1;
        }
    }

    template <typename T>
    void LinkedList<T>::traverse(const std::function<void(const T&)>& func) const {
        Node<T>* temp = head.get();
        while (temp != nullptr) {
            func(temp->data);
            temp = temp->next.get();
        }
    }

    template <typename T>
    void LinkedList<T>::map(const std::function<T(T)>& func) {
        Node<T>* temp = head.get();
        while (temp != nullptr) {
            temp->data = func(temp->data);
            temp = temp->next.get();
        }
    }

    template <typename T>
    bool LinkedList<T>::search(const T& value) const {
        Node<T>* temp = head.get();
        while (temp != nullptr) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next.get();
        }
        return false;
    }

    template <typename T>
    void LinkedList<T>::update(int position, const T& value) {
        if (position < 0 || position >= size) {
            throw std::out_of_range("Update Error: Position out of bounds.");
        }
        Node<T>* temp = getNodeAtPosition(position);
        temp->data = value;
    }

    template <typename T>
    void LinkedList<T>::copyFrom(const LinkedList& other) {
        Node<T>* temp = other.head.get();
        while (temp != nullptr) {
            insertAtEnd(temp->data);
            temp = temp->next.get();
        }
    }

    template <typename T>
    Node<T>* LinkedList<T>::getNodeAtPosition(int position) const {
        if (position < 0 || position >= size) {
            throw std::out_of_range("Position out of bounds.");
        }

        if (cacheNode && std::abs(cachePosition - position) <= position && std::abs(cachePosition - position) <= (size - position)) {
            // Use cache to optimize the search
            if (cachePosition <= position) {
                Node<T>* temp = cacheNode;
                for (int i = cachePosition; i < position; ++i) {
                    temp = temp->next.get();
                }
                cacheNode = temp;
                cachePosition = position;
                return temp;
            } else {
                Node<T>* temp = cacheNode;
                for (int i = cachePosition; i > position; --i) {
                    temp = temp->prev;
                }
                cacheNode = temp;
                cachePosition = position;
                return temp;
            }
        } else {
            // Normal search
            Node<T>* temp = head.get();
            for (int i = 0; i < position; ++i) {
                temp = temp->next.get();
            }
            cacheNode = temp;
            cachePosition = position;
            return temp;
        }
    }
}
