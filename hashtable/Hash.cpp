#include "Hash.h"

Hash::Hash(int value) {
    bucketsAmount = value;
    for (int i = 0; i < value; i++) {
        Linked_list linked_list;
        buckets.push_back(linked_list);
    }
}

void Hash::insert(std::string name, int age, char gender) {
    Student* student = new Student(name, age, gender);

    int hashKey = student->getId() % bucketsAmount;
    buckets[hashKey].push(student);
}

void Hash::remove(int* key) {
    int hashKey = *key % bucketsAmount;
    bool removed;

    std::cout << '\n' << std::setfill('=') << std::setw(21) << '\n';
    if (!(buckets[hashKey].getHead() == nullptr)) {
        removed = buckets[hashKey].pop(*key);
    }
    if(!removed) {
        std::cout << "Invalid or non-existent id.\nNo student has been removed!\n";
    }
    std::cout << std::setfill('=') << std::setw(21) << '\n';
}

void Hash::showAll() {
    int counter = 0;
    std::cout << '\n' << std::setfill('=') << std::setw(11) << '\n';
    for (int i = 0; i < bucketsAmount; i++) {
        if (buckets[i].getHead() != nullptr) {
            std::vector<Student*> students = buckets[i].listAll();

            for (int j = 0; j < students.size(); j++) {
                if (counter > 0) {
                    std::cout << std::setfill('=') << std::setw(7) << '\n';
                }
                students[j]->introduceYourself();
                counter++;
            }
        }
    }
    std::cout << std::setfill('=') << std::setw(11) << '\n';
}

void Hash::showAll(int* key) {
    int counter = 0;
    int hashKey = *key % bucketsAmount;
    std::cout << '\n' << std::setfill('=') << std::setw(11) << '\n';
    if (!(buckets[hashKey].getHead() == nullptr)) {
        std::vector<Student*> students = buckets[hashKey].listAll(key);
        for (int j = 0; j < students.size(); j++) {
            if (counter > 0) {
                std::cout << std::setfill('=') << std::setw(7) << '\n';
            }
            students[j]->introduceYourself();
            counter++;
        }
    }
    std::cout << std::setfill('=') << std::setw(11) << '\n';
}

void Hash::showAll(std::string* name) {
    int counter = 0;
    std::cout << '\n' << std::setfill('=') << std::setw(11) << '\n';
    for (int i = 0; i < bucketsAmount; i++) {
        if (buckets[i].getHead() != nullptr) {
            std::vector<Student*> students = buckets[i].listAll(name);

            for (int j = 0; j < students.size(); j++) {
                if (counter > 0) {
                    std::cout << std::setfill('=') << std::setw(7) << '\n';
                }
                students[j]->introduceYourself();
                counter++;
            }
        }
    }
    std::cout << std::setfill('=') << std::setw(11) << '\n';
}
