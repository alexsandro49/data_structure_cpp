#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <algorithm>
#include "binary_search.cpp"

int main() {
    std::cout << std::setfill('=') << std::setw(22) << '\n';
    std::cout << std::string(4, ' ') << "BINARY SEARCH\n";
    std::cout << std::setfill('=') << std::setw(22) << '\n';

    int capacity;
    do
    {
        std::cout << "\nSet array capacity: ";
        std::cin >> capacity;

        if (capacity < 1) {
            std::cout << "\nInvalid capability! Please try again.\n";
        }
    } while (capacity < 1);
    
    std::vector<int> myVector;
    int option;

    while (true) {
        myVector.clear();
        std::cout << '\n' << std::setfill('=') << std::setw(22) << '\n';
        std::cout << "1 - Random values\n";
        std::cout << "2 - Choose values\n";
        std::cout << "0 - Close\n";
        std::cout << ": ";
        std::cin >> option;

        srandom(time(0));
        int value;

        switch (option) {
            case 1:
                for (int i = 0; i < capacity; i++) {
                    value = rand() % 1001;
                    myVector.push_back(value);
                }
                break;
            case 2:
                std::cout << '\n';
                for (int i = 0; i < capacity; i++) {
                    std::cout << "Set " << i+1 << "° value: ";
                    std::cin >> value;
                    myVector.push_back(value);
                }
                break;
            case 0:
                std::cout << "\nFinished program!\n";
                exit(0);
                break;
        default:
            std::cout << "\nInvalid option! Please try again.\n";
        }

        std::sort(myVector.begin(), myVector.end());
        
        std::cout << '\n' << myVector[0] << ' ';
        for (int i = 1; i < capacity; i++) {
            if (i > 0 && i % 5 == 0) {
                std::cout << "\n " << myVector[i] << " ";
            } else {
                std::cout << "| "<< myVector[i] << " ";
            }
        }
        std::cout << '\n';

        int target;
        std::cout << "\nChoose value to search: ";
        std::cin >> target;


        std::cout << '\n' << std::setfill('=') << std::setw(14) << '\n';
        std::cout << (binary_search(myVector, capacity, target) ? "Value found!\n" : "Value not found!\n");
        std::cout << std::setfill('=') << std::setw(14) << '\n';
    }

    return 0;
}