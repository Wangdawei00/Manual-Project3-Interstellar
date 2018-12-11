//
// Created by lenovo on 2018/12/11.
//

#ifndef MANUAL_PROJECT3_INTERSTELLAR_SLOT_H
#define MANUAL_PROJECT3_INTERSTELLAR_SLOT_H

#include "Shape.h"
#include "Figure.h"
class slot {
public:
    void pushGroup(Group* carParking);
explicit slot(Point Center);
private:
    Point centerOfSlot;
    Group* carParking;
};

#endif //MANUAL_PROJECT3_INTERSTELLAR_SLOT_H
