//
// Created by lenovo on 2018/12/11.
//

#ifndef MANUAL_PROJECT3_INTERSTELLAR_SLOT_H
#define MANUAL_PROJECT3_INTERSTELLAR_SLOT_H

#include "Shape.h"
#include "Figure.h"

class slot {
public:
    void pushGroup(Group *carParking);

    explicit slot(Point Center);

private:
    Point center;
    const double length = 0.2;
    const double width = 0.1;
    Group *vehicle;
};

#endif //MANUAL_PROJECT3_INTERSTELLAR_SLOT_H
