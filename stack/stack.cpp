#include <iostream>
#include "stack.h"

stack::stack(int value) {
    this->capacity = value;
    this->size = 0;
    this->head = nullptr;
}

stack::~stack() {
    node* current = head;

    while (current != nullptr) {
        node* nextNode = current->getNext();
        delete current;
        current = nextNode;
    }
}

int stack::getCapacity() {
    return capacity;
}

int stack::getSize() {
    return size;
}

void stack::push(int value, std::string* ptr) {
    node* newNode = new node(value);

    if (head == nullptr) {
        head = newNode;
        *ptr = "Item Added";
    } else {
        if (size == capacity) {
            *ptr = "The stack is full!";
        } else {
            node* current = head;

            while (current->getNext() != nullptr) {
                current = current->getNext();
            }
            current->setNext(newNode);
            *ptr = "Item Added";
        }
    }

    size++;
}

int stack::pop(std::string* ptr) {
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
        node* current = head;
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

void stack::show(std::string* ptr) {
    node* current = head;

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
