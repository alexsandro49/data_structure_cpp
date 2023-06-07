class node 
{
    private:
        int value;
        node* next;
    public:
        node(int value);

        void setNext(node* nextnode);

        node* getNext();

        int getValue();
};
