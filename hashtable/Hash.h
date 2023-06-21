#include <iomanip>
#include "Linked_list.h"

class Hash {
    private:
        int bucketsAmount;
        std::vector<Linked_list> buckets;
    public:
        Hash(int value);

        void insert(std::string name, int age, char gender);

        void remove(int* key);

        void showAll();

        void showAll(int* key);

        void showAll(std::string* name);
};
