//
// Created by lenovo on 2018/12/11.
//

#ifndef MANUAL_PROJECT3_INTERSTELLAR_SLOT_H
#define MANUAL_PROJECT3_INTERSTELLAR_SLOT_H

#include "Shape.h"
//#include "Figure.h"
#include <GL/glut.h>

class Group;

static const double defLength = 0.2;
static const double defWidth = 0.1;

class Slot : public Figure {
public:
    void pushGroup(Group *carParking);

    explicit Slot(Point Center, Point datum);

    Group *returnVehicle();

    bool isEmpty() const;

    const Point &retCoordinate() const;

    const Point &retDatum() const;

    void draw() const override;

    void setIndex(int i,int j);

    const int getI() const;

    const int getJ() const;

private:
    Point center;
    Point datum;
    bool empty;
    static const double length;
    static const double width;
    Group *vehicle;
    int i,j;
};

#endif //MANUAL_PROJECT3_INTERSTELLAR_SLOT_H
