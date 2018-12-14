#include <iostream>
#include "Figure.h"
#include <GL/glut.h>
#include <ctime>

using namespace std;

int main(int argc, char **argv) {
    srand((unsigned int) time(nullptr));
    int column = 0;
    for (int i = 1; i < argc; ++i) {
        if (strcmp("--size", argv[i]) == 0) {
            column = strtol(argv[i + 1], nullptr, 10);
            break;
        }
    }
    if (column == 0) {
        cerr << "You didn't correctly initialize the Parking Lot!\nPlease refer to the README carefully!" << endl;
    }
    MainFigure::initPark(column);
    MainFigure::draw(&argc, argv);
    return 0;
}