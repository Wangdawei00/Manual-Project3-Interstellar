//
// Created by Wangdawei on 2018/12/5.
//

#include "Shape.h"
#include <glut.h>
#include <cmath>

Color::Color(double r, double g, double b) {
    this->r = r;
    this->b = b;
    this->g = g;
}

double Color::getB() const {
    return b;
}

double Color::getG() const {
    return g;
}

double Color::getR() const {
    return r;
}

void Color::set(double r, double g, double b) {
    this->g = g;
    this->b = b;
    this->r = r;
}

Shape::Shape(double r, double g, double b) {
    color = Color(r, g, b);
}

void Shape::setColor(double r, double g, double b) {
    color.set(r, g, b);
}


Quadrilateral::Quadrilateral(double r, double g, double b, Point p1, Point p2, Point p3, Point p4) : Shape(r, g, b) {
    point1 = p1;
    point2 = p2;
    point3 = p3;
    point4 = p4;
}

void Quadrilateral::draw() const {
    glColor3d(color.getR(), color.getG(), color.getB());
    glBegin(GL_QUADS);
    glVertex2d(point1.getX(), point1.getY());
    glVertex2d(point2.getX(), point2.getY());
    glVertex2d(point3.getX(), point3.getY());
    glVertex2d(point4.getX(), point4.getY());
    glEnd();
}

void Quadrilateral::move(Vec v) {
    point1 += v;
    point2 += v;
    point4 += v;
    point3 += v;
}

void Quadrilateral::rotate(Point center, double angle) {
    point1 = (point1 - center << angle) + center;
    point2 = (point2 - center << angle) + center;
    point3 = (point3 - center << angle) + center;
    point4 = (point4 - center << angle) + center;
}

void Quadrilateral::zoom(Point center, double coefficient) {
    point1 = (point1 - center) * coefficient + center;
    point2 = (point2 - center) * coefficient + center;
    point3 = (point3 - center) * coefficient + center;
    point4 = (point4 - center) * coefficient + center;
}

Rect::Rect(double r, double g, double b, Point center, double length, double width, double angle) :
        Quadrilateral(r, g, b) {
    this->center = center;
    this->length = length;
    rotationAngle = angle;
    Vec v1(length / 2, width / 2), v2(-length / 2, width / 2);
    point1 = center + v1;
    point2 = center + v2;
    point3 = center * 2 - point1;
    point4 = center * 2 - point2;
    Quadrilateral::rotate(center, rotationAngle);
}

void Rect::zoom(Point center, double coefficient) {
    this->center = (this->center - center) * coefficient + center;
    length *= coefficient;
    width *= coefficient;
    Quadrilateral::zoom(center, coefficient);
}

void Rect::rotate(Point center, double angle) {
    Quadrilateral::rotate(center, angle);
    this->rotationAngle += angle;
    this->center = (this->center - center << angle) + center;
}

IsoTrapezoid::IsoTrapezoid(double r, double g, double b, Point center, double upLength, double downLength,
                           double height, double angle) : Quadrilateral(r, g, b) {
    this->center = center;
    this->downLength = downLength;
    this->upLength = upLength;
    this->height = height;
    rotationAngle = angle;
    point1 = center + Vec(upLength / 2, height / (upLength + downLength) * upLength);
    point2 = center + Vec(-upLength / 2, height / (upLength + downLength) * upLength);
    point3 = center + Vec(-downLength / 2, -height / (upLength + downLength) * downLength);
    point4 = center + Vec(downLength / 2, -height / (upLength + downLength) * downLength);
    Quadrilateral::rotate(center, angle);
}

void IsoTrapezoid::zoom(Point center, double coefficient) {
    this->center = (this->center - center) * coefficient + center;
    upLength *= coefficient;
    downLength *= coefficient;
    height *= coefficient;
    Quadrilateral::zoom(center, coefficient);
}

void IsoTrapezoid::rotate(Point center, double angle) {
    Quadrilateral::rotate(center, angle);
    this->rotationAngle += angle;
    this->center = (this->center - center << angle) + center;
}


void Triangle::move(Vec v) {
    point3 += v;
    point1 += v;
    point2 += v;
}


void Triangle::rotate(Point center, double angle) {
    point1 = (point1 - center << angle) + center;
    point2 = (point2 - center << angle) + center;
    point3 = (point3 - center << angle) + center;
}

void Triangle::zoom(Point center, double coefficient) {
    point1 = (point1 - center) * coefficient + center;
    point2 = (point2 - center) * coefficient + center;
    point3 = (point3 - center) * coefficient + center;
}

Triangle::Triangle(Point p1, Point p2, Point p3, double r, double g, double b) : Shape(r, g, b) {
    point1 = p1;
    point2 = p2;
    point3 = p3;
}

void Triangle::draw() const {
    glColor3d(color.getR(), color.getG(), color.getB());
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2d(point1.getX(), point1.getY());
    glVertex2d(point2.getX(), point2.getY());
    glVertex2d(point3.getX(), point3.getY());
    glEnd();
}

Circle::Circle(Point p1, double radius, double r, double g, double b) : Shape(r, g, b) {
    this->radius = radius;
    center = p1;
}

void Circle::zoom(Point center, double coefficient) {
    this->center = (this->center - center) * coefficient + center;
    radius *= coefficient;
}

void Circle::draw() const {
    int iter = 2000;
    glColor3d(color.getR(), color.getG(), color.getB());
    glBegin(GL_POLYGON);
    for (int i = 0; i < iter; ++i) {
        glVertex2d(radius * cos(2 * pi / iter * i) + center.getX(), radius * sin(2 * pi / iter * i) + center.getY());
    }
    glEnd();
    glFlush();
}

void Circle::rotate(Point center, double angle) {
    this->center = (this->center - center << angle) + center;
}

void Circle::move(Vec v) {
    center += v;
}

SemiCircle::SemiCircle(double r, double g, double b, Point center, double radius, double angle) : Shape(r, g, b) {
    this->center = center;
    rotationAngle = angle;
    this->radius = radius;
}

void SemiCircle::rotate(Point center, double angle) {
    this->center = (this->center - center << angle) + center;
    rotationAngle += angle;
}

void SemiCircle::move(Vec v) {
    center += v;
}

void SemiCircle::draw() const {
    glColor3d(color.getR(), color.getG(), color.getB());
    glBegin(GL_POLYGON);
    int iter = 2000;
    for (int i = 0; i < iter; ++i) {
        glVertex2d(radius * cos(pi / iter * i + rotationAngle) + center.getX(),
                   radius * sin(pi / iter * i + rotationAngle) + center.getY());
    }
    glEnd();
    glFlush();
}

void SemiCircle::zoom(Point center, double coefficient) {
    this->center = (this->center - center) * coefficient + center;
    radius *= coefficient;
}

Shape::~Shape() = default;

SemiCircle::~SemiCircle() = default;

//
Quadrilateral::~Quadrilateral() = default;

//
Circle::~Circle() = default;

//
Triangle::~Triangle() = default;

//
IsoTrapezoid::~IsoTrapezoid() = default;

Rect::~Rect() = default;