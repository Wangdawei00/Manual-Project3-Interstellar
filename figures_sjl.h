//
// Created by starrynight on 2018/12/5.
//

#ifndef EX3_FIGURES_H
#define EX3_FIGURES_H

typedef struct _point {double x;double y;}point;
class Figures {
public:
    virtual void draw()=0;

protected:
    float r,g,b;
};
class Circle: public Figures{
public:
    Circle(point cIn,double rIn,float r, float g, float b);
    void draw() override;
private:
    point c;
    double radius;
};
class Trapezium:public Figures{
public:
    Trapezium(point aIn,point bIn,point cIn,point dIn,float red,float green,float blue);
    Trapezium();
    void draw() override;

private:
    point p1,p2,p3,p4;
};

#endif //EX3_FIGURES_H
