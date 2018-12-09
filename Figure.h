//
// Created by Wangdawei on 2018/12/5.
//

#ifndef MANUAL_PROJECT3_INTERSTELLAR_FIGURE_H
#define MANUAL_PROJECT3_INTERSTELLAR_FIGURE_H

#include "vector.h"
#include <vector>
//#include "Singleton.h"
using namespace std;

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

//    virtual ~Group() = 0;

protected:
    vector<Shape> shapes;
private:
    Vec anchor;

};

class Car : public Group {
public:
    explicit Car(Vec v, double *ang);

    void set(double w, double h);


private:
    double width, height;
};

class Teleported : public Group {
    explicit Teleported(Vec v);

    void set(double w, double h);


    void randomColor();

private:
    double width, height;
    double r, g, b;
};

class UFO : public Group {
public:
//    void draw() override;

    void move(Vec moveToward);

    void rotate(Vec centerPoint, double angleTurning);

    void spin();

    explicit UFO(Vec initial);

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
    explicit Rocket(Vec initial);

//    void draw() override;

    void move(Vec moveToward);

    void rotate(Vec centerPoint, double angleTurning);

    void zoom(double coefficient);

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
};

inline double rand0to1();
#endif //MANUAL_PROJECT3_INTERSTELLAR_FIGURE_H
