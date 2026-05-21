#include "nodo.h"

//Constructor
Nodo::Nodo(int data){
    this->data = data;
    prev = nullptr;
    sig = nullptr;
}

//Getter y setters
int Nodo::getData(){
    return data;
}

Nodo* Nodo::getPrev(){
    return prev;
}

Nodo* Nodo::getSig(){
    return sig;
}

void Nodo::setData(int data){
    this->data = data;
}

void Nodo::setPrev(Nodo *prev){
    this->prev = prev;
}

void Nodo::setSig(Nodo *sig){
    this->sig = sig;
}