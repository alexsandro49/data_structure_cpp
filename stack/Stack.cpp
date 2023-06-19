#include <iostream>
#include "Stack.h"

Stack::Stack(int value) {
    this->capacity = value;
    this->size = 0;
    this->elements = new int[capacity];
}

int Stack::getCapacity() {
    return capacity;
}

int Stack::getSize() {
    return size;
}

void Stack::push(int value, std::string* ptr) {
    if (size < capacity) {
        elements[size] = value;
        *ptr = "Item Added";
        size++;
    } else {
        *ptr = "The stack is full!";
    }
}

int Stack::pop(std::string* ptr) {
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

void Stack::show(std::string* ptr) {
    if (size > 0) {
        for (int i = 0; i < size; i++) {
            std::cout << elements[i] << ' ';
        }
        *ptr = "Displayed items";
    } else {
        *ptr = "The stack is empty!";
    }
}
