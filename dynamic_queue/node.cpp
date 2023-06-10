#include "node.h"

node::node(int value) {
    this->value = value;
    this->next = nullptr;
}

void node::setNext(node* nextnode) {
    next = nextnode;
}

node* node::getNext() {
    return next;
}

int node::getValue() {
    return value;
}
