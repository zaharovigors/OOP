#include "octagon.h"
#include <iostream>
#include <cmath>

Octagon::Octagon() : Octagon(0) {
}

Octagon::Octagon(size_t a) :
        a(a){
    std::cout << "Octagon with side is " << a << " created." << std::endl;
}

Octagon::Octagon(std::istream &is) {
    is >> a;
}

Octagon::Octagon(const Octagon& orig) {
    std::cout << "Octagon copy created" << std::endl;
    a = orig.a;
}

double Octagon::Square() {
    double S = 2*(1 + sqrt(2))*a;
    return S;

}

void Octagon::Print() {
    std::cout << "Восьмиугольник со стороной a=" << a << std::endl;

}

Octagon::~Octagon() {
    std::cout << "Octagon deleted" << std::endl;
}
