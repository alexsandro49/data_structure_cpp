#include "Doubly_linked_list.h"

Doubly_linked_list::Doubly_linked_list() {
    this->size = 0;
    this->head = nullptr;
}

Node* Doubly_linked_list::getHead() {
    return head;
}

int Doubly_linked_list::getSize() {
    return size;
}

void Doubly_linked_list::push(int value, Node* currentNode) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = currentNode->getNext();
        currentNode->setNext(newNode);
        currentNode->getNext()->setNext(temp);
        currentNode->getNext()->setPrevious(currentNode);
    }
    
    size++;
}

void Doubly_linked_list::pop(Node* nodeToRemove) {
    if (head == nullptr) {
        return;
    }

    if (head == nodeToRemove) {
        head = head->getNext();
        delete nodeToRemove;
    } else {
        Node* previousNode = nullptr;
        Node* currentNode = head;

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
