#include <map>

class Node {
    private:
        std::map<char, Node*> children;
        bool isEndOfWord;
    public:
        Node();

        std::map<char, Node*>& getChildren();

        bool getIsEndOfWord();

        void setChildren(char letter);

        void setIsEndOfWord(bool value);
};
