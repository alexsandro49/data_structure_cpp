class node 
{
    private:
        int value;
        node* next;
        node* previous;
    public:
        node(int value);

        int getValue();

        node* getNext();
        
        node* getPrevious();

        void setNext(node* nextNode);

        void setPrevious(node* previousNode);
};
