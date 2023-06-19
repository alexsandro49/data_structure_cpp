#include <iostream>
#include "Queue.h"

Queue::Queue(int value) {
    this->capacity = value;
    this->size = 0;
    this->head = nullptr;
}

int Queue::getCapacity() {
    return capacity;
}

int Queue::getSize() {
    return size;
}

void Queue::push(int value, std::string* ptr) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        *ptr = "Item Added";
    } else {
        if (size == capacity) {
            *ptr = "The queue is full!";
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

int Queue::pop(std::string* ptr) {
    int value;

    if (head == nullptr) {
        *ptr = "The queue is empty!";
        size = 0;
        return -1;
    }

    if (head->getNext() == nullptr) {
        value = head->getValue();
        delete head;
        head = nullptr;
    } else {
        Node* current = head;
        
        value = head->getValue();
        head = current->getNext();
    }

    size--;
    *ptr = "Item removed!";
    return value;
}

void Queue::show(std::string* ptr) {
    Node* current = head;

    if (size > 0) {
        while (current != nullptr) {
            std::cout << current->getValue() << ' ';
            current = current->getNext();
        }
        *ptr = "Displayed items";
    } else {
        *ptr = "The queue is empty!";
    }
}
