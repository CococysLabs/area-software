#include <iostream>

class Nodo{
    private:
        int data;
        Nodo *prev;
        Nodo *sig;

    public:
        Nodo(int data);

        void setData(int valor);
        void setSig(Nodo* sig);
        void setPrev(Nodo *prev);

        int getData();
        Nodo* getPrev();   
        Nodo* getSig();    
};
