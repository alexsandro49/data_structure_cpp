#include <iostream>
#include <iomanip>
#include "doubly_linked_list.h"

int main()
{
    std::cout << std::setfill('=') << std::setw(22) << '\n';
    std::cout << std::string(5, ' ') << "LINKED LIST\n";
    std::cout << std::setfill('=') << std::setw(22) << '\n';

    doubly_linked_list myList;
    node* currentNode = myList.getHead();
    std::string currentValue, nextValue, previousValue;

    int option, position;
    bool reloadHead = true;

    while (true) {
        if (reloadHead) {
            currentNode = myList.getHead();
            (myList.getSize() == 0) ? position = 0 : position = 1;
            reloadHead = false;
        }

        if (currentNode == nullptr) {
            currentValue = "null";
            nextValue = "null";
            previousValue = "null";
        } else {
            currentValue = std::to_string(currentNode->getValue());
            if (currentNode->getNext() != nullptr) {
                nextValue = std::to_string(currentNode->getNext()->getValue());
            } else {
                nextValue = "null";
            }

            if (currentNode->getPrevious() != nullptr) {
                previousValue = std::to_string(currentNode->getPrevious()->getValue());
            } else {
                previousValue = "null";
            }
        }

        std::cout << '\n' << std::setfill('=') << std::setw(29) << '\n';
        std::cout << "Current value: " << currentValue << '\n';
        std::cout << "Next value: " << nextValue << '\n';
        std::cout << "Previous value: " << previousValue << '\n';
        std::cout << "List position: " << position << '\n';
        std::cout << "List size: " << myList.getSize() << '\n';
        std::cout << std::setfill('=') << std::setw(29) << '\n';
        std::cout << "Choose a option:\n";
        std::cout << "1 - Add element\n";
        std::cout << "2 - Remove element\n";
        std::cout << "3 - Next element\n";
        std::cout << "4 - Previous element\n";
        std::cout << "0 - Close\n";
        std::cout << ": ";
        std::cin >> option;

        switch (option) {
            case 1:
                int value;
                std::cout << "\nEnter an integer to add: ";
                std::cin >> value;
                myList.push(value, currentNode);
                reloadHead = true;
                break;
            case 2:
                myList.pop(currentNode);
                reloadHead = true;
                break;
            case 3:
                if (myList.getSize() > 1 && currentNode->getNext() != nullptr) {
                    currentNode = currentNode->getNext();
                    position++;
                } else {
                    reloadHead = true;
                }
                break;

            case 4:
                if (myList.getSize() > 1 && currentNode->getPrevious() != nullptr) {
                    currentNode = currentNode->getPrevious();
                    position--;
                } else {
                    reloadHead = true;
                }
                break;
            case 0:
                std::cout << "\nFinished program!\n";
                exit(0);
                break;
            default:
                std::cout << "\nInvalid option! Please try again.\n";
        }
    }

    return 0;
}
