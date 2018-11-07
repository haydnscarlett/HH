//
// Created by haydn on 26/10/2018.
//
#pragma once
#include <string>
#ifndef BASICREB0RN_ITEM_H
#define BASICREB0RN_ITEM_H


class Item {

public:
    Item();

    Item(const std::string item, bool examinable, const std::string examination, int locationNumber, bool hidden,
         bool ableToTake);

    virtual ~Item();

    std::string getItem();
    std::string getExamination();
    bool getExaminable();
    int getLocationNumber();
    void setLocationNumber(int newLocationNumber);
    bool getHidden();
    void setHidden(bool newExaminable);
    bool getAbleToTake();

private:
    std::string item;
    bool examinable;
    std::string examination;
    int locationNumber;
    bool hidden;
    bool ableToTake;

};


#endif //BASICREB0RN_ITEM_H
