//
// Created by haydn on 26/10/2018.
//

#include "Item.h"

/**
*   @brief   Default Constructor.
*   @details
*/
Item::Item() {
    item = "";
    examinable= false;
    examination = "";
    locationNumber = -1;
    hidden= false;
    ableToTake = false;
}

/**
*   @brief   Override Constructor.
*   @details creates an item from the input values
*/
Item::Item(const std::string item, bool examinable, const std::string examination, int locationNumber, bool hidden,
           bool ableToTake) : item(item), examinable(examinable), examination(examination),
                              locationNumber(locationNumber), hidden(hidden), ableToTake(ableToTake) {

    Item:: item = item;
    Item::examinable = examinable;
    Item:: examination = examination;
    Item::locationNumber = locationNumber;
    Item::hidden = hidden;
    Item::ableToTake = ableToTake;
}
/**
*   @brief   Destructor.
*   @details Remove any non-managed memory and callbacks.
*/
Item::~Item() {

}

/**
*   @brief   Gets the Item
*   @details This function is designed to get the item name as a string
*   @return  std::string
*/
std::string Item::getItem()
{
    return item;
}

/**
*   @brief   Gets the Examination Text
*   @details This function is designed to get the item examination as a string
*   @return  std::string
*/
std::string Item::getExamination()
{
    return examination;
}

/**
*   @brief   Get Examinable
*   @details This function is designed to get the examinable bool for an item
*   @return  bool
*/
bool Item::getExaminable()
{
    return examinable;
}

/**
*   @brief   Get Hidden
*   @details This function is designed to get the hidden bool for an item
*   @return  bool
*/
bool Item::getHidden()
{
    return hidden;
}

/**
*   @brief   Set Hidden
*   @details This function is designed to set the hidden bool for an item
*   @return  void
*/
void Item::setHidden(bool newHidden)
{
    hidden = newHidden;
}

/**
*   @brief   Gets the Items Location Number
*   @details This function is designed to get the items location number
*   @return  int
*/
int Item::getLocationNumber()
{
    return locationNumber;
}

/**
*   @brief   Sets the Items Location Number
*   @details This function is designed to set the items location number
*   @return  void
*/
void Item::setLocationNumber(int newLocationNumber)
{
    locationNumber = newLocationNumber;
}

/**
*   @brief   Gets the Item ability to pick up
*   @details This function is designed to get the items ability to pick up bool
*   @return  bool
*/
bool Item::getAbleToTake() {
    return ableToTake;
}


