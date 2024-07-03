

#include "LinkedList/LinkedList.h"


namespace STRUCTS {
    LinkedList::LinkedList() : head(nullptr), size(0) {}

    LinkedList::~LinkedList() {
        clear();
    }

    void LinkedList::clear() {
        while (head != nullptr) {
            deleteFromBeginning();
        }
    }

    void LinkedList::insertAtBeginning(int value) {
        std::unique_ptr<Node> newNode = std::make_unique<Node>(value);
        newNode->next = std::move(head);
        head = std::move(newNode);
        ++size;
    } 

    void LinkedList::insertAtEnd(int value) {
        std::unique_ptr<Node> newNode = std::make_unique<Node>(value);
        if (head == nullptr) {
            head = std::move(newNode);
        } else {
            Node* temp = head.get();
            while (temp->next != nullptr) {
                temp = temp->next.get();
            }
            temp->next = std::move(newNode);
        }
        ++size;
    }


    void LinkedList::insertAtPosition(int position, int value) {
                if (position < 0 || position > size) {
            throw std::out_of_range("Insert Error: Position out of bounds.");
        }
        if (position == 0) {
            insertAtBeginning(value);
        } else {
            std::unique_ptr<Node> newNode = std::make_unique<Node>(value);
            Node* temp = head.get();
            for (int i = 1; i < position; ++i) {
                temp = temp->next.get();
            }
            newNode->next = std::move(temp->next);
            temp->next = std::move(newNode);
            ++size;
        }
    }

    void LinkedList::deleteFromBeginning() {
        if (head == nullptr) {
            throw std::out_of_range("Delete Error: List is empty.");
        }
        head = std::move(head->next);
        --size;
    }

    void LinkedList::deleteFromEnd() {
        if (head == nullptr) {
            throw std::out_of_range("Delete Error: List is empty.");
        }
        if (head->next == nullptr) {
            head = nullptr;
        } else {
            Node* temp = head.get();
            while (temp->next->next != nullptr) {
                temp = temp->next.get();
            }
            temp->next = nullptr;
        }
        --size;
    }

    void LinkedList::deleteFromPosition(int position) {
        if (position < 0 || position >= size) {
            throw std::out_of_range("Delete Error: Position out of bounds.");
        }
        if (position == 0) {
            deleteFromBeginning();
        } else {
            Node* temp = head.get();
            for (int i = 1; i < position; ++i) {
                temp = temp->next.get();
            }
            temp->next = std::move(temp->next->next);
            --size;
        }
    }

    void LinkedList::traverse(const std::function<void(int)>& func) const {
        Node* temp = head.get();
        while (temp != nullptr) {
            func(temp->data);
            temp = temp->next.get();
        }
    }

    bool LinkedList::search(int value) const {
        Node* temp = head.get();
        while (temp != nullptr) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next.get();
        }
        return false;
    }

    void LinkedList::update(int position, int value) {
        if (position < 0 || position >= size) {
            throw std::out_of_range("Update Error: Position out of bounds.");
        }
        Node* temp = head.get();
        for (int i = 0; i < position; ++i) {
            temp = temp->next.get();
        }
        temp->data = value;
    }

} 

