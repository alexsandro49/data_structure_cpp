#include <iostream>
#include <iomanip>
#include "queue.h"

void menu(int value);

int main()
{
    int capacity;

    std::cout << std::setfill('=') << std::setw(29) << '\n';
    std::cout << std::string(12, ' ') << "QUEUE\n";
    std::cout << std::setfill('=') << std::setw(29) << '\n';

    do
    {
        std::cout << "\nSet the queue capacity: ";
        std::cin >> capacity;

        if (capacity < 1) {
            std::cout << "\nInvalid capability! Please try again.\n";
        }
    } while (capacity < 1);

    menu(capacity);

    return 0;
}

void menu(int value) {
    int option;
    std::string status = "----";
    std::string* statusPtr = &status;
    queue myQueue(value);

    while (true) {
        std::cout << std::endl << std::setfill('=') << std::setw(29) << '\n';
        std::cout << "Last status: " << status << std::endl;
        std::cout << "Queue capacity: " << myQueue.getCapacity() << std::endl;
        std::cout << "Size: " << myQueue.getSize() << std::endl;
        std::cout << std::setfill('=') << std::setw(29) << '\n';
        std::cout << "Choose a option:\n";
        std::cout << "1 - Add element\n";
        std::cout << "2 - Remove element\n";
        std::cout << "3 - Show elements\n";
        std::cout << "0 - Close\n";
        std::cout << ": ";
        std::cin >> option;

        switch (option) {
            case 1:
                int value;
                std::cout << "\nEnter an integer to add: ";
                std::cin >> value;
                myQueue.push(value, statusPtr);
                break;
            case 2:
                std::cout << "\nItem removed: " << myQueue.pop(statusPtr) << std::endl;
                break;
            case 3:
                std::cout << std::endl << std::setfill('-') << std::setw(29) << '\n';
                myQueue.show(statusPtr);
                std::cout << std::endl << std::setfill('-') << std::setw(29) << '\n';
                break;
            case 0:
                std::cout << "\nFinished program!\n";
                exit(0);
                break;
            default:
                std::cout << "\nInvalid option! Please try again.\n";
        }
    }
}
