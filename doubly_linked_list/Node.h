class Node 
{
    private:
        int value;
        Node* next;
        Node* previous;
    public:
        Node(int value);

        int getValue();

        Node* getNext();
        
        Node* getPrevious();

        void setNext(Node* nextNode);

        void setPrevious(Node* previousNode);
};
