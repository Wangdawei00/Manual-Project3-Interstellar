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

