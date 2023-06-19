class Node 
{
    private:
        int value;
        Node* next;
    public:
        Node(int value);

        void setNext(Node* nextnode);

        Node* getNext();

        int getValue();
};
