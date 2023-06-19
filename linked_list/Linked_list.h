#include "Node.h"

class Linked_list {
    private:
        int size;
        Node* head;
    public:
        Linked_list();

        Node* getHead();

        int getSize();

        void push(int value, Node* currentNode);

        void pop(Node* nodeToRemove);
};