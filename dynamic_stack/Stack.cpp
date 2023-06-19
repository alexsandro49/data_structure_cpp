#include <iostream>
#include "Stack.h"

Stack::Stack(int value) {
    this->capacity = value;
    this->size = 0;
    this->head = nullptr;
}

int Stack::getCapacity() {
    return capacity;
}

int Stack::getSize() {
    return size;
}

void Stack::push(int value, std::string* ptr) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        *ptr = "Item Added";
    } else {
        if (size == capacity) {
            *ptr = "The stack is full!";
        } else {
            Node* current = head;
            
            while (current->getNext() != nullptr) {
                current = current->getNext();
            }
            current->setNext(newNode);
            *ptr = "Item Added";
        }
    }

    size++;
}

int Stack::pop(std::string* ptr) {
    int value;

    if (head == nullptr) {
        *ptr = "The stack is empty!";
        size = 0;
        return -1;
    }

    if (head->getNext() == nullptr) {
        value = head->getValue();
        delete head;
        head = nullptr;
    } else {
        Node* current = head;
        while (current->getNext()->getNext() != nullptr) {
            current = current->getNext();
        }

        value = current->getNext()->getValue();
        delete current->getNext();
        current->setNext(nullptr);
    }

    size--;
    *ptr = "Item removed!";
    return value;
}

void Stack::show(std::string* ptr) {
    Node* current = head;

    if (size > 0) {
        while (current != nullptr) {
            std::cout << current->getValue() << ' ';
            current = current->getNext();
        }
        *ptr = "Displayed items";
    } else {
        *ptr = "The stack is empty!";
    }
}
