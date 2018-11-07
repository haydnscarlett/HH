//
// Created by haydn on 19/10/2018.
//

#include "Cell.h"
#ifndef BASICREB0RN_MAP_H
#define BASICREB0RN_MAP_H


class Map {
public:
    int getGridSize();
    void setCell(int index, Cell newCell);
    Cell getCell(int index);
private:
    int gridSize = 8;
    Cell cells[64];
};


#endif //BASICREB0RN_MAP_H
