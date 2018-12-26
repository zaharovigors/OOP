#include <cstdlib>
#include <iostream>

#include "octagon.h"
#include "TNode.h"
#include "list.h"

// Simple list on pointers
int main(int argc, char** argv) {

    TList list;

    list.push(Octagon(1),0);
    list.push(Octagon(2),1);
    list.push(Octagon(1)+Octagon(2),1);

    std::cout << list;


    Octagon t;

    t = list.pop(2); std::cout << t;
    t = list.pop(1); std::cout << t;
    t = list.pop(0); std::cout << t;

    return 0;
}
