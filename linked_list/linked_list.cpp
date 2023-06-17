#include "linked_list.h"

linked_list::linked_list() {
    this->size = 0;
    this->head = nullptr;
}

node* linked_list::getHead() {
    return head;
}

int linked_list::getSize() {
    return size;
}

void linked_list::push(int value, node* currentNode) {
    node* newNode = new node(value);

    if (head == nullptr) {
        head = newNode;
    } else {
        node* temp = currentNode->getNext();
        currentNode->setNext(newNode);
        currentNode->getNext()->setNext(temp);
    }
    
    size++;
}

void linked_list::pop(node* nodeToRemove) {
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
