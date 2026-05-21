#include "nodo.h"

class ListaCircular{
    private:
        int largo;
        Nodo *primero;

    public:
        ListaCircular();
        ~ListaCircular();

        void push(int data);
        void append(int data);
        void print();
        void graph();
};