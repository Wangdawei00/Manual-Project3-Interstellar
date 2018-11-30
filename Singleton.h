//
// Created by Wangdawei on 2018/11/23.
//

#ifndef PROJECT3_SINGLETON_H
#define PROJECT3_SINGLETON_H

class Singleton {
public:
    static Singleton &getInstance();

//    static void deleteInstance();

protected:
    Singleton();

    ~Singleton();

    Singleton(Singleton const &);

    Singleton &operator=(Singleton const &);

//    static Singleton *instance;
};

#endif //PROJECT3_SINGLETON_H
