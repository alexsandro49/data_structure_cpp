#include "Student.h"

class Linked_list {
    private:
        Student* head;
    public:
        Linked_list();

        Student* getHead();

        void push(Student* currentStudent);

        bool pop(int idToRemove);

        std::vector<Student*> listAll();

        std::vector<Student*> listAll(int* key);

        std::vector<Student*> listAll(std::string* name);
};