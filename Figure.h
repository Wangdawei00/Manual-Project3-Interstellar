//
// Created by Wangdawei on 2018/12/5.
//

#ifndef MANUAL_PROJECT3_INTERSTELLAR_FIGURE_H
#define MANUAL_PROJECT3_INTERSTELLAR_FIGURE_H

#include "vector.h"
#include "Singleton.h"

class Figure {
public:
    virtual void draw() = 0;

//    virtual ~Figure();
};

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

#endif //MANUAL_PROJECT3_INTERSTELLAR_FIGURE_H
