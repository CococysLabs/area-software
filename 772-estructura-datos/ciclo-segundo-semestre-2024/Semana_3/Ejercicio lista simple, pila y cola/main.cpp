#include "ListaSimpleEnlazada.h"

int main(int argc, char const *argv[])
{
    listaSimpleEnlazada l;
    l.push(12);
    l.push(10);
    l.push(5);
    l.push(3);

    l.append(500);
    l.append(200);
    l.append(50);

    l.insert(0, 999);
    l.insert(3, 999);
    l.insert(6, 999);
    l.insert(1500, 999);
    l.print();

    int ret = l.pop();
    l.print();
    std::cout << ret << std::endl;
    return 0;
}
