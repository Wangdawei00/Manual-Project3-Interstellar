//
// Created by Wangdawei on 2018/12/5.
//

#include "Figure.h"
#include "Shape.h"
#include <cmath>
#include <random>

//Figure::~Figure() = default;

inline double rand0to1() {
    return rand() * 1.0 / RAND_MAX;
}

MainFigure &MainFigure::getInstance() {
    static MainFigure instance;
    return instance;
}

void Group::setAnchor(Vec v) {
    anchor = v;
}

const Vec &Group::getAnchor() const {
    return anchor;
}

Car::Car(Vec v, double *ang) {
    setAnchor(v);
    set(.16, .08);
    shapes.push_back(
            IsoTrapezoid(rand0to1(), rand0to1(), rand0to1(), Vec(v.getX(), v.getY() + height / 4), .375 * width,
                         .625 * width, height / 2,
                         *ang));
    shapes.push_back(
            Rect(rand0to1(), rand0to1(), rand0to1(), Vec(v.getX(), v.getY() - height * .1875), width, height * .375,
                 *ang));
    shapes.push_back(Circle(Vec(v.getX() - width / 4, v.getY() - height * .375), height / 8, rand0to1(), rand0to1(),
                            rand0to1()));
    shapes.push_back(Circle(Vec(v.getX() + width / 4, v.getY() - height * .375), height / 8, rand0to1(), rand0to1(),
                            rand0to1()));
}

void Car::set(double w, double h) {
    width = w;
    height = h;
}

//void Car::draw() {
//    top.draw();
//    below.draw();
//    wheels[0].draw();
//    wheels[1].draw();
//}

Teleported::Teleported(Vec v) {
    Teleported::setAnchor(v);
    Teleported::set(.16, .08);
    shapes.push_back(Rect(rand0to1(), rand0to1(), rand0to1(), v, width, height, 0));
}

void Teleported::randomColor() {
    shapes[0].setColor(rand0to1(), rand0to1(), rand0to1());
}

void Teleported::set(double w, double h) {
    width = w;
    height = h;
}

//void Teleported::draw() {
//    rec.draw();
//}

UFO::UFO(Vec initial) {
    bodyRadius = 0.04;
    wheelUpLength = 0.02;
    wheelDownLength = 0.03;
    wheelHeight = 0.02;
    antennaLength = 0.01;
    center = initial;
    angle = 0;
    shapes.push_back(SemiCircle(rand0to1(), rand0to1(), rand0to1(), center, bodyRadius, angle));
    Vec leftWheelCenter;
    leftWheelCenter = center + Vec(-0.02, -0.01);
    shapes.push_back(IsoTrapezoid(rand0to1(), rand0to1(), rand0to1(), leftWheelCenter, wheelUpLength, wheelDownLength,
                                  wheelHeight, angle));
    Vec rightWheelCenter;
    rightWheelCenter = center + (Vec(0.02, -0.01));
    shapes.push_back(IsoTrapezoid(rand0to1(), rand0to1(), rand0to1(), rightWheelCenter, wheelUpLength, wheelDownLength,
                                  wheelHeight, angle));
    Vec leftAntennaCenter;
    leftAntennaCenter = center + (Vec(cos(2.0 / 3.0 * pi) * bodyRadius, sin(2.0 / 3.0 * pi) * bodyRadius));
    shapes.push_back(
            Rect(rand0to1(), rand0to1(), rand0to1(), leftAntennaCenter, antennaLength, 0.005, 2.0 / 3.0 * pi + angle));
    Vec rightAntennaCenter;
    rightAntennaCenter = center + (Vec(cos(1.0 / 3.0 * pi) * bodyRadius, sin(1.0 / 3.0 * pi) * bodyRadius));
    shapes.push_back(
            Rect(rand0to1(), rand0to1(), rand0to1(), rightAntennaCenter, antennaLength, 0.005, 1.0 / 3.0 * pi + angle));
}

//void UFO::draw() {
//    for (auto const &item:all) {
//        item->draw();
//    }
//}

void UFO::move(Vec a) {
    center = center + a;
    for (auto &item:shapes)
        item.move(a);
}

void UFO::rotate(Vec centerPoint, double angleTurnig) {
    for (auto &item:shapes) {
        item.rotate(centerPoint, angleTurnig);
    }
};

void UFO::spin() {
    for (auto &item:shapes) {
        item.rotate(center, 0.1);
    }
}

//UFO::~UFO() {
//    for (auto const &item:all) {
//        delete item;
//    }
//};

Rocket::Rocket(Vec initial) {
    bodyWidth = 0.04;
    bodyHeight = 0.08;
    wingLength = 0.02;
    wingHeight = 0.04;
    jetHeight = 0.02;
    roofHeight = 0.02;
    jetUpLength = 0.04 / 3.00;
    angle = 0;
    center = initial;
    shapes.push_back(Rect(rand0to1(), rand0to1(), rand0to1(), center, bodyHeight, bodyWidth, angle));
    Vec wingP1 = center + Vec(-wingLength - 0.5 * bodyWidth, -0.5 * bodyHeight),
            wingP2 = center + Vec(-0.5 * bodyWidth, -0.5 * bodyHeight),
            wingP3 = center + Vec(-0.5 * bodyWidth, -0.5 * bodyHeight + wingHeight);
    shapes.push_back(Triangle(wingP1, wingP2, wingP3, rand0to1(), rand0to1(), rand0to1()));
    wingP1 = center + Vec(0.5 * bodyWidth, -0.5 * bodyHeight);
    wingP2 = center + Vec(0.5 * bodyWidth + wingLength, -0.5 * bodyHeight);
    wingP3 = center + Vec(0.5 * bodyWidth, -0.5 * bodyHeight + wingHeight);
    shapes.push_back(Triangle(wingP1, wingP2, wingP3, rand0to1(), rand0to1(), rand0to1()));
    Vec IsoTrapezoidCenter = center + Vec(0, -0.5 * bodyHeight - 0.5 * jetHeight);
    shapes.push_back(
            IsoTrapezoid(rand0to1(), rand0to1(), rand0to1(), IsoTrapezoidCenter, jetUpLength, bodyWidth, jetHeight,
                         angle));
    Vec roofP1 = center + Vec(-0.5 * bodyWidth, 0.5 * bodyHeight),
            roofP2 = center + Vec(0.5 * bodyWidth, 0.5 * bodyHeight),
            roofP3 = center + Vec(0, 0.5 * bodyHeight + roofHeight);
    shapes.push_back(Triangle(roofP1, roofP2, roofP3, 0, 0, 1));
    Vec RectCenter = center + Vec(0, -(1.0 / 3.0) * bodyHeight);
    shapes.push_back(
            Rect(rand0to1(), rand0to1(), rand0to1(), RectCenter, (1.0 / 3.0) * bodyHeight, (1.0 / 3.0) * bodyWidth,
                 angle));
    RectCenter = center + Vec(0.25 * bodyWidth, 0.25 * bodyHeight);
    shapes.push_back(Rect(rand0to1(), rand0to1(), rand0to1(), RectCenter, 0.25 * bodyHeight, 0.25 * bodyWidth, angle));
    RectCenter = center + Vec(-0.25 * bodyWidth, 0.25 * bodyHeight);
    shapes.push_back(Rect(rand0to1(), rand0to1(), rand0to1(), RectCenter, 0.25 * bodyHeight, 0.25 * bodyWidth, angle));
}

//void Rocket::draw() {
//    for (auto const &item:all) {
//        item->draw();
//    }
//}

void Rocket::move(Vec moveToward) {
    for (auto &item:shapes) {
        item.move(moveToward);
    }
}

void Rocket::rotate(Vec centerPoint, double angleTurning) {
    for (auto &item:shapes) {
        item.rotate(centerPoint, angleTurning);
    }
}

void Rocket::zoom(double coefficient) {
    for (auto &item:shapes) {
        item.zoom(center, coefficient);
    }
}

//Rocket::~Rocket() {
//    for (int i = 0; i < 8; ++i) {
//        delete (all[i]);
//    }
//}

void MainFigure::draw() const {


}

MainFigure::MainFigure() = default;

MainFigure::~MainFigure() = default;

void Group::draw() const {
    for (auto const &item:shapes)
        item.draw();
}

