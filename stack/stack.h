#include <iostream>

class stack {
    private:
        int capacity, size;
        int* elements;

    public:
        stack(int value);

        int getCapacity();

        int getSize();

        void push(int value, std::string* ptr);

        int pop(std::string* ptr);

        void show(std::string* ptr);
};
