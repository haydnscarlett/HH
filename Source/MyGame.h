//
// Created by Huxy on 03/10/2018.
//

#ifndef HELLOASGE_MYGAME_H
#define HELLOASGE_MYGAME_H

#include <Engine/OGLGame.h>
#include <Windows.h>
#include <string>
#include <fstream>
#include <iostream>

#include "Constants.h"
#include "Item.h"
#include "Map.h"
#include "Verbs.h"
#include "Commands.h"
#include "Cell.h"
#include "Event.h"

class MyGame : public ASGE::OGLGame
{
public:
    MyGame();
    ~MyGame();
    bool init() override;
    void update(const ASGE::GameTime& us) override;
    void render(const ASGE::GameTime& us) override;

private:
    void keyHandler(const ASGE::SharedEventData data);
    void renderMainMenu();
    void renderInGame();
    void renderInGameVerbs(float * placeholderDimensions);
    void renderInGameInventory(float * placeholderDimensions);
    void renderInGameScore(float * placeholderDimensions);
    void renderInGameItems(float * placeholderDimensions);
    void renderInGameMessages(float * placeholderDimensions);
    void renderInGameCell();



    void setupResolution();
    void setupHauntedHouseGame();
    void setupHauntedHouseVerbs();
    void setupHauntedHouseItems();
    void setupHauntedHouseMap();
    void setupHauntedHouseEvents();
    void setupHauntedHouseInventory();
    void setupHauntedHouseCommands();


    void saveVerbList();
    void loadVerbList();

    void checkInput();
    void checkLight();
    void checkEvents();
    void processEvent();
    void performAction();
    void processCommand(int verbIndex, int objectIndex);
    bool checkInventory(int itemIndex);


    void goNorth();
    void goWest();
    void goEast();
    void goSouth();
    void goUp();
    void goDown();
    void addItem(int itemIndex);
    void leaveItem(int itemIndex);
    void examine();
    void createExitNorth();
    void createExitWest();
    void createExitEast();
    void createExitSouth();
    void revealItem();
    void teleport();
    void lightOn();
    void lightOff();
    void removeItemFromCell(int itemIndex);


    int  key_callback_id = -1;	        /**< Key Input Callback ID. */

    int game_state;

    int map;
    Map mapList;

    int cellIndex;
    Cell currentCell;

    int numberVerbs;
    Verbs verbList[26];

    int numberItems;
    Item itemList[36];

    int itemsInInventory;
    int inventory[36];

    int numberCommands;
    Commands availableCommands[45];
    int commandToProcess;


    int numberEvents;
    Event events[16];
    int eventToProcess;
    int objectIndex;

    bool light;
    int lightCounter;

    bool displayEventMessage;
    std::string eventMessage;

    bool displayAMessage;
    std::string message;

    bool firstWordComplete;
    std::string firstWord;
    std::string secondWord;
    bool checkingInput;
    bool displayVerbList;
    bool displayInventory;
    bool displayTheScore;
    bool displayLightWarning;
    bool displayLightOut;

    bool canTeleport;

};


#endif //HELLOASGE_MYGAME_H
