#include "Student.h"

Student::Student(std::string name, int age, char gender) {
    this->name = name;
    this->id = generateId();
    this->age = age;
    this->gender = gender;
    this->next = nullptr;
}

int Student::generateId() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1000, 9999);

    int id = dis(gen);

    return id;
}

void Student::introduceYourself() {
    std::cout << "Id: " << id << '\n';
    std::cout << "Student: " << name << '\n';
    std::cout << "Age: " << age << '\n';
    std::cout << "Gender: " << gender << '\n';
}

std::string Student::getName() {
    return name;
}

int Student::getId() {
    return id;
}

int Student::getAge() {
    return age;
}

char Student::getGender() {
    return gender;
}

Student* Student::getNext() {
    return next;
}

void Student::setNext(Student* nextStudent) {
    next = nextStudent;
}