#include "node.h"

node::node(int value) {
    this->value = value;
    this->next = nullptr;
}

int node::getValue() {
    return value;
}

node* node::getNext() {
    return next;
}

node* node::getPrevious() {
    return previous;
}

void node::setNext(node* nextNode) {
    next = nextNode;
}

void node::setPrevious(node* previousNode) {
    previous = previousNode;
}
