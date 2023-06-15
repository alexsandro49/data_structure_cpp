#include "node.h"

class linked_list {
    private:
        int size;
        node* head;
    public:
        linked_list();

        node* getHead();

        int getSize();

        void push(int value, node* currentNode);

        void pop(node* nodeToRemove);
};