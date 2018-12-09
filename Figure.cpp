//
// Created by Wangdawei on 2018/12/5.
//

#include "Figure.h"
#include "Shape.h"
#include <cmath>
#include <random>

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

void Group::draw() const {
    for (auto const &item:shapes)
        item->draw();
}

Group::~Group() {
    for (auto &item:shapes)
        delete item;
}

void Group::move(Vec v) {
    anchor += v;
    for (auto &item:shapes) {
        item->move(v);
    }
}

void Group::rotate(Point center, double angle) {
    anchor = (anchor - center << angle) + center;
    for (auto &item:shapes) {
        item->rotate(center, angle);
    }
}

Car::Car(Vec v, double angle, double size) {
    this->size = size;
    setAnchor(v);
    set(.16 * size, .08 * size);
    shapes.push_back(new IsoTrapezoid(rand0to1(), rand0to1(), rand0to1(), Vec(v.getX(), v.getY() + height / 4),
                                      .375 * width, .625 * width, height / 2, 0));
    shapes.push_back(new Rect(rand0to1(), rand0to1(), rand0to1(), Vec(v.getX(), v.getY() - height * .1875), width,
                              height * .375, 0));
    shapes.push_back(new Circle(Vec(v.getX() - width / 4, v.getY() - height * .375), height / 8, rand0to1(), rand0to1(),
                                rand0to1()));
    shapes.push_back(new Circle(Vec(v.getX() + width / 4, v.getY() - height * .375), height / 8, rand0to1(), rand0to1(),
                                rand0to1()));
    rotate(v, angle);
}

void Car::set(double w, double h) {
    width = w;
    height = h;
}

Teleported::Teleported(Vec v, double size) {
    this->size = size;
    Teleported::setAnchor(v);
    Teleported::set(.16 * size, .08 * size);
    shapes.push_back(new Rect(rand0to1(), rand0to1(), rand0to1(), v, width, height, 0));
}

void Teleported::randomColor() {
    shapes[0]->setColor(rand0to1(), rand0to1(), rand0to1());
}

void Teleported::set(double w, double h) {
    width = w;
    height = h;
}

UFO::UFO(Vec initial, double angle, double size) {
    this->size = size;
    bodyRadius = 0.04 * size;
    wheelUpLength = 0.02 * size;
    wheelDownLength = 0.03 * size;
    wheelHeight = 0.02 * size;
    antennaLength = 0.01 * size;
    center = initial;
    this->angle = angle;
    shapes.push_back(new SemiCircle(rand0to1(), rand0to1(), rand0to1(), center, bodyRadius, 0));
    Vec leftWheelCenter;
    leftWheelCenter = center + Vec(-0.02 * size, -0.01 * size);
    shapes.push_back(new IsoTrapezoid(rand0to1(), rand0to1(), rand0to1(), leftWheelCenter, wheelUpLength,
                                      wheelDownLength, wheelHeight, 0));
    Vec rightWheelCenter;
    rightWheelCenter = center + (Vec(0.02 * size, -0.01 * size));
    shapes.push_back(new IsoTrapezoid(rand0to1(), rand0to1(), rand0to1(), rightWheelCenter, wheelUpLength,
                                      wheelDownLength, wheelHeight, 0));
    Vec leftAntennaCenter;
    leftAntennaCenter = center + (Vec(cos(2.0 / 3.0 * pi) * bodyRadius, sin(2.0 / 3.0 * pi) * bodyRadius));
    shapes.push_back(new Rect(rand0to1(), rand0to1(), rand0to1(), leftAntennaCenter, antennaLength, 0.005 * size,
                              2.0 / 3.0 * pi + 0));
    Vec rightAntennaCenter;
    rightAntennaCenter = center + (Vec(cos(1.0 / 3.0 * pi) * bodyRadius, sin(1.0 / 3.0 * pi) * bodyRadius));
    shapes.push_back(new Rect(rand0to1(), rand0to1(), rand0to1(), rightAntennaCenter, antennaLength, 0.005 * size,
                              1.0 / 3.0 * pi + 0));
    rotate(initial, angle);
}

void UFO::spin() {
    rotate(center, 0.1);
}

Rocket::Rocket(Vec initial, double angle, double size) {
    this->size = size;
    bodyWidth = 0.04 * size;
    bodyHeight = 0.08 * size;
    wingLength = 0.02 * size;
    wingHeight = 0.04 * size;
    jetHeight = 0.02 * size;
    roofHeight = 0.02 * size;
    jetUpLength = 0.04 * size / 3.00;
    this->angle = angle;
    center = initial;
    shapes.push_back(new Rect(rand0to1(), rand0to1(), rand0to1(), center, bodyWidth, bodyHeight, 0));
    Vec wingP1 = center + Vec(-wingLength - 0.5 * bodyWidth, -0.5 * bodyHeight),
            wingP2 = center + Vec(-0.5 * bodyWidth, -0.5 * bodyHeight),
            wingP3 = center + Vec(-0.5 * bodyWidth, -0.5 * bodyHeight + wingHeight);
    shapes.push_back(new Triangle(wingP1, wingP2, wingP3, rand0to1(), rand0to1(), rand0to1()));
    wingP1 = center + Vec(0.5 * bodyWidth, -0.5 * bodyHeight);
    wingP2 = center + Vec(0.5 * bodyWidth + wingLength, -0.5 * bodyHeight);
    wingP3 = center + Vec(0.5 * bodyWidth, -0.5 * bodyHeight + wingHeight);
    shapes.push_back(new Triangle(wingP1, wingP2, wingP3, rand0to1(), rand0to1(), rand0to1()));
    Vec IsoTrapezoidCenter = center + Vec(0, -0.5 * bodyHeight - 0.5 * jetHeight);
    shapes.push_back(new IsoTrapezoid(rand0to1(), rand0to1(), rand0to1(), IsoTrapezoidCenter, jetUpLength,
                                      bodyWidth, jetHeight,
                                      0));
    Vec roofP1 = center + Vec(-0.5 * bodyWidth, 0.5 * bodyHeight),
            roofP2 = center + Vec(0.5 * bodyWidth, 0.5 * bodyHeight),
            roofP3 = center + Vec(0, 0.5 * bodyHeight + roofHeight);
    shapes.push_back(new Triangle(roofP1, roofP2, roofP3, rand0to1(), rand0to1(), rand0to1()));
    Vec RectCenter = center + Vec(0, -(1.0 / 3.0) * bodyHeight);
    shapes.push_back(new Rect(rand0to1(), rand0to1(), rand0to1(), RectCenter, (1.0 / 3.0) * bodyWidth,
                              (1.0 / 3.0) * bodyHeight, 0));
    RectCenter = center + Vec(0.25 * bodyWidth, 0.25 * bodyHeight);
    shapes.push_back(new Rect(rand0to1(), rand0to1(), rand0to1(), RectCenter, 0.25 * bodyWidth, 0.25 * bodyHeight, 0));
    RectCenter = center + Vec(-0.25 * bodyWidth, 0.25 * bodyHeight);
    shapes.push_back(new Rect(rand0to1(), rand0to1(), rand0to1(), RectCenter, 0.25 * bodyWidth, 0.25 * bodyHeight, 0));
    rotate(center, angle);
}

void Rocket::zoom() {
    static int i = 0;
    const double sizeMax = 6;
    const double sizeMin = 2;
    if (size >= sizeMin && i == 0)
        zoomIn();
    else if (size <= sizeMax) {
        zoomOut();
        i = 1;
    } else
        i = 0;
}

void Rocket::zoomIn() {
    const double coefficient = 0.99;
    size *= coefficient;
    for (auto &item:shapes)
        item->zoom(center, coefficient);
}

void Rocket::zoomOut() {
    const double coefficient = 1.01;
    size *= coefficient;
    for (auto &item:shapes)
        item->zoom(center, coefficient);
}

void MainFigure::draw() const {


}

MainFigure::MainFigure() = default;

MainFigure::~MainFigure() = default;

