#include <iostream>
#include <vector>
#include <map>
#include "Node.h"

class Trie {
    private:
        void autoCompleteDFS(Node* node, std::string& currentWord, std::vector<std::string>& completions);
        Node* root;

    public:

        Trie();

        void insert(const std::string& word);

        bool remove(const std::string& word);

        bool search(const std::string& word);

        std::vector<std::string> autoComplete(const std::string& prefix);
};
