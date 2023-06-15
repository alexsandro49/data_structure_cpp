#include <iostream>
#include "queue.h"

queue::queue(int value) {
    this->capacity = value;
    this->size = 0;
    this->head = nullptr;
}

int queue::getCapacity() {
    return capacity;
}

int queue::getSize() {
    return size;
}

void queue::push(int value, std::string* ptr) {
    node* newNode = new node(value);

    if (head == nullptr) {
        head = newNode;
        *ptr = "Item Added";
    } else {
        if (size == capacity) {
            *ptr = "The queue is full!";
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

int queue::pop(std::string* ptr) {
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
        node* current = head;

        value = head->getValue();
        head = current->getNext();
    }

    size--;
    *ptr = "Item removed!";
    return value;
}

void queue::show(std::string* ptr) {
    node* current = head;

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
