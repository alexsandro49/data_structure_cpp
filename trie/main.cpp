#include <iostream>
#include <iomanip>
#include <limits>
#include <algorithm>
#include "Trie.h"

int main() {
    std::cout << std::setfill('=') << std::setw(21) << '\n';
    std::cout << std::string(8, ' ') << "TRIE\n";
    std::cout << std::setfill('=') << std::setw(21) << '\n';
    Trie myTrie;

    while(true) {
        int option;
        
        std::cout << '\n' << std::setfill('=') << std::setw(21) << '\n';
        std::cout << "1 - Add a new word\n";
        std::cout << "2 - Remove a word\n";
        std::cout << "3 - Do a search\n";
        std::cout << "4 - Show all words\n";
        std::cout << "0 - Close\n";
        std::cout << ": ";
        std::cin >> option;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


        std::string word;
        switch (option) {
            case 1:
                std::cout << "\nType word to add: ";
                std::getline(std::cin, word);
                std::transform(word.begin(), word.end(), word.begin(), ::toupper);
                myTrie.insert(word);
                break;
            case 2: 
                std::cout << "\nType word to remove: ";
                std::getline(std::cin, word);
                std::transform(word.begin(), word.end(), word.begin(), ::toupper);

                std::cout << '\n' << std::setfill('=') << std::setw(15) << '\n';
                std::cout << (myTrie.remove(word) ? "Word removed!\n" : "Word not removed!\n");
                std::cout << std::setfill('=') << std::setw(15) << '\n';
                break;
            case 3: {
                    std::cout << "\nType word to search: ";
                    std::getline(std::cin, word);
                    std::transform(word.begin(), word.end(), word.begin(), ::toupper);
                    std::vector<std::string> completions = myTrie.autoComplete(word);

                    std::cout << '\n' << std::setfill('=') << std::setw(15) << '\n';
                    for (int i = 0; i < completions.size(); i++) {
                        std::cout << completions[i] << '\n';
                    }
                    std::cout << std::setfill('=') << std::setw(15) << '\n';
                }
                break;
            case 4: {
                    std::vector<std::string> completions = myTrie.autoComplete("");

                    std::cout << '\n' << std::setfill('=') << std::setw(15) << '\n';
                    for (int i = 0; i < completions.size(); i++) {
                        std::cout << completions[i] << '\n';
                    }
                    std::cout << std::setfill('=') << std::setw(15) << '\n';
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
