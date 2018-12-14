//
// Created by starrynight on 2018/12/12.
//

#include "ParkingLot.h"
#include "Figure.h"

bool compare(double x, double y) {
    const double f = 0.01;
    double ans = x - y;
    if ((ans >= -f) && (ans <= f)) return true;
    return false;
}


ParkingLot::ParkingLot(int column) {
    this->row = 2;
    this->column = column;
    flag1 = true;
    flag2 = true;
    flag3 = true;
    flagMovingCar = false;
    index = 0;//index is used to determine how many times the vehicle has rotated ( pi/30 = 1 time )
    Point starting_down(-0.75, -0.7);
    Point starting_up(-0.75, 0.5);
    double distance = (1.4 / (column - 1));
    barrierCenter = Vec(0.1, -0.1);
    vector<Slot> a, b;//generate a vector of Slot(a type defined in "slot.h")
    for (int i = 0; i < column; ++i) {
        Slot S(starting_down.operator+(Vec(i * distance, 0)), starting_down.operator+(Vec(i * distance + 0.1, 0.1)));
        a.push_back(S);//add new element(a new slot "S")to the end of the vector "a"
    }
    for (int j = 0; j < column; ++j) {
        Slot S(starting_up.operator+(Vec(j * distance, 0)), starting_up.operator+(Vec(j * distance + 0.1, 0.1)));
        b.push_back(S);
    }
    slots.push_back(a);
    slots.push_back(b);//add "a"to the end of the whole slots
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < column; j++) {
            slots[i][j].setIndex(i, j);
        }
    }
}


Slot const *ParkingLot::find_empty_slot() {
//    int (*empty)[2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < column; j++) {
            if (slots[i][j].isEmpty()) {//if there exists an empty slot
                return &slots[i][j];
            }
        }
    }
    return nullptr;
}

void ParkingLot::drawingInitialize() {
    if (ParkingLot::find_empty_slot() == nullptr) {
        cout << "no empty slots!" << endl;
        return;
    }
    if (flagMovingCar) {
        if (flag1) {
            Vec const dir(0, 0.01); //the direction( go up )

            (*(all.end() - 1))->move(dir); //move up
            Vec momentAnchor = (*(all.end() - 1))->getAnchor();

            Vec corner1 = Vec(-0.9, (*(all.end() - 1))->getDestination().getY());

            double my = momentAnchor.getY();
            double cy = corner1.getY();
            if (compare(momentAnchor.getY(), corner1.getY()) &&
                compare(momentAnchor.getX(), corner1.getX())) { //if vehicle moves to the first corner
                flag1 = false;
                cout << "hu" << endl;
            }
        } else if (flag2) { //need to turn right at the first corner
            double const angle = -pi /
                                 30; //the direction( turn right ) in order to let the vehicle stop when angle=pi/2, the unit angle must be the factor of pi/2
            Vec corner1(-0.7, (*(all.end() - 1))->getDestination().getY());//the turning center
            (*(all.end() - 1))->rotate(corner1, angle); //rotate
            index++;
            if (index == 15) { //if vehicle has finished rotating
                flag2 = false;
                index = 0;
            }
        } else if (flag3) {
            Vec const dir(0.01, 0); //the direction( go right )
            (*(all.end() - 1))->move(dir); //move right
            Vec momentAnchor = (*(all.end() - 1))->getAnchor();
            Vec corner2 = (*(all.end() - 1))->getDestination();
            corner2 = corner2.operator+(Vec(0.2, 0.2));
            if (compare(momentAnchor.getY(), corner2.getY()) &&
                compare(momentAnchor.getX(), corner2.getX())) { //if vehicle moves to the second corner
                flag3 = false;
            }
        } else {
            double const angle = pi / 30; //anticlockwise
            Vec corner2 = (*(all.end() - 1))->getDestination();
            corner2 = corner2.operator+(Vec(0.2, 0));//the turning center
            (*(all.end() - 1))->rotate(corner2, angle); //rotate
            index++;
            if (index == 15) { //if vehicle has finished rotating
                flagMovingCar = false;
                flag1 = true;
                flag2 = true;
                flag3 = true;
                cout << "slot=[" << ParkingLot::find_empty_slot()->getI() << "]["
                     << ParkingLot::find_empty_slot()->getJ() << "]" << endl;
                slots[ParkingLot::find_empty_slot()->getI()][ParkingLot::find_empty_slot()->getJ()].pushGroup(
                        all.back());
                index = 0;
            }
        }
    } else {
        int random = rand() % 4;
        flagMovingCar = true;
        switch (random) {
            case 0:
                all.push_back(new Car(Vec(-0.9, -0.9), pi / 2, 1));
                (*(all.end() - 1))->setDestination(ParkingLot::find_empty_slot());
                break;
            case 1:
                all.push_back(new Teleported(Vec(ParkingLot::find_empty_slot()->retCoordinate().getX(),
                                                 ParkingLot::find_empty_slot()->retCoordinate().getY()), 1));
                slots[ParkingLot::find_empty_slot()->getI()][ParkingLot::find_empty_slot()->getJ()].pushGroup(
                        all.back());
                flagMovingCar = false;
                break;
            case 2:
                all.push_back(new UFO(Vec(-0.9, -0.9), 0, 1));
                (*(all.end() - 1))->setDestination(ParkingLot::find_empty_slot());
                break;
            case 3:
                all.push_back(new Rocket(Vec(-0.9, -0.9), 0, 1));
                (*(all.end() - 1))->setDestination(ParkingLot::find_empty_slot());
            default:
                break;
        }
    }
    specialMove();

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