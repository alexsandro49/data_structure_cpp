#include <iostream>
#include "node.h"

class queue 
{
    private:
        int capacity, size;
        node* head;
    public:
        queue(int value);

        int getCapacity();

        int getSize();

        void push(int value, std::string* ptr);

        int pop(std::string* ptr);

        void show(std::string* ptr);
};
