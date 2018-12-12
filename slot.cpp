//
// Created by lenovo on 2018/12/11.
//

#include "slot.h"

const double Slot::width = defWidth;
const double Slot::length = defLength;

void Slot::pushGroup(Group *car) {
    vehicle = car;
    empty = false;
}

Slot::Slot(Point center, Point datum) {
    this->center = center;
    this->datum = datum;
    vehicle = nullptr;
    empty = true;
}

Group *Slot::returnVehicle() {
    return vehicle;
}

bool Slot::isEmpty() const {
    return empty;
}

const Point &Slot::retCoordinate() const {
    return center;
}


const Point &Slot::retDatum() const {
    return datum;
}

void Slot::draw(){
//    Strip(center.operator+(Vec(-0.1,-0.1)),center.operator+(Vec(-0.1,0.1))).draw();
    glBegin(GL_LINE_STRIP);
    glVertex2d(center.operator+(Vec(-0.1,-0.1)).getX(),center.operator+(Vec(-0.1,-0.1)).getY());
    glVertex2d(center.operator+(Vec(-0.1,0.1)).getX(),center.operator+(Vec(-0.1,0.1)).getY());
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2d(center.operator+(Vec(0.1,-0.1)).getX(),center.operator+(Vec(0.1,-0.1)).getY());
    glVertex2d(center.operator+(Vec(0.1,0.1)).getX(),center.operator+(Vec(0.1,0.1)).getY());
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2d(center.operator+(Vec(-0.1,-0.1)).getX(),center.operator+(Vec(-0.1,-0.1)).getY());
    glVertex2d(center.operator+(Vec(0.1,-0.1)).getX(),center.operator+(Vec(0.1,-0.1)).getY());
    glEnd();
}

void Slot::specialMove() {}