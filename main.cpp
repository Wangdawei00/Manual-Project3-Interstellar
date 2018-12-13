#include <iostream>
#include "ParkingLot.h"
#include <glut.h>

using namespace std;
void glDraw() {
    static ParkingLot  park(7);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    park.drawingInitialize();
    park.draw();
    glutSwapBuffers();
    glFlush();
}

void TimeStep(int n){
    glutTimerFunc(n,TimeStep,n);
    glutPostRedisplay();
}

int main() {
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Home sweet home");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(glDraw);
    glutTimerFunc(25, TimeStep, 25);
    glutMainLoop();
    return 0;
}