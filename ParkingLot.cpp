//
// Created by starrynight on 2018/12/12.
//

#include "ParkingLot.h"

ParkingLot::ParkingLot(int column) {
    int i, j;
    this->row = 2;
    this->column = column;
    Point starting_down(-0.7, -0.7);
    Point starting_up(-0.7, 0.5);
    double distance = (1.4 / (column - 1));
    barrierCenter = Vec(0.1, -0.1);
    vector<Slot> a, b;//generate a vector of Slot(a type defined in "slot.h")
    for (i = 0; i < column; ++i) {
        Slot S(starting_down.operator+(Vec(i * distance, 0)), starting_down.operator+(Vec(i * distance + 0.1, 0.1)));
        a.push_back(S);//add new element(a new slot "S")to the end of the vector "a"
    }
    for (j = 0; j < column; ++j) {
        Slot S(starting_up.operator+(Vec(j * distance, 0)), starting_up.operator+(Vec(j * distance + 0.1, 0.1)));
        b.push_back(S);
    }
    slots.push_back(a);
    slots.push_back(b);//add "a"to the end of the whole slots
}

vector<int> const &ParkingLot::find_empty_slot() {
//    int (*empty)[2];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (slots[i][j].isEmpty()) {//if there exists an empty slot
//                return a[i][j];
                static vector<int> ret(2, 0);//generate a vector containing 2 integers
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }
    static vector<int> b = vector<int>(2, -1);//otherwise return (-1,-1) to indicate no empty slot
    return b;
}

void ParkingLot::drawingInitialize() {
    if (ParkingLot::find_empty_slot()[0] == -1) {
        cout << "no empty slots!" << endl;
        return;
    }
//    else if(){} 这里写一个判断是否有车在动的函数
    else {
        int random = rand() % 4;
        switch (random) {
            case 0:
                all.push_back(new Car(Vec(-0.9, -0.9), 0, 1));
                break;
            case 1:
                all.push_back(new Teleported(Vec(-0.9, -0.9), 1));
                break;
            case 2:
                all.push_back(new UFO(Vec(-0.9, -0.9), 0, 1));
                break;
            case 3:
                all.push_back(new Rocket(Vec(-0.9, -0.9), 0, 1));
            default:
                break;
        }
        slots[ParkingLot::find_empty_slot()[0]][ParkingLot::find_empty_slot()[1]].pushGroup(all.back());
    }
}

void ParkingLot::draw() {
    for (auto &item:all) item->draw();
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            slots[i][j].draw();
        }
    }
    Rect(0.5, 0.5, 0.5, barrierCenter, 1.4, 0.4, 0).draw();
    Rect(0, 0, 0, Vec(-1, 0), 0.005, 2, 0).draw();
    Rect(0, 0, 0, Vec(0, 1), 2, 0.005, 0).draw();
    Rect(0, 0, 0, Vec(1, 0.1), 0.005, 1.8, 0).draw();
    Rect(0, 0, 0, Vec(0.1, -0.8), 1.8, 0.005, 0).draw();
    Rect(0, 0, 0, Vec(-0.8, -0.9), 0.005, 0.2, 0).draw();
}

void ParkingLot::specialMove() {
    for (auto &item:all) item->specialMove();
}


vector<Slot> &ParkingLot::operator[](int a) {
    return slots[a];//return a single row "a" from "slots"
}

ParkingLot::~ParkingLot() {
    for (auto &item:all) {
        delete item;
    }
}