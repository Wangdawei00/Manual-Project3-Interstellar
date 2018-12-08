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

    void draw() override;

private:
    MainFigure();

    ~MainFigure();

    MainFigure(MainFigure const &);

    MainFigure &operator=(MainFigure const &);
};

class Group : public Figure {
public:
    void draw() override = 0;

    void setAnchor(Vec v);

    const Vec &getAnchor() const;

private:
    Vec anchor;
};

class Car : public Group {
public:
    explicit Car(Vec v,double *ang);
    void set(double w,double h);
    void draw() override;

private:
    vector<Circle> wheels;
    Rect below;
    IsoTrapezoid top;
    double width, height;
};

class Teleported : public Group{
    explicit Teleported(Vec v);
    void set(double w,double h);
    void draw() override;
    void randomColor();
private:
    Rect rec;
    double width, height;
    double r,g,b;
};

 class UFO :public  Group{
public:void draw() override;
    void move(Vec moveToward);
    void rotate(Vec centerPoint,double angleTurning);
    void spin();
    explicit  UFO(Vec initial);
    ~UFO();

private:
     Shape* all[5] ;
Vec center;
double angle;
double bodyRadius;
double wheelUpLength;
double wheelDownLength;
double wheelHeight;
double antennaLength;

};

#endif //MANUAL_PROJECT3_INTERSTELLAR_FIGURE_H
