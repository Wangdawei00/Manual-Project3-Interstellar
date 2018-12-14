//
// Created by Wangdawei on 2018/12/14.
//
#include "Figure.h"

ParkingLot *MainFigure::parkingLot;

void MainFigure::initPark(int column) {
    parkingLot = new ParkingLot(column);
}

void MainFigure::glDraw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    MainFigure::parkingLot->drawingInitialize();
    MainFigure::parkingLot->draw();
    glutSwapBuffers();
    glFlush();
}

void MainFigure::TimeStep(int n) {
    glutTimerFunc((unsigned int) n, TimeStep, n);
    glutPostRedisplay();
}

void MainFigure::draw(int *argc, char **argv) {
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow(argv[0]);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(glDraw);
    glutTimerFunc(50, TimeStep, 50);
    glutMainLoop();
}

MainFigure::MainFigure() = default;

MainFigure::~MainFigure() = default;

