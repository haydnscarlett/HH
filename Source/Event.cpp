//
// Created by haydn on 01/11/2018.
//

#include "Event.h"


/**
*   @brief   Default Constructor.
*   @details
*/
Event::Event() {
    Event::cellIndex = 0;
    Event::oneOff = false;
    Event::happened = false;
    Event::outcome = 0;
    Event::itemAffected = 0;
    Event::itemRequired = 0;
    Event::itemRequiredInInventory = false;
    Event::isRandom = false;
    Event::randomMax = 0;
    Event::command = 0;
    Event::message = "";
}

/**
*   @brief   Override Constructor.
*   @details creates a event from the input values
*/
Event::Event(int cellIndex, bool oneOff, bool happened, int command, int outcome, bool isRandom,
             int randomMax, int itemAffected, std::string message, int itemRequired,
             bool itemRequiredInInventory)  {

    Event::cellIndex = cellIndex;
    Event::oneOff = oneOff;
    Event::happened = happened;
    Event::outcome = outcome;
    Event::itemAffected = itemAffected;
    Event::itemRequired = itemRequired;
    Event::itemRequiredInInventory = itemRequiredInInventory;
    Event::isRandom = isRandom;
    Event::randomMax = randomMax;
    Event::command = command;
    Event::message = message;
}

/**
*   @brief   Destructor.
*   @details Remove any non-managed memory and callbacks.
*/
Event::~Event() {

}

/**
*   @brief   Get Cell Index
*   @details This function is designed to get the Cell Index required for the event
*   @return  int
*/
int Event::getCellIndex() const {
    return cellIndex;
}

/**
*   @brief   Is Happened
*   @details This function is designed to check if a one off event has happened
*   @return  bool
*/
bool Event::isHappened() const {
    return happened;
}

/**
*   @brief   Is Happened
*   @details This function is designed to set a one off event as happened
*   @return  bool
*/
void Event::setHappened(bool happened) {
    Event::happened = happened;
}

/**
*   @brief   Get Outcome
*   @details This function is designed to return the outcome of the event when triggered
*   @return  int
*/
int Event::getOutcome() const {
    return outcome;
}

/**
*   @brief   Get Item Affected
*   @details This function is designed to return the index of the affected item of an event
*   @return  int
*/
int Event::getItemAffected() const {
    return itemAffected;
}

/**
*   @brief   Is Random
*   @details This function is designed to check if an event is Random
*   @return  bool
*/
bool Event::isIsRandom() const {
    return isRandom;
}

/**
*   @brief   Get Random Max
*   @details This function is designed to return the max value for a random event check
*   @return  int
*/
int Event::getRandomMax() const {
    return randomMax;
}

/**
*   @brief   Get Message
*   @details This function is designed to return the message from the event
*   @return  std::string
*/
const std::string &Event::getMessage() const {
    return message;
}

/**
*   @brief   Get Item Required
*   @details This function is designed to return the index of an item required for an event
*   @return  int
*/
int Event::getItemRequired() const {
    return itemRequired;
}

/**
*   @brief   Get Command
*   @details This function is designed to return the index of the command required to trigger an event
*   @return  int
*/
int Event::getCommand() const {
    return command;
}

/**
*   @brief   Is One Off
*   @details This function is designed to check if an event is a one off
*   @return  bool
*/
bool Event::isOneOff() const {
    return oneOff;
}

/**
*   @brief   Is Item Required In Inventory
*   @details This function is designed to check if an item is required in inventory for the event
*   @return  bool
*/
bool Event::isItemRequiredInInventory() const {
    return itemRequiredInInventory;
}



