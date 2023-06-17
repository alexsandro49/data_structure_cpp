#include "node.h"

class doubly_linked_list {
    private:
        int size;
        node* head;
    public:
        doubly_linked_list();

        node* getHead();

        int getSize();

        void push(int value, node* currentNode);

        void pop(node* nodeToRemove);
};