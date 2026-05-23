#include "nodo.h"

class ListaDoblementeEnlazada{
    private:
        Nodo *primero;
        Nodo *ultimo;

    public:
        ListaDoblementeEnlazada();
        ~ListaDoblementeEnlazada();

        void push(int data);
        void append(int data);
        void insert(int index, int value);
        void print();
        void revPrint();
        void graph();
};