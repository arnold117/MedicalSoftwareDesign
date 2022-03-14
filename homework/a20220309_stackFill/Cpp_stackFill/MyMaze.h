//
// Created by Arnold on 2022/3/14.
//

#ifndef CPP_STACKFILL_MYMAZE_H
#define CPP_STACKFILL_MYMAZE_H

#define MAZE_SIZE 10

#include "MyPoint.h"

class MyMaze {
public:
    int maze[MAZE_SIZE][MAZE_SIZE] = {
            {2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
            {2, 0, 0, 0, 0, 0, 0, 0, 0, 2},
            {2, 0, 0, 0, 0, 0, 0, 0, 0, 2},
            {2, 0, 0, 0, 0, 0, 0, 0, 0, 2},
            {2, 0, 0, 0, 0, 0, 0, 0, 0, 2},
            {2, 0, 0, 0, 0, 0, 0, 0, 0, 2},
            {2, 0, 0, 0, 0, 0, 0, 0, 0, 2},
            {2, 0, 0, 0, 0, 0, 0, 0, 0, 2},
            {2, 0, 0, 0, 0, 0, 0, 0, 0, 2},
            {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}
    };
    MyStack<MyPoint> myStack;
    MyPoint startPoint;

    void printMaze();
    void fill();
    bool isFull();
    MyMaze(const MyPoint &startPoint);
};


#endif //CPP_STACKFILL_MYMAZE_H
