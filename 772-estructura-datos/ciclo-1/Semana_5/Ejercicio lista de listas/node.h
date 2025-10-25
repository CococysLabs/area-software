#include <iostream>

class node {
    private:
        class sub_node {
            private:
                char data;
                sub_node *next;

            public:
                sub_node(char data);

                char getData();
                sub_node* getNext();
                void setData(char data);
                void setNext(sub_node *next);
        };

        int index;
        node *next;
        node *prev;
        sub_node *list;

    public:
        node();
        node(int index);
        ~node();

        void append(char value);
        void print();

        int getIndex();
        node* getNext();
        node* getPrev();
        void setIndex(int index);
        void setNext(node *next);
        void setPrev(node *prev);
};