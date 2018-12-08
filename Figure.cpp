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
    center=initial;angle=0;
}

void UFO::draw() {
    SemiCircle body(1,0,0,center,0.04, angle);
    body.draw();
   Vec leftWheelCenter;
   leftWheelCenter=center.operator+(Vec(-0.02,-0.01));
   IsoTrapezoid leftWheel(0,0, 1,leftWheelCenter ,0.02, 0.03,0.02, angle);
    leftWheel.draw();
    Vec rightWheelCenter;
   rightWheelCenter=center.operator+(Vec(0.02,-0.01));
    IsoTrapezoid rightWheel(0,0, 1,rightWheelCenter ,0.02, 0.03,0.02, angle);
    rightWheel.draw();
    Vec leftAntennaCenter;
    leftAntennaCenter=center.operator+(Vec(cos(2.0/3.0*pi)*0.04,sin(2.0/3.0*pi)*0.04));
    Rect leftAntenna(0,1,0,leftAntennaCenter, 0.01,0.005,2.0/3.0*pi+angle );
    leftAntenna.draw();
    Vec rightAntennaCenter;
    rightAntennaCenter=center.operator+(Vec(cos(1.0/3.0*pi)*0.04,sin(1.0/3.0*pi)*0.04));
    Rect rightAntenna(0,1,0,rightAntennaCenter, 0.01 , 0.005,1.0/3.0*pi+angle );
    rightAntenna.draw();
}
void UFO::move(Vec a){
    center=center+a;
}
void UFO::rotate(double angleTurnig) {
    angle+=angleTurnig;
    center<<angleTurnig;
};
UFO::~UFO()=default;

void MainFigure::draw() {


}

MainFigure::MainFigure() = default;

MainFigure::~MainFigure() = default;