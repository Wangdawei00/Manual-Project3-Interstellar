#include <iostream>
#include <GL/freeglut.h>
#include "figures.h"
#include "car.h"

using namespace std;

void glDraw() {
    static point p = {-0.5, -0.5};
    Car C(p, 1, 0.75, 0.1, 0.66, 0.33);
    C.move(&p, 0.001);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    C.draw();
    glutSwapBuffers();
    glFlush();
}

void TimeStep(int n) {
    glutTimerFunc(n, TimeStep, n);
    glutPostRedisplay();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("car");
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(glDraw);
    glutTimerFunc(1, TimeStep, 1);
    glutMainLoop();
    return 0;
}