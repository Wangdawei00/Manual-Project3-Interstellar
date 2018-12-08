//
// Created by Wangdawei on 2018/12/5.
//

#include "Figure.h"

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

Car::Car(Vec v,double *ang) {
    Car::setAnchor(v);
    top=IsoTrapezoid(154,127,255,Vec(v.getX(),v.getY()+.2),.6,1,.4,*ang);
    below=Rect(255,187,127,Vec(v.getX(),v.getY()-.15),.16,.03,*ang);
    wheels.push_back(Circle(Vec(v.getX()-.4,v.getY()-.3),255,127,127));
    wheels.push_back(Circle(Vec(v.getX()+.4,v.getY()-.3),255,127,127));
}

void Car::draw(){
    top.draw();
    below.draw();
    wheels[0].draw();
    wheels[1].draw();
}

void MainFigure::draw() {

}

MainFigure::MainFigure() = default;

MainFigure::~MainFigure() = default;

