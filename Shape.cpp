//
// Created by Wangdawei on 2018/12/5.
//

#include "Shape.h"

#include <GL/freeglut.h>
#include <cmath>


Shape::Shape(double r, double g, double b) {
    color = Color(r, g, b);
}

Quadrilateral::Quadrilateral(double r, double g, double b, Point p1, Point p2, Point p3, Point p4) : Shape(r, g, b) {
    point1 = p1;
    point2 = p2;
    point3 = p3;
    point4 = p4;
}

Triangle::Triangle(Point p1, Point p2, Point p3, double r, double g, double b) : Shape(r, g, b) {
    point1 = p1;
    point2 = p2;
    point3 = p3;
}

Circle::Circle(Point p1, double radius, double r, double g, double b) : Shape(r, g, b) {
    this->radius = radius;
    center = p1;
}

void Triangle::draw() {
    glColor3d(color.getR(), color.getG(), color.getB());
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2d(point1.getX(), point1.getY());
    glVertex2d(point2.getX(), point2.getY());
    glVertex2d(point3.getX(), point3.getY());
    glEnd();
}

void Quadrilateral::draw() {
    glColor3d(color.getR(), color.getG(), color.getB());
    glBegin(GL_QUADS);
    glVertex2d(point1.getX(), point1.getY());
    glVertex2d(point2.getX(), point2.getY());
    glVertex2d(point3.getX(), point3.getY());
    glVertex2d(point4.getX(), point4.getY());
    glEnd();
}

void Circle::draw() {
    int iter = 2000;
    glColor3d(color.getR(), color.getG(), color.getB());
    glBegin(GL_POLYGON);
    for (int i = 0; i < iter; ++i) {
        glVertex2d(radius * cos(2 * pi / iter * i) + center.getX(), radius * sin(2 * pi / iter * i) + center.getY());
    }
    glEnd();
    glFlush();
}

Parellelogram::Parellelogram(double r, double g, double b, Point center, double angle1, double halfDiagonal1,
                             double angle2, double halfDiagonal2) : Quadrilateral(r, g, b) {
    this->center = center;
    this->angle1 = angle1;
    this->angle2 = angle2;
    this->halfDiagonal1 = halfDiagonal1;
    this->halfDiagonal2 = halfDiagonal2;
    point1 = Vec(center.getX() + halfDiagonal1 * cos(angle1), center.getY() + halfDiagonal1 * sin(angle1));
    point2 = Vec(center.getX() - halfDiagonal2 * cos(angle2), center.getY() + halfDiagonal2 * sin(angle2));
    point3 = Vec(center.getX() - halfDiagonal1 * cos(angle1), center.getY() - halfDiagonal1 * sin(angle1));
    point4 = Vec(center.getX() + halfDiagonal2 * cos(angle2), center.getY() - halfDiagonal2 * sin(angle2));
}


Rect::Rect(double r, double g, double b, Point center, Point vertex, double angle) : Parellelogram(r, g, b) {
    this->center = center;
    this->vertex = vertex;
    diagonalAngle = angle;
    point1 = vertex;
    point2 = (vertex - center << diagonalAngle) + center;
    point3 = center * 2 - point1;
    point4 = center * 2 - point2;
}


void Quadrilateral::move(Vec v) {
    point1 += v;
    point2 += v;
    point4 += v;
    point3 += v;
}


void Circle::move(Vec v) {
    center += v;
}

void Parellelogram::move(Vec v) {
    Quadrilateral::move(v);
    center += v;
}

void Triangle::move(Vec v) {
    point3 += v;
    point1 += v;
    point2 += v;
}

void Circle::rotate(Point center, double angle) {
    this->center = (this->center - center << angle) + center;
}

void Quadrilateral::rotate(Point center, double angle) {
    point1 = (point1 - center << angle) + center;
    point2 = (point1 - center << angle) + center;
    point3 = (point1 - center << angle) + center;
    point4 = (point1 - center << angle) + center;
}

void Parellelogram::rotate(Point center, double angle) {
    Quadrilateral::rotate(center, angle);
    this->center = (this->center - center << angle) + center;
}

void Triangle::rotate(Point center, double angle) {
    point1 = (point1 - center << angle) + center;
    point2 = (point1 - center << angle) + center;
    point3 = (point1 - center << angle) + center;
}

void Color::set(double r, double g, double b) {
    this->g = g;
    this->b = b;
    this->r = r;
}

Color::Color(double r, double g, double b) {
    this->r = r;
    this->b = b;
    this->g = g;
}

double Color::getB() {
    return b;
}

double Color::getG() {
    return g;
}

double Color::getR() {
    return r;
}

void Shape::setColor(double r, double g, double b) {
    color.set(r, g, b);
}