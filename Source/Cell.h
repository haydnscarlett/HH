//
// Created by haydn on 26/10/2018.
//

#pragma once
#include <string>
#ifndef BASICREB0RN_CELL_H
#define BASICREB0RN_CELL_H


class Cell {
public:
    Cell();
    Cell(std::string newCellName, std::string newCellDescription, bool exitNorth, bool exitWest,
         bool exitEast, bool exitSouth,bool up, int upExit, bool down,int downExit,bool newLit);

    virtual ~Cell();

    std::string getCellName();
    std::string getCellDescription();
    bool getExit(int index);
    void setExit(int index, bool newExit);
    bool isUp();
    int getUpExit();
    bool isDown();
    int getDownExit();
    bool isLit();

private:

    std::string cellName;
    std::string cellDescription;
    bool exit[4];
    bool up;
    int upExit;
    bool down;
    int downExit;
    bool lit;

};


#endif //BASICREB0RN_CELL_H
