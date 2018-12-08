//
// Created by Wangdawei on 2018/11/22.
//

#include <cmath>
#include "vector.h"

double Vec::getX() const {
    return this->x;
}

double Vec::getY() const {
    return y;
}

Vec::Vec(double x, double y) {
    this->x = x;
    this->y = y;
}

Vec Vec::operator+(Vec v) const {
    return Vec(x + v.getX(), y + v.getY());
}

Vec Vec::operator-(Vec v) const {
    return Vec(x - v.getX(), y - v.getY());
}

Vec Vec::operator*(double k) const {
    return Vec(k * x, k * y);
}

double Vec::operator*(Vec v) const {
    return x * v.getX() + y * v.getY();
}

Vec Vec::operator<<(double angle) const {
    Vec a1(cos(angle), -sin(angle)), a2(sin(angle), cos(angle));
    return Vec(a1 * (*this), a2 * (*this));
}

Vec Vec::operator>>(double angle) const {
    return (*this) << (-angle);
}

Vec &Vec::operator=(Vec v) {
//    Vec ret(v.getX(),v.getY());
    this->x = v.getX();
    this->y = v.getY();
    return *this;
}

Vec &Vec::operator+=(Vec v) {
    this->x += v.getX();
    this->y += v.getY();
    return *this;
}

Vec Vec::operator-() const {
    return Vec(-x, -y);
}

Vec &Vec::operator-=(Vec v) {
    (*this) += (-v);
    return (*this);
}

Vec operator*(double k, Vec v) {
    return v * k;
}

Vec &Vec::operator*=(double k) {
    (*this) = (*this) * k;
    return *this;
}