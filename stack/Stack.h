#include <iostream>

class Stack {
    private:
        int capacity, size;
        int* elements;

    public:
        Stack(int value);

        int getCapacity();

        int getSize();

        void push(int value, std::string* ptr);

        int pop(std::string* ptr);

        void show(std::string* ptr);
};
