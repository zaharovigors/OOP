#include "square.h"
#include <iostream>
#include <cmath>

FSquare::FSquare() : FSquare(0) {
}

FSquare::FSquare(size_t a) : side_a(a) {
    std::cout << "FSquare created: " << side_a << std::endl;
}

FSquare::FSquare(std::istream &is) {
    is >> side_a;
}

FSquare::FSquare(const FSquare& orig) {
    std::cout << "FSquare copy created" << std::endl;
    side_a = orig.side_a;
}

double FSquare::Square() {
    double S = pow(side_a , 2);
    return S;

}

void FSquare::Print() {
    std::cout << "a=" << side_a << std::endl;

}

FSquare::~FSquare() {
    std::cout << "Square deleted" << std::endl;
}
