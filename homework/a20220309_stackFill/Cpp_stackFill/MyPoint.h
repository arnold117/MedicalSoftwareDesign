//
// Created by Arnold on 2022/3/14.
//

#ifndef CPP_STACKFILL_MYPOINT_H
#define CPP_STACKFILL_MYPOINT_H

#include "MyStack.h"

class MyPoint {
private:
    int row;
    int col;

public:
    MyPoint(int row, int col) : row(row), col(col) {}
    MyPoint() = default;

    int getRow() const {
        return row;
    }

    int getCol() const {
        return col;
    }
};


#endif //CPP_STACKFILL_MYPOINT_H
