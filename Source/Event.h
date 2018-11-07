//
// Created by haydn on 01/11/2018.
//

#ifndef BASICREB0RN_EVENT_H
#define BASICREB0RN_EVENT_H

#include <string>

class Event {
public:
    Event();

    Event(int cellIndex, bool oneOff, bool happened, int command, int outcome, bool isRandom,
          int randomMax, int itemAffected, std::string message, int itemRequired, bool itemRequiredInInventory);

    virtual ~Event();

    int getCellIndex() const;
    bool isOneOff() const;
    bool isHappened() const;
    void setHappened(bool happened);
    int getOutcome() const;
    int getItemAffected() const;
    bool isIsRandom() const;
    int getRandomMax() const;
    int getCommand() const;
    const std::string &getMessage() const;
    int getItemRequired() const;
    bool isItemRequiredInInventory() const;

private:
    int cellIndex;
    bool oneOff;
    bool happened;
    int command;
    int outcome;
    bool isRandom;
    int randomMax;
    int itemAffected;
    std::string message;
    int itemRequired;
    bool itemRequiredInInventory;
};


#endif //BASICREB0RN_EVENT_H
