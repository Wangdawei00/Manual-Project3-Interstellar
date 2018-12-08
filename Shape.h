//
// Created by Wangdawei on 2018/12/5.
//

#ifndef MANUAL_PROJECT3_INTERSTELLAR_SHAPE_H
#define MANUAL_PROJECT3_INTERSTELLAR_SHAPE_H
static const double pi = 3.1415926535897932;

//#include "Figure.h"
#include "vector.h"

class Figure {
public:
    virtual void draw() = 0;

    virtual ~Figure() = 0;
};

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
    void setColor(double r, double g, double b);

    void draw() override = 0;

    virtual void move(Vec v) = 0;

    virtual void zoom(Point center, double coefficient) = 0;

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

    void zoom(Point center, double coefficient) override;


    explicit Quadrilateral(double r = 0, double g = 0, double b = 0, Point p1 = Vec(0, 0), Point p2 = Vec(0, 1),
                           Point p3 = Vec(1, 0), Point p4 = Vec(1, 1));

protected:
    Point point1, point2, point3, point4;//counterclockwise

};

class IsoTrapezoid : public Quadrilateral {
public:
    explicit IsoTrapezoid(double r = 255, double g = 255, double b = 255, Point center = Vec(0, 0),
                          double upLength = 0.1,
                          double downLength = 0.2, double height = 0.3, double angle = pi / 2);

    void rotate(Point center, double angle) override;

    void zoom(Point center, double coefficient) override;

private:
    Point center;
    double rotationAngle;
    double upLength, downLength, height;
};


class Rect : public Quadrilateral {
public:
    explicit Rect(double r = 255, double g = 255, double b = 255, Point center = Vec(0, 0),
                  double length = 0.5, double width = 0.25, double angle = pi / 2);

    void rotate(Point center, double angle) override;

    void zoom(Point center, double coefficient) override;

private:
    Point center;
    double length, width;
    double rotationAngle;
};

class Triangle : public Shape {
public:
    void draw() override;

    void move(Vec v) override;

    void rotate(Point center, double angle) override;

    explicit Triangle(Point p1 = Vec(0, 0), Point p2 = Vec(1, 0), Point p3 = Vec(0.5, 0.866), double r = 0,
                      double g = 0, double b = 0);

    void zoom(Point center, double coefficient) override;

private:
    Point point1, point2, point3;
};

class Circle : public Shape {
public:
    void draw() override;

    void move(Vec v) override;

    void rotate(Point center, double angle) override;

    explicit Circle(Point p1 = Vec(0, 0), double radius = 1, double r = 255, double g = 255, double b = 255);

    void zoom(Point center, double coefficient) override;

private:
    Point center;
    double radius;
};


class SemiCircle : public Shape {
public:
    explicit SemiCircle(double r = 255, double g = 255, double b = 255, Point center = Vec(0, 0), double angle = 0);

    void rotate(Point center, double angle) override;

    void zoom(Point center, double coefficient) override;

    void move(Vec v) override;

    void draw() override;

private:
    double radius;
    double rotationAngle;
    Point center;

};

#endif //MANUAL_PROJECT3_INTERSTELLAR_SHAPE_H
