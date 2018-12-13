//
// Created by Wangdawei on 2018/12/6.
//

#include <iostream>
#include <GL/glut.h>
#include <ctime>
#include "Figure.h"
#include "ParkingLot.h"

using namespace std;

void TimeStep(int n) {
    glutTimerFunc((unsigned int) n, TimeStep, n);
    glutPostRedisplay();
}

void glDraw() {
    static ParkingLot parkingLot(5);
    parkingLot.drawingInitialize();
    parkingLot.specialMove();
    parkingLot.draw();
//    static UFO ufo(Vec(0, 0), 0, 1);
//    static Car car(Vec(0.5, 0.5), 0, 3);
//    static Rocket rocket(Vec(-0.5, -0.5), 0, 5);
//    static Teleported teleported(Vec(-0.5, 0.5), 3);
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    ufo.move(Vec(0,0.001));
//    ufo.draw();
//    ufo.specialMove();
//    teleported.specialMove();
//    teleported.draw();
//    ufo.specialMove();
//    rocket.specialMove();
//    rocket.draw();
//    car.draw();
//    ufo.draw();
    glutSwapBuffers();
    glFlush();
}

int main(int argc, char *argv[]) {
    int a = 9;
    srand((unsigned int) time(nullptr));
    glutInit(&argc, argv);
//    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("test");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(glDraw);
    glutTimerFunc(25, TimeStep, 25);
    glutMainLoop();
}