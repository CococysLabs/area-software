#include "node.h"

/*
    CLASE NODO
*/

node::node(){
    index = -1;
    list = nullptr;
    next = nullptr;
}

node::node(int index){
    this->index = index;
    list = nullptr;
    next = nullptr;
}

node::~node(){
    sub_node *temp = list;
    sub_node *aux;

    while(temp != nullptr){
        aux = temp->getNext();
        delete temp;
        temp = aux;
    }
}

void node::append(char data){
    sub_node *new_node = new sub_node(data);
    
    if(list == nullptr){
        list = new_node;
    
    }else{
        sub_node *temp = list;
        while(temp->getNext() != nullptr){
            temp = temp->getNext();
        }
        temp->setNext(new_node);
    }
}

void node::print(){
    sub_node *temp = list;
    while(temp != nullptr){
        std::cout << temp->getData() << std::endl;
        temp = temp->getNext();
    }
}

void node::setIndex(int index){
    this->index = index;
}

void node::setPrev(node *prev){
    this->prev = prev;
}

void node::setNext(node *next){
    this->next = next;
}

node* node::getPrev(){
    return prev;
}

node* node::getNext(){
    return next;
}

int node::getIndex(){
    return index;
}

/*
    CLASE SUB_NODO
*/

// Constructor
node::sub_node::sub_node(char data){
    this->data = data;
    next = nullptr;
}

// Getters y setters
char node::sub_node::getData(){
    return data;
}

node::sub_node* node::sub_node::getNext(){
    return next;
}

void node::sub_node::setData(char data){
    this->data = data;
}

void node::sub_node::setNext(sub_node *next){
    this->next = next;
}