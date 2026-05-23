#include "listaDobleEnlazada.h"

int main(int argc, char const *argv[])
{
    ListaDoblementeEnlazada l;
    l.push(5);
    l.push(10);
    l.push(51);
    l.push(20);

    l.append(100);
    l.append(1);
    l.append(30);

    l.insert(0, 9999);
    l.insert(20, 8888);

    std::cout << "Lista escrita al derecho: " << '\n';
    l.print();
    std::cout << std::endl;

    std::cout << "Lista escrita al revez: " << '\n';
    l.revPrint();
    return 0;
}
