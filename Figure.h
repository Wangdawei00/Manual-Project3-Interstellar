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
    void draw() override;

private:
    vector<Circle> wheels;
    Rect top;

    double width, height;
};

#endif //MANUAL_PROJECT3_INTERSTELLAR_FIGURE_H
