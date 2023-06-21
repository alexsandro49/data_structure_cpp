#include <string>
#include <limits>
#include <algorithm>
#include "Hash.h"

std::string removeExtraEspaces(std::string word);

int main()
{
    int capacity;

    std::cout << std::setfill('=') << std::setw(22) << '\n';
    std::cout << std::string(6, ' ') << "HASHTABLE\n";
    std::cout << std::setfill('=') << std::setw(22) << '\n';

    std::cout << '\n' <<std::setfill('=') << std::setw(22) << '\n';
    do
    {
        std::cout << "Set the amount of buckets: \n: ";
        std::cin >> capacity;

        if (capacity < 1) {
            std::cout << "\nInvalid capability! Please try again.\n";
        }
    } while (capacity < 1);

    Hash myHash(capacity);

    int option;
    while (true) {
        std::cout << '\n' << std::setfill('=') << std::setw(22) << '\n';
        std::cout << "1 - Add a student\n";
        std::cout << "2 - Remove a student\n";
        std::cout << "3 - Do a search\n";
        std::cout << "4 - Show all data\n";
        std::cout << "0 - Close \n: ";
        std::cin >> option;

        switch (option) {
            case 1: {
                    std::string name;
                    int age;
                    int genderSelect;

                    std::cout << "\nName: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, name);

                    name = removeExtraEspaces(name);
                    std::transform(name.begin(), name.end(), name.begin(), ::toupper);

                    std::cout << "Age: ";
                    std::cin >> age;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    
                    do {
                        std::cout << "Gender:\n";
                        std::cout << "1 - M\n";
                        std::cout << "0 - F \n: ";
                        std::cin >> genderSelect;

                        switch (genderSelect) {
                            case 1:
                                myHash.insert(name, age, 'M');
                                break;
                            case 0:
                                myHash.insert(name, age, 'F');
                                break;
                            default:
                                std::cout << "\nInvalid option! Please try again.\n" << '\n';
                        }
                    } while (genderSelect < 0 || genderSelect > 1);
                }
                break;
            case 2: {
                    int id;
                    do {
                        std::cout << "\nId (xxxx): ";
                        std::cin >> id;
                        if (id < 0 || id > 9999) {
                            std::cout << "\nInvalid id! Please try again.\n"; 
                        }
                    } while (id < 0 || id > 9999);

                    myHash.remove(&id);
                }
                break;
            case 3:
                int search;
                std::cout << '\n' << std::setfill('=') << std::setw(22) << '\n';
                std::cout << "1 - Search by id\n";
                std::cout << "2 - Search by name \n: ";
                std::cin >> search;

                switch (search) {
                    case 1: {
                            int id;
                            do {
                                std::cout << "\nId (xxxx): ";
                                std::cin >> id;
                                if (id < 0 || id > 9999) {
                                   std::cout << "\nInvalid id! Please try again.\n"; 
                                }
                            } while (id < 0 || id > 9999);

                            myHash.showAll(&id);
                        }
                        break;
                    case 2: {
                            std::string name;
                            std::cout << "\nName: ";
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::getline(std::cin, name);
                            name = removeExtraEspaces(name);
                            std::transform(name.begin(), name.end(), name.begin(), ::toupper);

                            myHash.showAll(&name);
                        }
                        break;
                    default:
                        std::cout << "\nInvalid option! Please try again.\n" << '\n';
                }
                break;
            case 4:
                myHash.showAll();
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

std::string removeExtraEspaces(std::string word) {
    auto newEnd = std::unique(word.begin(), word.end(), [](char a, char b) {
        return std::isspace(a) && std::isspace(b);
    });
    word.erase(newEnd, word.end());

    if (word[0] == ' ') {
        word.erase(0, 1);
    }
    
    if (word[word.size()-1] == ' ') {
        word.pop_back();
    }

    return word;
}
