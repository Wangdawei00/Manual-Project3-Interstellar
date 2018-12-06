//
// Created by Wangdawei on 2018/11/22.
//

#ifndef PROJECT3_VECTOR_H
#define PROJECT3_VECTOR_H
static const double PI = 3.1415926535897932384626;
typedef class Vec {
private:
    double x, y;
public:
    explicit Vec(double x = 0, double y = 0);

    double getX() const;

    double getY() const;

    Vec operator+(Vec v);

    Vec operator-(Vec v);

    double operator*(Vec v);

    Vec operator*(double k);

    Vec operator<<(double angle);

    Vec operator>>(double angle);

    Vec &operator=(Vec v);

    Vec &operator+=(Vec v);

    Vec &operator-=(Vec v);

    Vec operator-();
} Point;

Vec operator*(double k, Vec v);

#endif //PROJECT3_VECTOR_H
