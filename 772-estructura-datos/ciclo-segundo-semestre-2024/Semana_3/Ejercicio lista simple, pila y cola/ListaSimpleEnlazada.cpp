#include "ListaSimpleEnlazada.h"

listaSimpleEnlazada::listaSimpleEnlazada(){
    primero = nullptr;
    ultimo = nullptr;
}

listaSimpleEnlazada::~listaSimpleEnlazada(){
    Nodo *temp = primero;
    Nodo *aux;

    while(temp != nullptr){
        aux = temp->getSig();
        delete temp;
        temp = aux;
    }
}

int listaSimpleEnlazada::pop(){
    Nodo *temp;
    int ret;

    if(primero == nullptr){return -999;}

    temp = primero;
    ret = temp->getData();

    primero = primero->getSig();

    delete temp;
    return ret;
}

void listaSimpleEnlazada::push(int valor){
    Nodo *nuevo_nodo = new Nodo(valor);
    if (primero == nullptr){
        primero = nuevo_nodo;
        ultimo = nuevo_nodo;
    
    }else{
        nuevo_nodo->setSig(primero);
        primero = nuevo_nodo;
    }
    
}

void listaSimpleEnlazada::append(int valor){
    Nodo *nuevo_nodo = new Nodo(valor);

    if (primero == nullptr){
        primero = nuevo_nodo;
        ultimo = nuevo_nodo;
    
    }else{
        // Nodo *temp = primero;
        // while(temp->getSig() != nullptr){
        //     temp = temp->getSig();
        // }
        // temp->setSig(nuevo_nodo);
        ultimo->setSig(nuevo_nodo);
        ultimo = nuevo_nodo;
    }
    
}

/*
    -   Si el indice es mayor que el tamaño de la lista, lo inserta al final
    -   Si el índice es 0, es un push
    -   0 significa el primer elemento
    -   Los índices entonces, irán desde 0 hasta el tamaño - 1
 */
void listaSimpleEnlazada::insert(int indice, int valor){
    Nodo *nuevo_nodo = new Nodo(valor);
    Nodo *temp;
    int i = 0;

    temp = primero;

    if (primero == nullptr || indice == 0){this->push(valor);}
    else{
        while(temp->getSig() != nullptr && i < indice - 1 ){
            temp = temp->getSig();
            i+=1;
        }
        
        nuevo_nodo->setSig(temp->getSig());
        temp->setSig(nuevo_nodo);
    }
}

void listaSimpleEnlazada::print(){
    Nodo *temp = primero;

    while(temp != nullptr){
        std::cout << temp->getData() << ", ";
        temp = temp->getSig();
    }
    std::cout <<  std::endl;
}