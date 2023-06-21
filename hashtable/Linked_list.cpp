#include "Linked_list.h"

Linked_list::Linked_list() {
    this->head = nullptr;
}

Student* Linked_list::getHead() {
    return head;
}

void Linked_list::push(Student* currentStudent) {
    if (head == nullptr) {
        head = currentStudent;
    } else {
        Student* current = head;
            
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(currentStudent);
    }
}

bool Linked_list::pop(int idToRemove) {
    if (head == nullptr) {
        return false;
    }

    if (head->getId() == idToRemove) {
        head->introduceYourself();
        head = head->getNext();
        return true;
    } else {
        Student* previousStudent = nullptr;
        Student* currentStudent = head;

        while (currentStudent != nullptr && currentStudent->getId() != idToRemove) {
            previousStudent = currentStudent;
            currentStudent = currentStudent->getNext();
        }

        if (currentStudent == nullptr) {
            return false;
        }

        currentStudent->introduceYourself();
        previousStudent->setNext(currentStudent->getNext());
        delete currentStudent;
        return true;
    }
}

std::vector<Student*> Linked_list::listAll() {
    Student* current = head;
    std::vector<Student*> students;

    while (current->getNext() != nullptr) {
        students.push_back(current);
        current = current->getNext();
    }
    students.push_back(current);

    return students;
}

std::vector<Student*> Linked_list::listAll(int* key) {
    Student* current = head;
    std::vector<Student*> students;

    while (current->getNext() != nullptr) {
        if (current->getId() == *key) {
            students.push_back(current);
        }
        current = current->getNext();
    }
    students.push_back(current);

    return students;
}

std::vector<Student*> Linked_list::listAll(std::string* name) {
    Student* current = head;
    std::vector<Student*> students;

    while (current->getNext() != nullptr) {
        if (current->getName().find(*name) != std::string::npos) {
            students.push_back(current);
        }
        current = current->getNext();
    }
    students.push_back(current);

    return students;
}
