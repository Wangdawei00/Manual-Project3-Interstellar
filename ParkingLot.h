//
// Created by starrynight on 2018/12/12.
//

#ifndef MANUAL_PROJECT3_INTERSTELLAR_PARKINGLOT_H
#define MANUAL_PROJECT3_INTERSTELLAR_PARKINGLOT_H

#include <iostream>
#include "slot.h"

using namespace std;

class ParkingLot {
public:
    explicit ParkingLot(int column);

    vector<int> const &find_empty_slot();

    vector<Slot> &operator[](int a);

    void drawingInitialize();

    void draw();

    void specialMove();

    ~ParkingLot();

private:
    int row, column;
    vector<vector<Slot>> slots;
    vector<Group*> all;
    Point barrierCenter;
    int index;
};


#endif //MANUAL_PROJECT3_INTERSTELLAR_PARKINGLOT_H