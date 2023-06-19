#include <iostream>
#include "Node.h"

class Stack 
{
    private:
        int capacity, size;
        Node* head;
    public:
        Stack(int value);

        int getCapacity();

        int getSize();

        void push(int value, std::string* ptr);

        int pop(std::string* ptr);

        void show(std::string* ptr);
};
