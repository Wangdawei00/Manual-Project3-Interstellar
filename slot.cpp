//
// Created by lenovo on 2018/12/11.
//

#include "slot.h"
void slot::pushGroup(Group *car) {
    carParking=car;
}
slot::slot(Point Center) {
    centerOfSlot=Center;
}