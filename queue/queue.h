#include <iostream>

class queue {
    private:
        int capacity, size;
        int* elements;

    public:
        queue(int value);

        ~queue();

        int getCapacity();

        int getSize();

        void push(int value, std::string* ptr);

        int pop(std::string* ptr);

        void show(std::string* ptr);
};
