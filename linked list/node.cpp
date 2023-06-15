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

void node::setNext(node* nextnode) {
    next = nextnode;
}
