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

Slot::Slot(Point center) {
    this->center = center;
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