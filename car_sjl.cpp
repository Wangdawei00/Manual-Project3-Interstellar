//
// Created by starrynight on 2018/12/5.
//

#include "car.h"
#include "figures.h"
Car::Car(point pIn, double carLength, double carHeight, double wheelRadius, double windowLength,double ceilingLength)
{
    p=pIn;
    point r1={p.x+(1.0/4.0)*carLength,p.y};F[2] = new Circle(r1,wheelRadius,0,0,0);
    point r2={p.x+(3.0/4.0)*carLength,p.y};F[3]=new Circle(r2,wheelRadius,0,0,0);
    point p2={p.x+carLength,p.y};point p3={p.x+carLength,p.y+0.5*carHeight};point p4={p.x,p.y+0.5*carHeight};
    F[0]=new Trapezium(p,p2,p3,p4,0,0,1);
    point p1={p.x+0.5*(carLength-windowLength),p.y+0.5*carHeight};p2={p.x+0.5*(carLength+windowLength),p.y+0.5*carHeight};
    p4={p1.x+0.5*(windowLength-ceilingLength),p.y+carHeight};p3={p1.x+0.5*(windowLength+ceilingLength),p.y+carHeight};
    F[1]=new Trapezium(p1,p2,p3,p4,1,0,0);
    p1={p.x+0.6*carLength,p.y+0.7*carHeight};F[4]= new Circle(p1,0.075,0,0.3,1);
}
void Car::draw() {
    for (int i=0;i<5;i++) {
        F[i]->draw();
    }
}
void Car::move(point *px,double dx) {
    int static i=1;
    if ((*px).x>=0 && i==1) {i=0;}
    else if ((*px).x<=-1 && i==0) {i=1;}
    if (i==1) goRight(px,dx);
    else  goLeft(px,dx);
}
void Car::goRight(point *px,double dx) {
    (*px).x+=dx;
}
void Car::goLeft(point *px,double dx) {
    (*px).x-=dx;
}
Car::~Car() {
    for (int i = 0; i < 5 ; i++) {
        F[i]= nullptr;
        delete F[i];
    }
}