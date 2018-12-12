//
// Created by lenovo on 2018/12/11.
//

#ifndef MANUAL_PROJECT3_INTERSTELLAR_SLOT_H
#define MANUAL_PROJECT3_INTERSTELLAR_SLOT_H

#include "Shape.h"
#include "Figure.h"
#include <GL/freeglut.h>

static const double defLength = 0.2;
static const double defWidth = 0.1;

class Slot:public Group{
public:
    void pushGroup(Group *carParking);

    explicit Slot(Point Center,Point datum);

    Group *returnVehicle();

    bool isEmpty() const;

    const Point &retCoordinate() const;

    const Point &retDatum() const;

    void draw();

    void specialMove() override;

private:
    Point center;
    Point datum;
    bool empty;
    static const double length;
    static const double width;
    Group *vehicle;
};

#endif //MANUAL_PROJECT3_INTERSTELLAR_SLOT_H
