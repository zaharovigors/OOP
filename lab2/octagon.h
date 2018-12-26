#ifndef OCTAGON_H
#define	OCTAGON_H
#include <cstdlib>
#include <iostream>
#include "figure.h"

class Octagon : public Figure{
public:
    Octagon();
    Octagon(size_t a);
    Octagon(const Octagon& orig);

    Octagon& operator++();
    double Square() override;
    friend Octagon operator+(const Octagon& left,const Octagon& right);

    friend std::ostream& operator<<(std::ostream& os, const Octagon& obj);
    friend std::istream& operator>>(std::istream& is,  Octagon& obj);

    Octagon& operator=(const Octagon& right);

    virtual ~Octagon();
private:
    size_t a;
};

#endif	/* OCTAGON_H */
