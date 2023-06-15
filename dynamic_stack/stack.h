#include <iostream>
#include "node.h"

class stack 
{
    private:
        int capacity, size;
        node* head;
    public:
        stack(int value);

        int getCapacity();

        int getSize();

        void push(int value, std::string* ptr);

        int pop(std::string* ptr);

        void show(std::string* ptr);
};
