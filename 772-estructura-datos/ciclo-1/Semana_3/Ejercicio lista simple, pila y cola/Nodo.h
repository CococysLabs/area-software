#include <iostream>

class Nodo {
    private:
        int data;
        Nodo *sig;

    public:
        Nodo();
        Nodo(int data);

        void setData(int valor);
        void setSig(Nodo* sig);
        int getData();
        Nodo* getSig();
};