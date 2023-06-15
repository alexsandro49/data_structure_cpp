class node 
{
    private:
        int value;
        node* next;
    public:
        node(int value);

        int getValue();

        node* getNext();

        void setNext(node* nextnode);
};
