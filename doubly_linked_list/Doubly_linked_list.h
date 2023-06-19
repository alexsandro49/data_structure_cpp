#include "Node.h"

class Doubly_linked_list {
    private:
        int size;
        Node* head;
    public:
        Doubly_linked_list();

        Node* getHead();

        int getSize();

        void push(int value, Node* currentNode);

        void pop(Node* nodeToRemove);
};