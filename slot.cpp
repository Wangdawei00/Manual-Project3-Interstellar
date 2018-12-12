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

void Slot::draw() const{
//    Strip(center.operator+(Vec(-0.1,-0.1)),center.operator+(Vec(-0.1,0.1))).draw();
    Rect(0,0,0,center.operator+(Vec(-0.5*width,0)),0.005,length,0).draw();
    Rect(0,0,0,center.operator+(Vec(0.5*width,0)),0.005,length,0).draw();
    Rect(0,0,0,center.operator+(Vec(0,-0.5*length)),width,0.005,0).draw();
}