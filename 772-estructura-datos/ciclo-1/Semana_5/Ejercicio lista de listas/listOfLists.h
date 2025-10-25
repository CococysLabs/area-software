#include "node.h"

class listOfLists {
    private:
        node *head;
        node *tail;

    public:
        listOfLists();
        ~listOfLists();
        
        void insert(int index, char value);
        void print();
};