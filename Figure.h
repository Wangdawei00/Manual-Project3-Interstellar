//
// Created by Wangdawei on 2018/12/5.
//

#ifndef MANUAL_PROJECT3_INTERSTELLAR_FIGURE_H
#define MANUAL_PROJECT3_INTERSTELLAR_FIGURE_H

#include "vector.h"
#include <vector>
#include "Shape.h"

class MainFigure : public Figure {
public:
    static MainFigure &getInstance();

    void draw() const override;

private:
    MainFigure();

    ~MainFigure();

    MainFigure(MainFigure const &);

    MainFigure &operator=(MainFigure const &);
};

class Group : public Figure {
public:
    void draw() const override;

    void setAnchor(Vec v);

    const Vec &getAnchor() const;

    void move(Vec v);

    void rotate(Point center, double angle);

    virtual void specialMove() = 0;

    ~Group();

protected:
    std::vector<Shape *> shapes;
    double size;
private:
    Vec anchor;

};

class Car : public Group {
public:
    explicit Car(Vec v = Vec(0, 0), double angle = 0, double size = 1);

    void set(double w, double h);

    void specialMove() override;

private:
    double width, height;
};

class Teleported : public Group {
public:
    explicit Teleported(Vec v = Vec(0, 0), double size = 1);

    void set(double w, double h);

//    void randomColor();

    void specialMove() override;


private:
    double width, height;
};

class UFO : public Group {
public:

//    void move(Vec moveToward);

//    void rotate(Vec centerPoint, double angleTurning);

//    void spin();

    explicit UFO(Vec initial = Vec(0, 0), double angle = 0, double size = 1);

    void specialMove() override;


//    ~UFO();

private:
    Vec center;
    double angle;
    double bodyRadius;
    double wheelUpLength;
    double wheelDownLength;
    double wheelHeight;
    double antennaLength;

};

class Rocket : public Group {
public:
    explicit Rocket(Vec initial = Vec(0, 0), double angle = 0, double size = 1);

//    void rotate(Vec centerPoint, double angleTurning);

//    void zoom();

    void specialMove() override;


//    ~Rocket();

private:
    Vec center;
    double angle;
    double bodyWidth;
    double bodyHeight;
    double wingLength;
    double wingHeight;
    double jetHeight;
    double roofHeight;
    double jetUpLength;

    void zoomIn();

    void zoomOut();
};

inline double rand0to1();

#endif //MANUAL_PROJECT3_INTERSTELLAR_FIGURE_H