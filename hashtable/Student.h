#include <iostream>
#include <random>

class Student {
    private:
        std::string name;
        int id;
        int age;
        char gender;
        Student* next;

        int generateId();
    public:
        Student(std::string name, int age, char gender);

        void introduceYourself();

        std::string getName();

        int getId();

        int getAge();

        char getGender();

        Student* getNext();

        void setNext(Student* nextStudent);        
};
