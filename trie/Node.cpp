#include "Node.h"

Node::Node() {
    isEndOfWord = false;
}

std::map<char, Node*>& Node::getChildren() {
    return children;
}

bool Node::getIsEndOfWord() {
    return isEndOfWord;
}

void Node::setChildren(char letter) {
    children[letter] = new Node();
}

void Node::setIsEndOfWord(bool value) {
    isEndOfWord = value;
}
