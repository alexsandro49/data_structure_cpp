#include <iostream>
#include "Node.h"

class Queue 
{
    private:
        int capacity, size;
        Node* head;
    public:
        Queue(int value);

        int getCapacity();

        int getSize();

        void push(int value, std::string* ptr);

        int pop(std::string* ptr);

        void show(std::string* ptr);
};
