#include "Node.h"

Node::Node(int value) {
    this->value = value;
    this->next = nullptr;
}

void Node::setNext(Node* nextnode) {
    next = nextnode;
}

Node* Node::getNext() {
    return next;
}

int Node::getValue() {
    return value;
}
