class Node 
{
    private:
        int value;
        Node* next;
    public:
        Node(int value);

        int getValue();

        Node* getNext();

        void setNext(Node* nextNode);
};
