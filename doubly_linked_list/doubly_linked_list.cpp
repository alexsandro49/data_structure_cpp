#include "doubly_linked_list.h"

doubly_linked_list::doubly_linked_list() {
    this->size = 0;
    this->head = nullptr;
}

node* doubly_linked_list::getHead() {
    return head;
}

int doubly_linked_list::getSize() {
    return size;
}

void doubly_linked_list::push(int value, node* currentNode) {
    node* newNode = new node(value);

    if (head == nullptr) {
        head = newNode;
    } else {
        node* temp = currentNode->getNext();
        currentNode->setNext(newNode);
        currentNode->getNext()->setNext(temp);
        currentNode->getNext()->setPrevious(currentNode);
    }
    
    size++;
}

void doubly_linked_list::pop(node* nodeToRemove) {
    if (head == nullptr) {
        return;
    }

    if (head == nodeToRemove) {
        head = head->getNext();
        delete nodeToRemove;
    } else {
        node* previousNode = nullptr;
        node* currentNode = head;

        while (currentNode != nullptr && currentNode != nodeToRemove) {
            previousNode = currentNode;
            currentNode = currentNode->getNext();
        }

        if (currentNode == nullptr) {
            return;
        }

        previousNode->setNext(currentNode->getNext());
        delete currentNode;
    }

    size--;
}
