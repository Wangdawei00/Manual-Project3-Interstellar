//
// Created by Wangdawei on 2018/12/5.
//

#ifndef MANUAL_PROJECT3_INTERSTELLAR_SHAPE_H
#define MANUAL_PROJECT3_INTERSTELLAR_SHAPE_H
static const double pi = 3.1415926535897932;

#include "Figure.h"
#include "vector.h"

class Color {
public:
    void set(double r, double g, double b);

    explicit Color(double r = 255, double g = 255, double b = 255);

    double getR();

    double getB();

    double getG();

private:
    double r, g, b;
};

class Shape : public Figure {
    void draw() override = 0;

    virtual void move(Vec v) = 0;

    virtual void rotate(Point center, double angle) = 0;

protected:
    explicit Shape(double r = 0, double g = 0, double b = 0);

    Color color;
};

class Quadrilateral : public Shape {
public:
    void draw() override;

    void move(Vec v) override;

    void rotate(Point center, double angle) override;

    explicit Quadrilateral(double r = 0, double g = 0, double b = 0, Point p1 = Vec(0, 0), Point p2 = Vec(0, 1),
                           Point p3 = Vec(1, 0), Point p4 = Vec(1, 1));

protected:
    Point point1, point2, point3, point4;//counterclockwise

};

class Parellelogram : public Quadrilateral {
public:
    void move(Vec v) override;

    void rotate(Point center, double angle) override;

    explicit Parellelogram(double r = 0, double g = 0, double b = 0, Point center = Vec(0, 0), double angle1 = 0,
                           double halfDiagonal1 = 0.25, double angle2 = pi / 2, double halfDiagonal2 = 0.25);

protected:
    double angle1, angle2;// the angle of two adjacent sides;
    double halfDiagonal1, halfDiagonal2;
    Point center;
};

class Triangle : public Shape {
public:
    void draw() override;

    void move(Vec v) override;

    void rotate(Point center, double angle) override;

    explicit Triangle(Point p1 = Vec(0, 0), Point p2 = Vec(1, 0), Point p3 = Vec(0.5, 0.866), double r = 0,
                      double g = 0,
                      double b = 0);

private:
    Point point1, point2, point3;
};

class Rect : public Parellelogram {
public:
    explicit Rect(double r = 255, double g = 255, double b = 255, Point center = Vec(0, 0),
                  Point vertex = Vec(0.5, 0.5),
                  double angle = pi / 2);

private:
    Point vertex;
    double diagonalAngle;
};

class Circle : public Shape {
public:
    void draw() override;

    void move(Vec v) override;

    void rotate(Point center, double angle) override;

    explicit Circle(Point p1 = Vec(0, 0), double radius = 1, double r = 255, double g = 255, double b = 255);

private:
    Point center;
    double radius;
};

#endif //MANUAL_PROJECT3_INTERSTELLAR_SHAPE_H
