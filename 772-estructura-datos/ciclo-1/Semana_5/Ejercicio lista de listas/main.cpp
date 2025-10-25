#include "listOfLists.h"

int main()
{
    listOfLists l;
    l.insert(0, 'H');
    l.insert(1, 'E');
    l.insert(2, 'L');
    l.insert(2, 'L');
    l.insert(3, 'O');
    l.insert(0, 'W');
    l.insert(1, 'O');
    l.insert(2, 'R');
    l.insert(3, 'L');
    l.insert(4, 'D');
    l.insert(5, '!');
    l.print();
    return 0;
}
