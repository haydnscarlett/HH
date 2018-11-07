//
// Created by haydn on 26/10/2018.
//

#ifndef BASICREB0RN_COMMANDS_H
#define BASICREB0RN_COMMANDS_H

#include <string>

class Commands {
public:
    Commands();
    Commands(int verbOneIndex, bool itemRequirement, bool itemRequiredInInventory, int itemIndex,
             bool secondItemRequirement, bool secondItemRequiredInInventory, int secondItemIndex,
             bool thirdItemRequirement, bool thirdItemRequiredInInventory, int thirdItemIndex, bool cellRequirement,
             int cellIndex, int actionIndex, std::string message);
    virtual ~Commands();

    int getVerbOneIndex() const;
    bool isItemRequirement() const;
    int getItemIndex() const;
    bool isCellRequirement() const;
    int getCellIndex() const;
    int getActionIndex() const;
    bool isItemRequiredInInventory() const;
    bool isSecondItemRequirement() const;
    bool isSecondItemRequiredInInventory() const;
    int getSecondItemIndex() const;
    bool isThirdItemRequirement() const;
    bool isThirdItemRequiredInInventory() const;
    int getThirdItemIndex() const;
    const std::string &getMessage() const;

private:

    int verbOneIndex;
    bool itemRequirement;
    bool itemRequiredInInventory;
    int itemIndex;
    bool secondItemRequirement;
    bool secondItemRequiredInInventory;
    int secondItemIndex;
    bool thirdItemRequirement;
    bool thirdItemRequiredInInventory;
    int thirdItemIndex;
    bool cellRequirement;
    int cellIndex;
    int actionIndex;
    std::string message;
};


#endif //BASICREB0RN_COMMANDS_H
