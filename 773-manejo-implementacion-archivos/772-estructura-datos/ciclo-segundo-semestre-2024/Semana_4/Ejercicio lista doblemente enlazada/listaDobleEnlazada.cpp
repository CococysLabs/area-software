#include "listaDobleEnlazada.h"

ListaDoblementeEnlazada::ListaDoblementeEnlazada(){
    primero = nullptr;
    ultimo = nullptr;
}

ListaDoblementeEnlazada::~ListaDoblementeEnlazada(){
    Nodo *temp = primero;
    Nodo *aux;

    while(temp != nullptr){
        aux = temp->getSig();
        delete temp;
        temp = aux;
    }
}

void ListaDoblementeEnlazada::push(int data){
    Nodo *nuevo = new Nodo(data);

    if(primero == nullptr){
        primero = nuevo;
        ultimo = nuevo;
    
    }else{
        nuevo->setSig(primero);
        primero->setPrev(nuevo);
        primero = nuevo;
    }
}

void ListaDoblementeEnlazada::append(int data){
    Nodo *nuevo = new Nodo(data);

    if(primero == nullptr){
        primero = nuevo;
        ultimo = nuevo;
    
    }else{
        nuevo->setPrev(ultimo);
        ultimo->setSig(nuevo);
        ultimo = nuevo;
    }
}

void ListaDoblementeEnlazada::insert(int indice, int data){
    Nodo *nuevo = new Nodo(data);
    Nodo *actual = new Nodo(data);

    int i = 0;
    actual = primero;

    if(primero == nullptr || indice == 0){this->push(data);}
    else{
        while(actual->getSig() != nullptr && i < indice - 1){
            actual = actual->getSig();
            i++;
        }

        if(i < indice -1){
            this->append(data);
            return;
        }

        nuevo->setSig(actual->getSig());
        nuevo->setPrev(actual);
        actual->getSig()->setPrev(nuevo);
        actual->setSig(nuevo);
    }
}

void ListaDoblementeEnlazada::print(){
    Nodo *temp = primero;

    while(temp != nullptr){
        std::cout << temp->getData() << ", ";
        temp = temp->getSig();
    }
    std::cout << std::endl;
}

void ListaDoblementeEnlazada::revPrint(){
    Nodo *temp = ultimo;

    while(temp != nullptr){
        std::cout << temp->getData() << ", ";
        temp = temp->getPrev();
    }
    std::cout << std::endl;
}