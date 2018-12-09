//
// Created by Wangdawei on 2018/12/5.
//

#include "Figure.h"
#include "Shape.h"
#include <cmath>
#include <random>
//Figure::~Figure() = default;

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
    Car::setAnchor(v);
    Car::set(.16, .08);
    top = IsoTrapezoid(154, 127, 255, Vec(v.getX(), v.getY() + height / 4), .375 * width, .625 * width, height / 2,
                       *ang);
    below = Rect(255, 187, 127, Vec(v.getX(), v.getY() - height * .1875), width, height * .375, *ang);
    wheels.push_back(Circle(Vec(v.getX() - width / 4, v.getY() - height * .375), height / 8, 255, 127, 127));
    wheels.push_back(Circle(Vec(v.getX() + width / 4, v.getY() - height * .375), height / 8, 255, 127, 127));
}

void Car::set(double w, double h) {
    width = w;
    height = h;
}

void Car::draw() {
    top.draw();
    below.draw();
    wheels[0].draw();
    wheels[1].draw();
}

Teleported::Teleported(Vec v) {
    Teleported::setAnchor(v);
    Teleported::set(.16, .08);
    rec = Rect(r, g, b, v, width, height, 0);
}

void Teleported::randomColor() {
    random_device randomDevice;
    r = (randomDevice()) % 256;
    g = (randomDevice()) % 256;
    b = (randomDevice()) % 256;
}

void Teleported::set(double w, double h) {
    width = w;
    height = h;
}

void Teleported::draw() {
    rec.draw();
}

UFO::UFO(Vec initial) {
    bodyRadius = 0.04;
    wheelUpLength = 0.02;
    wheelDownLength = 0.03;
    wheelHeight = 0.02;
    antennaLength = 0.01;
    center = initial;
    angle = 0;
    all[0] = new SemiCircle(1, 0, 0, center, bodyRadius, angle);
    Vec leftWheelCenter;
    leftWheelCenter = center.operator+(Vec(-0.02, -0.01));
    all[1] = new IsoTrapezoid(0, 0, 1, leftWheelCenter, wheelUpLength, wheelDownLength, wheelHeight, angle);
    Vec rightWheelCenter;
    rightWheelCenter = center.operator+(Vec(0.02, -0.01));
    all[2] = new IsoTrapezoid(0, 0, 1, rightWheelCenter, wheelUpLength, wheelDownLength, wheelHeight, angle);
    Vec leftAntennaCenter;
    leftAntennaCenter = center.operator+(Vec(cos(2.0 / 3.0 * pi) * bodyRadius, sin(2.0 / 3.0 * pi) * bodyRadius));
    all[3] = new Rect(0, 1, 0, leftAntennaCenter, antennaLength, 0.005, 2.0 / 3.0 * pi + angle);
    Vec rightAntennaCenter;
    rightAntennaCenter = center.operator+(Vec(cos(1.0 / 3.0 * pi) * bodyRadius, sin(1.0 / 3.0 * pi) * bodyRadius));
    all[4] = new Rect(0, 1, 0, rightAntennaCenter, antennaLength, 0.005, 1.0 / 3.0 * pi + angle);
}

void UFO::draw() {
    for (int i = 0; i < 5; i++) {
        (*all[i]).draw();
    }
}

void UFO::move(Vec a) {
    center = center + a;
}

void UFO::rotate(Vec centerPoint, double angleTurnig) {
    for (int i = 0; i < 5; i++) {
        (*all[i]).rotate(centerPoint, angleTurnig);
    }
};

void UFO::spin() {
    for (int i = 0; i < 5; i++) {
        (*all[i]).rotate(center, 0.1);
    }
}

UFO::~UFO() {
    for (int i = 0; i < 5; i++) {
        delete (all[i]);
    }
};

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
    all[0] = new Rect(1, 0, 0, center, bodyHeight, bodyWidth, angle);
    Vec wingP1 = center.operator+(Vec(-wingLength - 0.5 * bodyWidth, -0.5 * bodyHeight)),
            wingP2 = center.operator+(Vec(-0.5 * bodyWidth, -0.5 * bodyHeight)),
            wingP3 = center.operator+(Vec(-0.5 * bodyWidth, -0.5 * bodyHeight + wingHeight));
    all[1] = new Triangle(wingP1, wingP2, wingP3, 0, 0, 0);
    wingP1 = center.operator+(Vec(0.5 * bodyWidth, -0.5 * bodyHeight));
    wingP2 = center.operator+(Vec(0.5 * bodyWidth + wingLength, -0.5 * bodyHeight));
    wingP3 = center.operator+(Vec(0.5 * bodyWidth, -0.5 * bodyHeight + wingHeight));
    all[2] = new Triangle(wingP1, wingP2, wingP3, 0, 0, 0);
    Vec IsoTrapezoidCenter = center.operator+(Vec(0, -0.5 * bodyHeight - 0.5 * jetHeight));
    all[3] = new IsoTrapezoid(0, 0, 0, IsoTrapezoidCenter, jetUpLength, bodyWidth, jetHeight, angle);
    Vec roofP1 = center.operator+(Vec(-0.5 * bodyWidth, 0.5 * bodyHeight)),
            roofP2 = center.operator+(Vec(0.5 * bodyWidth, 0.5 * bodyHeight)),
            roofP3 = center.operator+(Vec(0, 0.5 * bodyHeight + roofHeight));
    all[4] = new Triangle(roofP1, roofP2, roofP3, 0, 0, 1);
    Vec RectCenter = center.operator+(Vec(0, -(1.0 / 3.0) * bodyHeight));
    all[5] = new Rect(0, 1, 0, RectCenter, (1.0 / 3.0) * bodyHeight, (1.0 / 3.0) * bodyWidth, angle);
    RectCenter = center.operator+((Vec(0.25 * bodyWidth, 0.25 * bodyHeight)));
    all[6] = new Rect(0, 1, 0, RectCenter, 0.25 * bodyHeight, 0.25 * bodyWidth, angle);
    RectCenter = center.operator+(Vec(-0.25 * bodyWidth, 0.25 * bodyHeight));
    all[7] = new Rect(0, 1, 0, RectCenter, 0.25 * bodyHeight, 0.25 * bodyWidth, angle);
}

void Rocket::draw() {
    for (int i = 0; i < 8; ++i) {
        (*all[i]).draw();
    }
}

void Rocket::move(Vec moveToward) {
    for (int i = 0; i < 8; ++i) {
        (*all[i]).move(moveToward);
    }
}

void Rocket::rotate(Vec centerPoint, double angleTurning) {
    for (int i = 0; i < 8; ++i) {
        (*all[i]).rotate(centerPoint, angleTurning);
    }
}

void Rocket::zoom(double coefficient) {
    for (int i = 0; i < 8; ++i) {
        (*all[i]).zoom(center, coefficient);
    }
}

Rocket::~Rocket() {
    for (int i = 0; i < 8; ++i) {
        delete (all[i]);
    }
}

void MainFigure::draw() {


}

MainFigure::MainFigure() = default;

MainFigure::~MainFigure() = default;

