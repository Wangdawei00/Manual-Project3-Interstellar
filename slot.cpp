//
// Created by lenovo on 2018/12/11.
//

#include "slot.h"

void slot::pushGroup(Group *car) {
    vehicle = car;
}

slot::slot(Point center) {
    this->center = center;
}