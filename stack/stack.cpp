#include <iostream>
#include "stack.h"

stack::stack(int value) {
    this->capacity = value;
    this->size = 0;
    this->elements = new int[capacity];
}

stack::~stack() {
    delete[] elements;
}

int stack::getCapacity() {
    return capacity;
}

int stack::getSize() {
    return size;
}

void stack::push(int value, std::string* ptr) {
    if (size < capacity) {
        elements[size] = value;
        *ptr = "Item Added";
        size++;
    } else {
        *ptr = "The stack is full!";
    }
}

int stack::pop(std::string* ptr) {
    int value;

    if (size > 0) {
        size--;
        value = elements[size];
        *ptr = "Item removed!";
    } else {
        *ptr = "The stack is empty!";
        value = -1;
    }

    return value;
}

void stack::show(std::string* ptr) {
    if (size > 0) {
        for (int i = 0; i < size; i++) {
            std::cout << elements[i] << ' ';
        }
        *ptr = "Displayed items";
    } else {
        *ptr = "The stack is empty!";
    }
}
