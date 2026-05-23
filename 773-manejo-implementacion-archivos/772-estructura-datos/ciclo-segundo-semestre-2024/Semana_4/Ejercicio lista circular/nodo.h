#include <iostream>
#include <fstream>

class Nodo{
    private:
        int data;
        Nodo *sig;

    public:
        Nodo(int data);

        void setData(int valor);
        void setSig(Nodo* sig);
        int getData();
        Nodo* getSig();

};