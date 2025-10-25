#include "listOfLists.h"

listOfLists::listOfLists(){
    head = nullptr;
    tail = nullptr;
};

listOfLists::~listOfLists(){
    node *temp = head;
    node *aux;

    while(temp != nullptr){
        aux = temp->getNext();
        delete temp;
        temp = aux;    
    }
}

void listOfLists::insert(int index, char value){
    node *new_node = new node(index);
    if(head == nullptr){
        head = new_node;
        tail = new_node;
        new_node->append(value);
    
    }else{
        if(index < head->getIndex()){
            head->setPrev(new_node);
            new_node->setNext(head);
            head = new_node;
            new_node->append(value);
        
        }else{
            node *aux = head;
            while(aux->getNext() != nullptr){
                if(index < aux->getNext()->getIndex()){
                    if(index == aux->getIndex()){
                        aux->append(value);
                        delete new_node;
                    
                    }else{
                        new_node->setNext(aux->getNext());
                        new_node->setPrev(aux);
                        aux->getNext()->setPrev(new_node);
                        aux->setNext(new_node);
                        new_node->append(value);
                    }
                    return;
                }
                aux = aux->getNext();
            }

            if(index == aux->getIndex()){
                aux->append(value);
                delete new_node;
            
            }else{
                tail->setNext(new_node);
                new_node->setPrev(tail);
                tail = new_node;
                new_node->append(value);
            }
        }
    }
}

void listOfLists::print(){
    node *temp = head;

    while(temp != nullptr){
        std::cout << "Indice: " << temp->getIndex() << std::endl;
        temp->print();
        temp = temp->getNext();
    }
}