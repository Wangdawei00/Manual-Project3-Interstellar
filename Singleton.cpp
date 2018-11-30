//
// Created by Wangdawei on 2018/11/23.
//

#include "Singleton.h"

Singleton::Singleton() = default;

Singleton::~Singleton() = default;

Singleton &Singleton::getInstance() {
    static Singleton s;
//    if (s == nullptr) s = new Singleton();
    return s;
}


Singleton &Singleton::operator=(Singleton const &) = default;

Singleton::Singleton(Singleton const &) = default;
