//
// Created by haydn on 26/10/2018.
//

#include "Commands.h"

/**
*   @brief   Default Constructor.
*   @details
*/
Commands::Commands() {
    Commands::verbOneIndex = 0;
    Commands::itemRequirement = false;
    Commands::itemRequiredInInventory = false;
    Commands::itemIndex = 0;
    Commands::secondItemRequirement = false;
    Commands::secondItemRequiredInInventory = false;
    Commands::secondItemIndex = 0;
    Commands::thirdItemRequirement = false;
    Commands::thirdItemRequiredInInventory = false;
    Commands::thirdItemIndex = 0;
    Commands::cellRequirement = false;
    Commands::cellIndex = 0;
    Commands::actionIndex = 0;
    Commands::message = "";
}

/**
*   @brief   Override Constructor.
*   @details creates a command from the input values
*/
Commands::Commands(int verbOneIndex, bool itemRequirement, bool itemRequiredInInventory, int itemIndex,
                   bool secondItemRequirement, bool secondItemRequiredInInventory, int secondItemIndex,
                   bool thirdItemRequirement, bool thirdItemRequiredInInventory, int thirdItemIndex,
                   bool cellRequirement, int cellIndex, int actionIndex, std::string message){

    Commands::verbOneIndex = verbOneIndex;
    Commands::itemRequirement = itemRequirement;
    Commands::itemRequiredInInventory = itemRequiredInInventory;
    Commands::itemIndex = itemIndex;
    Commands::secondItemRequirement = secondItemRequirement;
    Commands::secondItemRequiredInInventory = secondItemRequiredInInventory;
    Commands::secondItemIndex = secondItemIndex;
    Commands::thirdItemRequirement = thirdItemRequirement;
    Commands::thirdItemRequiredInInventory = thirdItemRequiredInInventory;
    Commands::thirdItemIndex = thirdItemIndex;
    Commands::cellRequirement = cellRequirement;
    Commands::cellIndex = cellIndex;
    Commands::actionIndex = actionIndex;
    Commands::message = message;
}

/**
*   @brief   Destructor.
*   @details Remove any non-managed memory and callbacks.
*/
Commands::~Commands() {

}

/**
*   @brief   Get Verb One Index
*   @details This function is designed to get the index number of the verb relevant to the command
*   @return  int
*/
int Commands::getVerbOneIndex() const {
    return verbOneIndex;
}

/**
*   @brief   Get Item Requirement
*   @details This function is designed to check if an item is required for the command
*   @return  bool
*/
bool Commands::isItemRequirement() const {
    return itemRequirement;
}

/**
*   @brief   Get Item Index
*   @details This function is designed to get the index number of the first Item relevant to the command
*   @return  int
*/
int Commands::getItemIndex() const {
    return itemIndex;
}

/**
*   @brief   Get Item Requirement
*   @details This function is designed to check if an item is required for the command
*   @return  bool
*/
bool Commands::isCellRequirement() const {
    return cellRequirement;
}

/**
*   @brief   Get Cell Index
*   @details This function is designed to get the index number of the Cell relevant to the command
*   @return  int
*/
int Commands::getCellIndex() const {
    return cellIndex;
}

/**
*   @brief   Get Action Index
*   @details This function is designed to get the index number of the Action outcome for the command
*   @return  int
*/
int Commands::getActionIndex() const {
    return actionIndex;
}

/**
*   @brief   Get Item Required In Inventory
*   @details This function is designed to check if an item is required to be in Inventory for the command
*   @return  bool
*/
bool Commands::isItemRequiredInInventory() const {
    return itemRequiredInInventory;
}

/**
*   @brief   Get Message
*   @details This function is designed to get any messsage the command requires to communicate
*   @return  std::string
*/
const std::string &Commands::getMessage() const {
    return message;
}

/**
*   @brief   Get Second Item Requirement
*   @details This function is designed to check if a Second item is required for the command
*   @return  bool
*/
bool Commands::isSecondItemRequirement() const {
    return secondItemRequirement;
}

/**
*   @brief   Get Second Item Required In Inventory
*   @details This function is designed to check if a Second item is required to be in Inventory for the command
*   @return  bool
*/
bool Commands::isSecondItemRequiredInInventory() const {
    return secondItemRequiredInInventory;
}

/**
*   @brief   Get Second Item Index
*   @details This function is designed to get the index number of the Second Item relevant to the command
*   @return  int
*/
int Commands::getSecondItemIndex() const {
    return secondItemIndex;
}

/**
*   @brief   Get Third Item Requirement
*   @details This function is designed to check if a Third item is required for the command
*   @return  bool
*/
bool Commands::isThirdItemRequirement() const {
    return thirdItemRequirement;
}

/**
*   @brief   Get Third Item Required In Inventory
*   @details This function is designed to check if a Third item is required to be in Inventory for the command
*   @return  bool
*/
bool Commands::isThirdItemRequiredInInventory() const {
    return thirdItemRequiredInInventory;
}

/**
*   @brief   Get Third Item Index
*   @details This function is designed to get the index number of the Third Item relevant to the command
*   @return  int
*/
int Commands::getThirdItemIndex() const {
    return thirdItemIndex;
}

