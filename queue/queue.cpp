#include <iostream>
#include "queue.h"

queue::queue(int value) {
    this->capacity = value;
    this->size = 0;
    this->elements = new int[capacity];
}

queue::~queue() {
    delete[] elements;
}

int queue::getCapacity() {
    return capacity;
}

int queue::getSize() {
    return size;
}

void queue::push(int value, std::string* ptr) {
    if (size < capacity) {
        elements[size] = value;
        *ptr = "Item Added";
        size++;
    } else {
        *ptr = "The queue is full!";
    }
}

int queue::pop(std::string* ptr) {
    int value;
    int x[size];

    if (size > 0) {
        value = elements[0];

        for (int i = 1; i < size; i++) {
            x[i-1] = elements[i];
        }
        size--;
        
        for (int i = 0; i < size; i++) {
            elements[i] = x[i];
        }

        *ptr = "Item removed!";
    } else {
        *ptr = "The queue is empty!";
        value = -1;
    }

    return value;
}

void queue::show(std::string* ptr) {
    if (size > 0) {
        for (int i = 0; i < size; i++) {
            std::cout << elements[i] << ' ';
        }
        *ptr = "Displayed items";
    } else {
        *ptr = "The queue is empty!";
    }
}
