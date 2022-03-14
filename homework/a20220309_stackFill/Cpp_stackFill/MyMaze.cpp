//
// Created by Arnold on 2022/3/14.
//

#include "MyMaze.h"

void MyMaze::printMaze() {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            cout << maze[i][j] << "  ";
            cout.setf(ios_base::unitbuf);
        }
        cout << endl;
    }
}

void MyMaze::fill() {
    myStack.push(startPoint);

    while (!myStack.isEmpty()) {
        MyPoint curLocation = myStack.top();
        const int curRow = curLocation.getRow();
        const int curCol = curLocation.getCol();
        maze[curRow][curCol] = 3;

        if (maze[curRow-1][curCol] == 0) {
            // if point can move north
            myStack.push(MyPoint(curRow-1, curCol));
            maze[curRow][curCol] = 1;
        } else if (maze[curRow][curCol-1] == 0) {
            // if point can move west
            myStack.push(MyPoint(curRow, curCol-1));
            maze[curRow][curCol] = 1;
        } else if (maze[curRow+1][curCol] == 0) {
            // if point can move south
            myStack.push(MyPoint(curRow+1, curCol));
            maze[curRow][curCol] = 1;
        } else if (maze[curRow][curCol+1] == 0) {
            // if point can move east
            myStack.push(MyPoint(curRow, curCol+1));
            maze[curRow][curCol] = 1;
        } else {
            myStack.pop();
        }

        cout << "moving..." << endl;
        Sleep(500);
        printMaze();

        if (isFull()){
            break;
        }
    }
}

MyMaze::MyMaze(const MyPoint &startPoint) : startPoint(startPoint) {}

bool MyMaze::isFull() {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            if (maze[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}
