//
// Created by Wangdawei on 2018/12/5.
//

#ifndef MANUAL_PROJECT3_INTERSTELLAR_FIGURE_H
#define MANUAL_PROJECT3_INTERSTELLAR_FIGURE_H

#include "vector.h"
#include <vector>
#include "Shape.h"
#include "slot.h"
#include "ParkingLot.h"


using namespace std;

class MainFigure {
public:
//    static MainFigure &getInstance();

    static void draw(int *argc, char **argv);

    static void initPark(int column);

private:
    static ParkingLot *parkingLot;

    static void glDraw();

    static void TimeStep(int n);

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

    void setDestination(const Slot *desti);

    const Vec &getDestination() const;

    const Slot *retSlot() const;

    void move(Vec v);

    void rotate(Point center, double angle);

    virtual void specialMove() = 0;

    virtual ~Group();

protected:
    std::vector<Shape *> shapes;
    double size;
private:
    Vec anchor;
    Vec destination;
    const Slot *desti;
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

    void specialMove() override;

private:
    double width, height;
};

class UFO : public Group {
public:
    explicit UFO(Vec initial = Vec(0, 0), double angle = 0, double size = 1);

    void specialMove() override;

private:
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

    void specialMove() override;

private:
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