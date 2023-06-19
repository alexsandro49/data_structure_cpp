#include "Node.h"

Node::Node(int value) {
    this->value = value;
    this->next = nullptr;
}

int Node::getValue() {
    return value;
}

Node* Node::getNext() {
    return next;
}

void Node::setNext(Node* nextNode) {
    next = nextNode;
}
