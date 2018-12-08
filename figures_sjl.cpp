//
// Created by starrynight on 2018/12/5.
//

#include "figures.h"
#include <GL/freeglut.h>
#include <cmath>

const GLdouble PI=3.1415927;
Trapezium::Trapezium(point aIn, point bIn, point cIn, point dIn, float red, float green, float blue) {
    p1=aIn;p2=bIn;p3=cIn;p4=dIn;
    r=red;g=green;b=blue;
}
Trapezium::Trapezium() {
    p1.x=0;p1.y=0;
    p2.x=1;p2.y=0;
    p3.x=1;p3.y=1;
    p4.x=0;p4.y=1;
    r=g=b=1;
}
void Trapezium::draw() {
    glColor3f(r,g,b);glBegin(GL_QUADS);
    glVertex2d(p1.x,p1.y);glVertex2d(p2.x,p2.y);glVertex2d(p3.x,p3.y);glVertex2d(p4.x,p4.y);
    glEnd();
}
Circle::Circle(point cIn, double rIn, float red, float green, float blue) {
    c=cIn;radius=rIn;
    r=red;g=green;b=blue;
}
void Circle::draw() {
    int n=75;
    glColor3f(r,g,b);glBegin(GL_POLYGON);
    for (int i=0;i<n;i++){
        glVertex2d(c.x+radius*cos(2*PI/n*i),c.y+radius*sin(2*PI/n*i));
    }
    glEnd();
}