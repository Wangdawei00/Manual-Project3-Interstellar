//
// Created by Wangdawei on 2018/12/5.
//

#include "Figure.h"
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

Car::Car(Vec v,double *ang) {
    Car::setAnchor(v);
    Car::set(.16,.08);
    top=IsoTrapezoid(154,127,255,Vec(v.getX(),v.getY()+height/4),.375*width,.625*width,height/2,*ang);
    below=Rect(255,187,127,Vec(v.getX(),v.getY()-height*.1875),width,height*.375,*ang);
    wheels.push_back(Circle(Vec(v.getX()-width/4,v.getY()-height*.375),height/8,255,127,127));
    wheels.push_back(Circle(Vec(v.getX()+width/4,v.getY()-height*.375),height/8,255,127,127));
}

void Car::set(double w,double h) {
    width=w;
    height=h;
}

void Car::draw(){
    top.draw();
    below.draw();
    wheels[0].draw();
    wheels[1].draw();
}

Teleported::Teleported(Vec v) {
    Teleported::setAnchor(v);
    Teleported::set(.16,.08);
    rec=Rect(r,g,b,v,width,height,0);
}

void Teleported::randomColor() {
    random_device randomDevice;
    r=(randomDevice())%256;
    g=(randomDevice())%256;
    b=(randomDevice())%256;
}

void Teleported::set(double w,double h) {
    width=w;
    height=h;
}

void Teleported::draw() {
    rec.draw();
}

void MainFigure::draw() {

}

MainFigure::MainFigure() = default;

MainFigure::~MainFigure() = default;

