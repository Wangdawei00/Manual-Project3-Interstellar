//
// Created by Wangdawei on 2018/11/22.
//

#ifndef PROJECT3_VECTOR_H
#define PROJECT3_VECTOR_H
static const double PI = 3.1415926535897932384626;
class Vec {
private:
    double x, y;
public:
    Vec();

    Vec(double x, double y);

    double getX();

    double getY();

    Vec operator+(Vec v);

    Vec operator-(Vec v);

    double operator*(Vec v);

    Vec operator*(double k);

    Vec operator<<(double angle);

    Vec operator>>(double angle);

    Vec& operator=(Vec v);
};

#endif //PROJECT3_VECTOR_H
