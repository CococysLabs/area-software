#include <iostream>
#include <memory>
#include <fstream>
#include <string>

using namespace std;

class SubNode {
public:
    int value;
    shared_ptr<SubNode> next = nullptr;

    SubNode(int val) : value(val) {}
};

class Node {
public:
    int index;
    shared_ptr<Node> next = nullptr;
    shared_ptr<Node> prev = nullptr;
    shared_ptr<SubNode> list = nullptr;

    void append(int value) {
        shared_ptr<SubNode> new_node = make_shared<SubNode>(value);

        if (!list) {
            list = new_node;
        } else {
            shared_ptr<SubNode> aux = list;
            while (aux->next) {
                aux = aux->next;
            }
            aux->next = new_node;
        }
    }

    void print() {
        shared_ptr<SubNode> aux = list;
        while (aux) {
            cout << aux->value << " ";
            aux = aux->next;
        }
        cout << endl;
    }
};

class ListOfList {
public:
    shared_ptr<Node> head = nullptr;
    shared_ptr<Node> tail = nullptr;

    void insert(int index, int value) {
        shared_ptr<Node> new_node = make_shared<Node>();
        new_node->index = index;

        if (!head) {
            head = new_node;
            tail = new_node;
            new_node->append(value);
        } else {
            if (index < head->index) {
                head->prev = new_node;
                new_node->next = head;
                head = new_node;
                new_node->append(value);
            } else {
                shared_ptr<Node> aux = head;
                while (aux->next && index > aux->next->index) {
                    aux = aux->next;
                }
                if (index == aux->index) {
                    aux->append(value);
                } else {
                    new_node->next = aux->next;
                    new_node->prev = aux;
                    if (aux->next) {
                        aux->next->prev = new_node;
                    } else {
                        tail = new_node;
                    }
                    aux->next = new_node;
                    new_node->append(value);
                }
            }
        }
    }

    void printList() {
        shared_ptr<Node> aux = head;
        while (aux) {
            cout << "Index: " << aux->index << endl;
            aux->print();
            aux = aux->next;
        }
    }

    void graph() {
        ofstream file("graph.dot");
        file << "digraph G {" << endl;

        shared_ptr<Node> current_node = head;
        while (current_node) {
            file << current_node->index << "[label=\"" << current_node->index << "\"];" << endl;

            shared_ptr<SubNode> current_subnode = current_node->list;
            while (current_subnode) {
                file << current_node->index << " -> " << current_subnode->value << " [dir=normal];" << endl;
                current_subnode = current_subnode->next;
            }
            current_node = current_node->next;
        }

        file << "}" << endl;
        file.close();

        string command = "dot -Tpng ./graph.dot -o ./graph.png";
        if (system(command.c_str()) != 0) {
            cout << "Error al crear la imagen." << endl;
        } else {
            cout << "Imagen creada con éxito." << endl;
        }
    }
};

int main() {
    ListOfList adjacency_list;

    // Insertar algunos datos de ejemplo
    adjacency_list.insert(1, 2);
    adjacency_list.insert(2, 3);
    adjacency_list.insert(3, 1);
    adjacency_list.insert(4, 1);
    adjacency_list.insert(4, 2);
    adjacency_list.insert(1, 3);

    // Imprimir la lista de adyacencia
    cout << "Lista de adyacencia:" << endl;
    adjacency_list.printList();

    // Generar el archivo DOT y la imagen del grafo
    adjacency_list.graph();

    cout << "Se ha generado la imagen del grafo." << endl;
    return 0;
}
