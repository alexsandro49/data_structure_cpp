#include "Trie.h"

Trie::Trie() {
    root = new Node();
}

void Trie::insert(const std::string& word) {
    Node* current = root;

    for (char letter : word) {
        if (current->getChildren().find(letter) == current->getChildren().end()) {
            current->setChildren(letter);
        }
        current = current->getChildren()[letter];
    }

    current->setIsEndOfWord(true);
}

bool Trie::remove(const std::string& word) {
    Node* current = root;
    std::vector<Node*> path;

    for (char letter : word) {
        if (current->getChildren().find(letter) == current->getChildren().end()) {
            return false;
        }
        path.push_back(current);
        current = current->getChildren()[letter];
    }
    
    if (!current->getIsEndOfWord()) {
        return false;
    }

    current->setIsEndOfWord(false);

    if (current->getChildren().empty()) {
        for (int i = path.size() - 1; i >= 0; i--) {
            Node* parent = path[i];
            parent->getChildren().erase(word[i]);
            if (!parent->getIsEndOfWord() && parent->getChildren().empty()) {
                delete parent;
                path.pop_back();
            } else {
                break;
            }
        }
    }

    return true;
}

bool Trie::search(const std::string& word) {
    Node* current = root;

    for (char letter : word) {
        if (current->getChildren().find(letter) == current->getChildren().end()) {
            return false;
        }
        current = current->getChildren()[letter];
    }

    return current->getIsEndOfWord();
}

void Trie::autoCompleteDFS(Node* node, std::string& currentWord, std::vector<std::string>& completions) {
    if (node->getIsEndOfWord()) {
        completions.push_back(currentWord);
    }

    std::map<char, Node*>& children = node->getChildren();
    for (auto& pair : children) {
        char letter = pair.first;
        Node* child = pair.second;

        currentWord.push_back(letter);
        autoCompleteDFS(child, currentWord, completions);
        currentWord.pop_back();
    }
}


std::vector<std::string> Trie::autoComplete(const std::string& prefix) {
    Node* current = root;

    for (char letter : prefix) {
        std::map<char, Node*>& children = current->getChildren();

        if (children.find(letter) == children.end()) {
            return {};
        }

        current = children[letter];
    }

    std::vector<std::string> completions;
    std::string currentWord = prefix;
    autoCompleteDFS(current, currentWord, completions);

    return completions;
}
