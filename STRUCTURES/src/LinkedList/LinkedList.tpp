#include "LinkedList/LinkedList.h"

namespace STRUCTS {

    template <typename T>
    LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

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
        : head(std::move(other.head)), tail(other.tail), size(other.size) {
        other.tail = nullptr;
        other.size = 0;
    }

    template <typename T>
    LinkedList<T>& LinkedList<T>::operator=(LinkedList&& other) noexcept {
        if (this != &other) {
            clear();
            head = std::move(other.head);
            tail = other.tail;
            size = other.size;
            other.tail = nullptr;
            other.size = 0;
        }
        return *this;
    }

    template <typename T>
    void LinkedList<T>::clear() {
        while (head != nullptr) {
            deleteFromBeginning();
        }
    }

    template <typename T>
    void LinkedList<T>::insertAtBeginning(const T& value) {
        std::unique_ptr<Node<T>> newNode = std::make_unique<Node<T>>(value);
        newNode->next = std::move(head);
        if (newNode->next) {
            newNode->next->prev = newNode.get();
        }
        head = std::move(newNode);
        if (tail == nullptr) {
            tail = head.get();
        }
        ++size;
    }

    template <typename T>
    void LinkedList<T>::insertAtEnd(const T& value) {
        std::unique_ptr<Node<T>> newNode = std::make_unique<Node<T>>(value);
        newNode->prev = tail;
        if (tail) {
            tail->next = std::move(newNode);
            tail = tail->next.get();
        } else {
            head = std::move(newNode);
            tail = head.get();
        }
        ++size;
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
            std::unique_ptr<Node<T>> newNode = std::make_unique<Node<T>>(value);
            Node<T>* temp = head.get();
            for (int i = 1; i < position; ++i) {
                temp = temp->next.get();
            }
            newNode->next = std::move(temp->next);
            if (newNode->next) {
                newNode->next->prev = newNode.get();
            }
            temp->next = std::move(newNode);
            temp->next->prev = temp;
            ++size;
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
    }

    template <typename T>
    void LinkedList<T>::deleteFromEnd() {
        if (tail == nullptr) {
            throw std::out_of_range("Delete Error: List is empty.");
        }
        if (tail->prev) {
            tail = tail->prev;
            tail->next.reset();
        } else {
            head.reset();
            tail = nullptr;
        }
        --size;
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
            Node<T>* temp = head.get();
            for (int i = 0; i < position; ++i) {
                temp = temp->next.get();
            }
            temp->next = std::move(temp->next->next);
            if (temp->next) {
                temp->next->prev = temp;
            }
            --size;
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
        Node<T>* temp = head.get();
        for (int i = 0; i < position; ++i) {
            temp = temp->next.get();
        }
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

} // namespace STRUCTS
