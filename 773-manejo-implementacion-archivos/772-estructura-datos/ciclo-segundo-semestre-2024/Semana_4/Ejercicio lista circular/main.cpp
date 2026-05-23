#include "ListaCircular.h"

int main(int argc, char const *argv[])
{
    ListaCircular l;

    l.push(1);
    l.push(2);
    l.push(6);
    l.push(10);
    l.push(5);

    l.append(100);
    l.append(2000);
    l.print();

    l.graph();
    return 0;
}
