//
// Created by Wangdawei on 2018/12/5.
//

#include "Figure.h"

//Figure::~Figure() = default;

MainFigure &MainFigure::getInstance() {
    static MainFigure instance;
    return instance;
}

void Group::setAnchor(Vec v) {
    anchor = v;
}

const Vec &Group::getAnchor() const {
    return anchor;
}

void Car::draw() {

}

void MainFigure::draw() {

}
MainFigure::MainFigure() = default;

MainFigure::~MainFigure() = default;