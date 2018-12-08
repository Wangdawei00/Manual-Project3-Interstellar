//
// Created by starrynight on 2018/12/5.
//

#ifndef EX3_CAR_H
#define EX3_CAR_H

#include "figures_sjl.h"

class Car {
public:
    Car(point pIn, double carLength, double carHeight, double wheelRadius, double windowLength, double ceilingLength);

    void draw();

    void move(point *p, double dx);

    ~Car();

private:
    Figures *F[5];
    point p;

    void goLeft(point *p, double dx);

    void goRight(point *p, double dx);
};

#endif //EX3_CAR_H
