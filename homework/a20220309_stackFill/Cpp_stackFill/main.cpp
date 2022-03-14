#include "MyMaze.h"

int main() {
    MyMaze myMaze(MyPoint(3, 3));
    myMaze.printMaze();
    myMaze.fill();

    return 0;
}
