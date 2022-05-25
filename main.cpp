#include <iostream>
#include "tree.h"

int main()
{
    tree<int> a;       //бинарное дерево
    a.push(45);
    a.push(30);
    a.push(50);
    a.push(27);
    a.push(39);
    a.push(15);
    a.push(90);
    a.push(103);
    a.push(70);

    a.show();

    return 0;
}
