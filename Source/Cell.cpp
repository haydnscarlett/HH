//
// Created by haydn on 26/10/2018.
//

#include "Cell.h"

/**
*   @brief   Default Constructor.
*   @details
*/
Cell::Cell() {
    cellName = "";
    cellDescription = "";
    exit[0] = false;
    exit[1] = false;
    exit[2] = false;
    exit[3] = false;
    up = false;
    upExit = -1;
    down = false;
    downExit = -1;
    lit = false;

}

/**
*   @brief   Override Constructor.
*   @details creates a cell from the input values
*/
Cell::Cell(std::string newCellName, std::string newCellDescription, bool exitNorth, bool exitWest,
                      bool exitEast, bool exitSouth,bool up, int upExit, bool down,int downExit, bool newLit)
{
    cellName = newCellName;
    cellDescription = newCellDescription;
    exit[0] = exitNorth;
    exit[1] = exitWest;
    exit[2] = exitEast;
    exit[3] = exitSouth;
    Cell::up = up;
    Cell::upExit = upExit;
    Cell::down = down;
    Cell::downExit = downExit;
    lit = newLit;

}

/**
*   @brief   Destructor.
*   @details Remove any non-managed memory and callbacks.
*/
Cell::~Cell() {

}

/**
*   @brief   Get the Cell Name
*   @details This function is designed to get the cell name as a string
*   @return  std::string
*/
std::string Cell::getCellName()
{
    return  cellName;
}

/**
*   @brief   Get Exit
*   @details This function is designed to get the exit bool to check if the player can go that way
*   @return  bool
*/
bool Cell::getExit(int index)
{
    return exit[index];
}

/**
*   @brief   Set Exit
*   @details This function is designed to set the exit bool for a specific exit in a cell
*   @return  void
*/
void Cell::setExit(int index, bool newExit)
{
    exit[index] = newExit;
}

/**
*   @brief   Get Up Exit
*   @details This function is designed to get the exit represented by the up exit
*   @return  int
*/
int Cell::getUpExit()
{
    return upExit;
}

/**
*   @brief   Is Down
*   @details This function is designed to get the exit bool for down to check if the cell represents stairs
*   @return  bool
*/
bool Cell::isDown()  {
    return down;
}

/**
*   @brief   Get Down Exit
*   @details This function is designed to get the exit represented by the down exit
*   @return  int
*/
int Cell::getDownExit()
{
    return downExit;
}

/**
*   @brief   Is Up
*   @details This function is designed to get the exit bool for up to check if the cell represents stairs
*   @return  bool
*/
bool Cell::isUp()
{
    return up;
}

/**
*   @brief   Get the Cell Description
*   @details This function is designed to get the cell description as a string
*   @return  std::string
*/
std::string Cell::getCellDescription()
{
    return cellDescription;
}

/**
*   @brief   Is Lit
*   @details This function is designed to check if the cell is lit
*   @return  bool
*/
bool Cell::isLit()
{
    return lit;
}




