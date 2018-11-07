//
// Created by haydn on 19/10/2018.
//

#include "Map.h"


int Map::getGridSize()
{
    return gridSize;
}


Cell Map::getCell(int index)
{
    return cells[index];
}
void Map::setCell(int index, Cell newCell)
{
    cells[index] = newCell;
}