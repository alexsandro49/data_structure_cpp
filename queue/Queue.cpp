#include <iostream>
#include "Queue.h"

Queue::Queue(int value) {
    this->capacity = value;
    this->size = 0;
    this->elements = new int[capacity];
}

int Queue::getCapacity() {
    return capacity;
}

int Queue::getSize() {
    return size;
}

void Queue::push(int value, std::string* ptr) {
    if (size < capacity) {
        elements[size] = value;
        *ptr = "Item Added";
        size++;
    } else {
        *ptr = "The queue is full!";
    }
}

int Queue::pop(std::string* ptr) {
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

void Queue::show(std::string* ptr) {
    if (size > 0) {
        for (int i = 0; i < size; i++) {
            std::cout << elements[i] << ' ';
        }
        *ptr = "Displayed items";
    } else {
        *ptr = "The queue is empty!";
    }
}
