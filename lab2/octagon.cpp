#include "octagon.h"
#include <iostream>
#include <cmath>

Octagon::Octagon() : Octagon(0) {
}

Octagon::Octagon(size_t a) : a(a) {
    std::cout << "Octagon created: " << a << std::endl;
}

Octagon::Octagon(const Octagon& orig) {
    std::cout << "Octagon copy created" << std::endl;
    a = orig.a;
}

double Octagon::Square(){
    double S = 2*(1 + sqrt(2))*a;
    return S;

}

Octagon& Octagon::operator=(const Octagon& right) {

    if (this == &right) return *this;

    std::cout << "Octagon copied" << std::endl;
    a = right.a;

    return *this;
}

Octagon& Octagon::operator++() {

    a++;

    return *this;
}

Octagon operator+(const Octagon& left,const Octagon& right) {

    return Octagon(left.a+right.a);
}

Octagon::~Octagon() {
    std::cout << "Octagon deleted" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Octagon& obj) {

    os << "a=" << obj.a << " ";
    return os;
}

std::istream& operator>>(std::istream& is, Octagon& obj) {

    is >> obj.a;

    return is;
}
