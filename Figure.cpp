//
// Created by Wangdawei on 2018/12/5.
//

#include "Figure.h"
#include "Shape.h"
#include <cmath>
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

void Car::draw() {

}

UFO::UFO(Vec initial) {
    bodyRadius=0.04;
    wheelUpLength=0.02;
    wheelDownLength=0.03;
    wheelHeight=0.02;
    antennaLength=0.01;
    center = initial;
    angle = 0;
    all[0] = new SemiCircle(1, 0, 0, center, bodyRadius, angle);
    Vec leftWheelCenter;
    leftWheelCenter = center.operator+(Vec(-0.02, -0.01));
    all[1] = new IsoTrapezoid(0, 0, 1, leftWheelCenter, wheelUpLength, wheelDownLength, wheelHeight, angle);
    Vec rightWheelCenter;
    rightWheelCenter = center.operator+(Vec(0.02, -0.01));
    all [2] =new IsoTrapezoid(0, 0, 1, rightWheelCenter, wheelUpLength, wheelDownLength, wheelHeight, angle);
    Vec leftAntennaCenter;
    leftAntennaCenter = center.operator+(Vec(cos(2.0 / 3.0 * pi) * bodyRadius, sin(2.0 / 3.0 * pi) * bodyRadius));
    all[3] =new Rect(0, 1, 0, leftAntennaCenter, antennaLength, 0.005, 2.0 / 3.0 * pi + angle);
    Vec rightAntennaCenter;
    rightAntennaCenter = center.operator+(Vec(cos(1.0 / 3.0 * pi) * bodyRadius, sin(1.0 / 3.0 * pi) * bodyRadius));
    all[4] =new Rect(0, 1, 0, rightAntennaCenter, antennaLength, 0.005, 1.0 / 3.0 * pi + angle);
}

void UFO::draw() {
for(int i=0;i<5;i++){
    (*all[i]).draw();
}
}

void UFO::move(Vec a) {
    center = center + a;
}

void UFO::rotate(Vec centerPoint,double angleTurnig) {
    for(int i=0;i<5;i++){
        (*all[i]).rotate(centerPoint,angleTurnig);
    }
};
void UFO::spin() {
    for(int i=0;i<5;i++){
        (*all[i]).rotate(center,0.1);
    }
}

UFO::~UFO() {
    for(int i=0;i<5;i++){
        delete (all[i]);
    }
};

void MainFigure::draw() {


}

MainFigure::MainFigure() = default;

MainFigure::~MainFigure() = default;