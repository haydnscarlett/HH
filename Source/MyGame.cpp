//
// Created by Huxy on 03/10/2018.
//

#include "MyGame.h"
#include <Engine/DebugPrinter.h>
#include <Engine/Input.h>
#include <Engine/InputEvents.h>
#include <Engine/Keys.h>
#include <Engine/FileIO.h>
#include <Engine/Platform.h>
#include <Engine/Sprite.h>

/**
*   @brief   Default Constructor.
*   @details Sets rand seed.
*/
MyGame::MyGame() {
  std::srand(time(NULL));
}

/**
*   @brief   Destructor.
*   @details Remove any non-managed memory and callbacks.
*/
MyGame::~MyGame() {

  this->inputs->unregisterCallback(key_callback_id);
}

/**
*   @brief   Initialises the game.
*   @details The game window is created and all assets required to
			 run the game are loaded. The keyHandler and clickHandler
			 callback should also be set in the initialise function.
*   @return  True if the game initialised correctly.
*/
bool MyGame::init(){
  setupResolution();
  if (!initAPI())
    return false;


  setupHauntedHouseGame();

  renderer->setWindowTitle("Write your own Adventure");
  renderer->setWindowedMode(ASGE::Renderer::WindowMode::WINDOWED);

  // input handling functions
  inputs->use_threads = false;

  key_callback_id = inputs->addCallbackFnc(
          ASGE::E_KEY, &MyGame::keyHandler, this);






  return true;
}

/**
*   @brief   Processes any key inputs
*   @details This function is added as a callback to handle the game's
			 keyboard input. For this game, calls to this function
			 are thread safe, so you may alter the game's state as you
			 see fit.
*   @param   data The event data relating to key input.
*   @see     KeyEvent
*   @return  void
*/
void MyGame::keyHandler(const ASGE::SharedEventData data){
  auto key = static_cast<const ASGE::KeyEvent*>(data.get());

  if (key->key == ASGE::KEYS::KEY_ESCAPE)
  {
    signalExit();
  }

  if (key->key == ASGE::KEYS::KEY_ENTER &&
      key->action == ASGE::KEYS::KEY_PRESSED &&
      key->mods == 0x0004)
  {
    if (renderer->getWindowMode() == ASGE::Renderer::WindowMode::WINDOWED)
    {
      renderer->setWindowedMode(ASGE::Renderer::WindowMode::FULLSCREEN);
    }
    else
    {
      renderer->setWindowedMode(ASGE::Renderer::WindowMode::WINDOWED);
    }
  }
  if (!checkingInput && game_state == IN_GAME)
  {

    // Player string input handling
    if (key->key == ASGE::KEYS::KEY_SPACE && key->action == ASGE::KEYS::KEY_PRESSED)
    {
      if(firstWordComplete)
      {
        secondWord += " ";
      } else {
        firstWordComplete = true;
      }
    }
    if (key->key == ASGE::KEYS::KEY_A && key->action == ASGE::KEYS::KEY_PRESSED)
    {
      if(firstWordComplete)
      {
        secondWord += "A";
      } else{
        firstWord += "A";
      }
    }
    if (key->key == ASGE::KEYS::KEY_B && key->action == ASGE::KEYS::KEY_PRESSED)
    {

      if(firstWordComplete)
      {
        secondWord += "B";
      } else{
        firstWord += "B";
      }
    }
    if (key->key == ASGE::KEYS::KEY_C && key->action == ASGE::KEYS::KEY_PRESSED)
    {
      if(firstWordComplete)
      {
        secondWord += "C";
      } else{
        firstWord += "C";
      }
    }
    if (key->key == ASGE::KEYS::KEY_D && key->action == ASGE::KEYS::KEY_PRESSED)
    {
      if(firstWordComplete)
      {
        secondWord += "D";
      } else{
        firstWord += "D";
      }
    }
    if (key->key == ASGE::KEYS::KEY_E && key->action == ASGE::KEYS::KEY_PRESSED)
    {
      if(firstWordComplete)
      {
        secondWord += "E";
      } else{
        firstWord += "E";
      }
    }
    if (key->key == ASGE::KEYS::KEY_F && key->action == ASGE::KEYS::KEY_PRESSED)
    {
      if(firstWordComplete)
      {
        secondWord += "F";
      } else{
        firstWord += "F";
      }
    }
    if (key->key == ASGE::KEYS::KEY_G && key->action == ASGE::KEYS::KEY_PRESSED)
    {
      if(firstWordComplete)
      {
        secondWord += "G";
      } else{
        firstWord += "G";
      }
    }
    if (key->key == ASGE::KEYS::KEY_H && key->action == ASGE::KEYS::KEY_PRESSED)
    {
      if(firstWordComplete)
      {
        secondWord += "H";
      } else{
        firstWord += "H";
      }
    }
    if (key->key == ASGE::KEYS::KEY_I && key->action == ASGE::KEYS::KEY_PRESSED)
    {
      if(firstWordComplete)
      {
        secondWord += "I";
      } else{
        firstWord += "I";
      }
    }
    if (key->key == ASGE::KEYS::KEY_J && key->action == ASGE::KEYS::KEY_PRESSED)
    {
      if(firstWordComplete)
      {
        secondWord += "J";
      } else{
        firstWord += "J";
      }
    }
    if (key->key == ASGE::KEYS::KEY_K && key->action == ASGE::KEYS::KEY_PRESSED)
    {
      if(firstWordComplete)
      {
        secondWord += "K";
      } else{
        firstWord += "K";
      }
    }
    if (key->key == ASGE::KEYS::KEY_L && key->action == ASGE::KEYS::KEY_PRESSED)
    {
      if(firstWordComplete)
      {
        secondWord += "L";
      } else{
        firstWord += "L";
      }
    }
    if (key->key == ASGE::KEYS::KEY_M && key->action == ASGE::KEYS::KEY_PRESSED)
    {
      if(firstWordComplete)
      {
        secondWord += "M";
      } else{
        firstWord += "M";
      }
    }
    if (key->key == ASGE::KEYS::KEY_N && key->action == ASGE::KEYS::KEY_PRESSED)
    {
      if(firstWordComplete)
      {
        secondWord += "N";
      } else{
        firstWord += "N";
      }
    }
    if (key->key == ASGE::KEYS::KEY_O && key->action == ASGE::KEYS::KEY_PRESSED)
    {
      if(firstWordComplete)
      {
        secondWord += "O";
      } else{
        firstWord += "O";
      }
    }
    if (key->key == ASGE::KEYS::KEY_P && key->action == ASGE::KEYS::KEY_PRESSED)
    {
      if(firstWordComplete)
      {
        secondWord += "P";
      } else{
        firstWord += "P";
      }
    }
    if (key->key == ASGE::KEYS::KEY_Q && key->action == ASGE::KEYS::KEY_PRESSED)
    {
      if(firstWordComplete)
      {
        secondWord += "Q";
      } else{
        firstWord += "Q";
      }
    }
    if (key->key == ASGE::KEYS::KEY_R && key->action == ASGE::KEYS::KEY_PRESSED)
    {
      if(firstWordComplete)
      {
        secondWord += "R";
      } else{
        firstWord += "R";
      }
    }
    if (key->key == ASGE::KEYS::KEY_S && key->action == ASGE::KEYS::KEY_PRESSED)
    {
      if(firstWordComplete)
      {
        secondWord += "S";
      } else{
        firstWord += "S";
      }
    }
    if (key->key == ASGE::KEYS::KEY_T && key->action == ASGE::KEYS::KEY_PRESSED)
    {
      if(firstWordComplete)
      {
        secondWord += "T";
      } else{
        firstWord += "T";
      }
    }
    if (key->key == ASGE::KEYS::KEY_U && key->action == ASGE::KEYS::KEY_PRESSED)
    {
      if(firstWordComplete)
      {
        secondWord += "U";
      } else{
        firstWord += "U";
      }
    }
    if (key->key == ASGE::KEYS::KEY_V && key->action == ASGE::KEYS::KEY_PRESSED)
    {
      if(firstWordComplete)
      {
        secondWord += "V";
      } else{
        firstWord += "V";
      }
    }
    if (key->key == ASGE::KEYS::KEY_W && key->action == ASGE::KEYS::KEY_PRESSED)
    {
      if(firstWordComplete)
      {
        secondWord += "W";
      } else{
        firstWord += "W";
      }
    }
    if (key->key == ASGE::KEYS::KEY_X && key->action == ASGE::KEYS::KEY_PRESSED)
    {
      if(firstWordComplete)
      {
        secondWord += "X";
      } else{
        firstWord += "X";
      }
    }
    if (key->key == ASGE::KEYS::KEY_Y && key->action == ASGE::KEYS::KEY_PRESSED)
    {
      if(firstWordComplete)
      {
        secondWord += "Y";
      } else{
        firstWord += "Y";
      }
    }
    if (key->key == ASGE::KEYS::KEY_Z && key->action == ASGE::KEYS::KEY_PRESSED)
    {
      if(firstWordComplete)
      {
        secondWord += "Z";
      } else{
        firstWord += "Z";
      }
    }
    if (key->key == ASGE::KEYS::KEY_SLASH && key->action == ASGE::KEYS::KEY_PRESSED && key->mods == 0x0001)
    {
      if(firstWordComplete)
      {
        secondWord += "?";
      } else{
        firstWord += "?";
      }
    }
    if (key->key == ASGE::KEYS::KEY_BACKSPACE && key->action == ASGE::KEYS::KEY_PRESSED)
    {
      if(firstWordComplete)
      {
        if (!secondWord.empty())
        {
          secondWord.erase (secondWord.end()-1);
          if (secondWord.empty())
          {
            firstWordComplete = false;
          }
        }
      } else{ if (!firstWord.empty())
        {
          firstWord.erase (firstWord.end()-1);
        }
      }
    }
    if (key->key == ASGE::KEYS::KEY_ENTER &&
        key->action == ASGE::KEYS::KEY_PRESSED)
    {
      checkInput();
      checkEvents();
      performAction();
      checkingInput = true;
    }

  }
  else if(checkingInput)
  {
    if (key->key == ASGE::KEYS::KEY_ENTER &&
        key->action == ASGE::KEYS::KEY_PRESSED)
    {
      checkingInput = false;
      displayInventory = false;
      displayVerbList = false;
      displayAMessage = false;
      firstWordComplete = false;
      displayTheScore = false;
      displayEventMessage = false;
      message = "";
      eventMessage = "";
      firstWord = "";
      secondWord = "";
      commandToProcess = 0;
    }
  }

  //Menu Handling
  if (key->key == ASGE::KEYS::KEY_1 &&
      key->action == ASGE::KEYS::KEY_PRESSED
      && game_state == MAIN_SCREEN)
  {
    game_state = IN_GAME;
  }

  if (key->key == ASGE::KEYS::KEY_2 &&
      key->action == ASGE::KEYS::KEY_PRESSED
      && game_state == MAIN_SCREEN)
  {
    signalExit();
  }
}

/**
*   @brief   Updates the scene
*   @details Prepares the renderer subsystem before drawing the
		     current frame. Once the current frame is has finished
		     the buffers are swapped accordingly and the image shown.
*   @return  void
*/
void MyGame::update(const ASGE::GameTime &us){
  //do some stuff / what's going on here?
  return;
}

/**
*   @brief   Renders the scene
*   @details Renders all the game objects to the current frame.
Once the current frame is has finished the buffers are
swapped accordingly and the image shown.
*   @return  void
*/
void MyGame::render(const ASGE::GameTime &us){
  // if in the main menu
  if (game_state == MAIN_SCREEN)
  {
    //display main menu
    renderMainMenu();
  }
    // else if in game
  else if (game_state == IN_GAME)
  {
    // display game
    renderInGame();
  }
  return;
}

/**
*   @brief   Sets the game window resolution
*   @details This function is designed to create the window size, any
             aspect ratio scaling factors and safe zones to ensure the
			 game frames when resolutions are changed in size.
*   @return  void
*/
void MyGame::setupResolution(){
  game_height = GetSystemMetrics(SM_CYSCREEN);
  game_width = GetSystemMetrics(SM_CXSCREEN);
}

/**
*   @brief   Main menu
*   @details This function is used to display the main menu
*   @see     KeyEvent
*   @return  void
*/
void MyGame::renderMainMenu(){
  // Set Background colour
  renderer->setClearColour(ASGE::COLOURS::MIDNIGHTBLUE);
  // renders the main menu text
  renderer->renderText(
          "WELCOME TO WRITE YOUR OWN ADVENTURE \n Press Esc to quit at any time.",
          game_width * 0.35, game_height * 0.20f, 1.4f, ASGE::COLOURS::GHOSTWHITE);

  renderer->renderText("1: PLAY GAME",
                       game_width * 0.4, game_height * 0.35f, 1.2f, ASGE::COLOURS::GHOSTWHITE);

  renderer->renderText("2: EXIT",
                       game_width * 0.4, game_height * 0.38f, 1.2f, ASGE::COLOURS::GHOSTWHITE);






}

/**
*   @brief   In Game
*   @details This function is used to render the game objects
*   @see     KeyEvent
*   @return  void
*/
void MyGame::renderInGame()
{

  float placeholderDimensions[2];
  placeholderDimensions[0] = 0.28f;
  placeholderDimensions[1] =  0.3f;
  std::string currentInput = ("What will you do: " + firstWord + " " + secondWord);

  renderInGameCell();
  if(displayVerbList)
  {
    renderInGameVerbs(placeholderDimensions);
  }
  else if(displayInventory)
  {
    renderInGameInventory(placeholderDimensions);
  }
  else if(displayTheScore)
  {
    renderInGameScore(placeholderDimensions);
  }
  else{

    renderInGameItems(placeholderDimensions);
    renderInGameMessages(placeholderDimensions);

    renderer->renderText(currentInput.c_str(),
                         game_width * 0.3, game_height * 0.78f, 1.2f, ASGE::COLOURS::GHOSTWHITE);
  }
}

/**
*   @brief   In Game Cell
*   @details This function is used to render the current cell information
*   @see     KeyEvent
*   @return  void
*/
void MyGame::renderInGameCell(){
  std::string currentCellName = ("Location: " + currentCell.getCellName());
  std::string currentCellDescription = currentCell.getCellDescription();


  std::string exits = ("Exits: ");
  if (currentCell.getExit(0))
  {
    exits += "N, ";
  }
  if (currentCell.getExit(1))
  {
    exits += "W, ";
  }
  if (currentCell.getExit(2))
  {
    exits += "E, ";
  }
  if (currentCell.getExit(3))
  {
    exits += "S, ";
  }
  if (currentCell.isUp())
  {
    exits += "U, ";
  }
  if (currentCell.isDown())
  {
    exits += "D, ";
  }

  renderer->setClearColour(ASGE::COLOURS::MIDNIGHTBLUE);

  renderer->renderText("*********************************************************************",
                       game_width * 0.25, game_height * 0.03f, 1.0f, ASGE::COLOURS::GHOSTWHITE);
  renderer->renderText(currentCellName.c_str(),
                       game_width * 0.25, game_height * 0.08f, 1.2f, ASGE::COLOURS::GHOSTWHITE);
  renderer->renderText(currentCellDescription.c_str(),
                       game_width * 0.25, game_height * 0.13f, 1.0f, ASGE::COLOURS::GHOSTWHITE);
  renderer->renderText(exits.c_str(),
                       game_width * 0.25, game_height * 0.18f, 1.0f, ASGE::COLOURS::GHOSTWHITE);
  renderer->renderText("*********************************************************************",
                       game_width * 0.25, game_height * 0.23f, 1.0f, ASGE::COLOURS::GHOSTWHITE);
}

/**
*   @brief   In Game Messages
*   @details This function is used to render the game messages
*   @see     KeyEvent
*   @return  void
*/
void MyGame::renderInGameMessages(float * placeholderDimensions){
  if(displayEventMessage)
  {
    renderer->renderText(eventMessage.c_str(),
                         game_width * placeholderDimensions[0], game_height * placeholderDimensions[1], 1.0f, ASGE::COLOURS::GHOSTWHITE);
    placeholderDimensions[1] += 0.025f;
  }
  if(displayAMessage)
  {
    renderer->renderText(message.c_str(),
                         game_width * placeholderDimensions[0], game_height * placeholderDimensions[1], 1.0f, ASGE::COLOURS::GHOSTWHITE);
    placeholderDimensions[1] += 0.025f;
  }
  if(displayLightWarning)
  {
    renderer->renderText("The candle is waning!",
                         game_width * .65f, game_height * 0.08f, 1.0f, ASGE::COLOURS::GHOSTWHITE);
    placeholderDimensions[1] += 0.025f;
  }
  if(displayLightOut)
  {
    renderer->renderText("The candle has run out!",
                         game_width * .65f, game_height * 0.08f, 1.0f, ASGE::COLOURS::GHOSTWHITE);
    placeholderDimensions[1] += 0.025f;
  }


}

/**
*   @brief   In Game Items Visible
*   @details This function is used to render the game items currently visible
*   @see     KeyEvent
*   @return  void
*/
void MyGame::renderInGameItems(float * placeholderDimensions){


  int numberItemsVisibleInLocation = 0;
  std::string  itemText[5];
  for(int i = 0; i < numberItems; i++)
  {
    if (cellIndex == itemList[i].getLocationNumber())
    {
      if (!itemList[i].getHidden())
      {
        itemText[numberItemsVisibleInLocation] = "You can see ";
        itemText[numberItemsVisibleInLocation] += itemList[i].getItem();
        itemText[numberItemsVisibleInLocation] += " here.";

        numberItemsVisibleInLocation++;

      }
    }
  }
  for(int i = 0; i < numberItemsVisibleInLocation; i++)
  {
    renderer->renderText(itemText[i].c_str(),
                         game_width * placeholderDimensions[0], game_height * placeholderDimensions[1],
                         1.0f, ASGE::COLOURS::GHOSTWHITE);
    placeholderDimensions[1] += 0.025f;
  }
}

/**
*   @brief   In Game Verbs
*   @details This function is used to render the game verb list
*   @see     KeyEvent
*   @return  void
*/
void MyGame::renderInGameVerbs(float * placeholderDimensions){
  for(int i = 0; i < numberVerbs; i++)
  {
    renderer->renderText(verbList[i].getVerb().c_str(),
                         game_width * placeholderDimensions[0], game_height * placeholderDimensions[1],
                         1.0f, ASGE::COLOURS::GHOSTWHITE);
    placeholderDimensions[1] += 0.025f;
    if (i % 10 == 0)
    {
      placeholderDimensions[0] += .1f;
      placeholderDimensions[1] = 0.28f;
    }
  }
}

/**
*   @brief   In Game Inventory
*   @details This function is used to render the game objects
*   @see     KeyEvent
*   @return  void
*/
void MyGame::renderInGameInventory(float * placeholderDimensions) {
  for(int i = 0; i < numberItems; i++)
  {
    if (checkInventory(i))
    {
      renderer->renderText(itemList[i].getItem().c_str(),
                           game_width * placeholderDimensions[0], game_height * placeholderDimensions[1], 1.0f, ASGE::COLOURS::GHOSTWHITE);
      placeholderDimensions[1] += 0.025f;
      if (i % 10 == 0)
      {
        placeholderDimensions[0] += .1f;
        placeholderDimensions[1] = 0.28f;
      }

    }
  }

}

/**
*   @brief   In Game Score
*   @details This function is used to render the game objects
*   @see     KeyEvent
*   @return  void
*/
void MyGame::renderInGameScore(float * placeholderDimensions){


  if (itemsInInventory == 17 && cellIndex == 57)
  {
    std::string currentScore = ("Current Score: " + std::to_string(itemsInInventory * 2));
    renderer->renderText("Double score for reaching here! Well Done! You finished the game!.",
                         game_width * placeholderDimensions[0], game_height * placeholderDimensions[1], 1.0f, ASGE::COLOURS::GHOSTWHITE);
    placeholderDimensions[1] += 0.025f;
    renderer->renderText(currentScore,
                         game_width * placeholderDimensions[0], game_height * placeholderDimensions[1], 1.0f, ASGE::COLOURS::GHOSTWHITE);
    placeholderDimensions[1] += 0.025f;
  }
  else if (itemsInInventory == 17 && cellIndex != 57)
  {
    std::string currentScore = ("Current Score: " + std::to_string(itemsInInventory));
    renderer->renderText("You have everything. Return to the gate for the final score.",
                         game_width * placeholderDimensions[0], game_height * placeholderDimensions[1], 1.0f, ASGE::COLOURS::GHOSTWHITE);
    placeholderDimensions[1] += 0.025f;
    renderer->renderText(currentScore,
                         game_width * placeholderDimensions[0], game_height * placeholderDimensions[1], 1.0f, ASGE::COLOURS::GHOSTWHITE);
    placeholderDimensions[1] += 0.025f;
  }
  else
  {
    std::string currentScore = ("Current Score: " + std::to_string(itemsInInventory));
    renderer->renderText(currentScore,
                         game_width * placeholderDimensions[0], game_height * placeholderDimensions[1], 1.0f, ASGE::COLOURS::GHOSTWHITE);
    placeholderDimensions[1] += 0.025f;
  }


}

/**
*   @brief   Setup Haunted House Game
*   @details This function is used to setup a new game
*   @see     KeyEvent
*   @return  void
*/
void MyGame::setupHauntedHouseGame(){
  // game setup
  setupHauntedHouseVerbs();
  setupHauntedHouseItems();
  setupHauntedHouseMap();
  setupHauntedHouseEvents();
  setupHauntedHouseInventory();
  setupHauntedHouseCommands();



  // loadVerbList();
  game_state = MAIN_SCREEN;
  checkingInput = false;
  displayInventory = false;
  displayVerbList =false;
  displayAMessage = false;
  displayEventMessage = false;
  displayLightWarning =false;
  displayLightOut = false;
  eventMessage = "";
  message = "";
  light = false;
  lightCounter = 60;
  displayTheScore = false;
  firstWord = "";
  secondWord = "";
  itemsInInventory = 0;
  eventToProcess = -1;
  commandToProcess = 0;
  firstWordComplete = false;
  canTeleport =false;

}

/**
*   @brief   Setup Haunted House Verbs
*   @details This function is used to setup the verb list for the game
*   @see     KeyEvent
*   @return  void
*/
void MyGame::setupHauntedHouseVerbs(){
  numberVerbs = 26;
  verbList[0].setVerb("");
  verbList[1].setVerb("HELP");
  verbList[2].setVerb("CARRYING?");
  verbList[3].setVerb("GO");
  verbList[4].setVerb("N");
  verbList[5].setVerb("S");
  verbList[6].setVerb("W");
  verbList[7].setVerb("E");
  verbList[8].setVerb("U");
  verbList[9].setVerb("D");
  verbList[10].setVerb("GET");
  verbList[11].setVerb("TAKE");
  verbList[12].setVerb("EXAMINE");
  verbList[13].setVerb("OPEN");
  verbList[14].setVerb("READ");
  verbList[15].setVerb("SAY");
  verbList[16].setVerb("DIG");
  verbList[17].setVerb("SWING");
  verbList[18].setVerb("CLIMB");
  verbList[19].setVerb("LIGHT");
  verbList[20].setVerb("UNLIGHT");
  verbList[21].setVerb("SPRAY");
  verbList[22].setVerb("USE");
  verbList[23].setVerb("UNLOCK");
  verbList[24].setVerb("LEAVE");
  verbList[25].setVerb("SCORE");
  //saveVerbList();
}

/**
*   @brief   Setup Haunted House Items
*   @details This function is used to setup the items list for the game
*   @see     KeyEvent
*   @return  void
*/
void MyGame::setupHauntedHouseItems() {
  numberItems = 36;
  itemList[0] = Item("PAINTING", true, "The painting is an Ominous Portrait of the Owner.", 46, false, true );
  itemList[1] = Item("RING", true, "This ring is an Ornate and encrusted with Rubies.", 38, true, true );
  itemList[2] = Item("BOOK OF SPELLS", true, "Use this word with care 'XZANFAR'.", 35, false, true );
  itemList[3] = Item("GOBLET", true, "This ornate Goblet is made from solid Gold.", 50, false, true );
  itemList[4] = Item("SCROLLS", true, "The script is in an Alien Tongue.", 13, false, true );
  itemList[5] = Item("COINS", true, "Collection of valuable old coins.", 18, false, true );
  itemList[6] = Item("STATUE", true, "This statue is made from solid Gold.", 28, false, true );
  itemList[7] = Item("CANDLESTICK", true, "This candlestick can hold a candle.", 42, false, true );
  itemList[8] = Item("MATCHES", true, "These matches came from a local bar.", 10, false, true );
  itemList[9] = Item("VACUUM CLEANER", true, "Dryson 5000 requires 6 9v Batteries.", 25, false, true );
  itemList[10] = Item("BATTERIES", true, "Six 9v Batteries.", 26, false, true );
  itemList[11] = Item("SHOVEL", true, "Antique shovel. Still solid.", 4, false, true );
  itemList[12] = Item("AXE", true, "Woodcutters Axe. Useful for chopping.", 2, false, true );
  itemList[13] = Item("ROPE", true, "Rope found hanging from tree.", 7, false, true );
  itemList[14] = Item("BOAT", true, "This Boat is very old.", 47, false, true );
  itemList[15] = Item("AEROSOL", true, "The label says Baticide.", 60, false, true );
  itemList[16] = Item("CANDLE", true, "A small Candle it won't last long when lit.", 43, true, true );
  itemList[17] = Item("KEY", true, "This key must unlock something.", 32, true, true );
  itemList[18] = Item("NORTH", false, "", -1, false, false );
  itemList[19] = Item("SOUTH", false, "", -1, false, false );
  itemList[20] = Item("WEST",false, "", -1, false, false );
  itemList[21] = Item("EAST", false, "", -1, false, false );
  itemList[22] = Item("UP", false, "", -1, false, false );
  itemList[23] = Item("DOWN", false, "", -1, false, false );
  itemList[24] = Item("DOOR", true, "This door looks heavy.", 28, false, false );
  itemList[25] = Item("BATS", false, "", 13, false, false );
  itemList[26] = Item("GHOSTS", false, "", 52, false, false );
  itemList[27] = Item("DRAWER",true, "It is a drawer.", 43, true, false );
  itemList[28] = Item("DESK", true, "There is a Drawer in the desk.", 43, false, false );
  itemList[29] = Item("COAT", true, "There is something here.", 32, false, false );
  itemList[30] = Item("RUBBISH", true, "Nothing to see here.", 2, false, false );
  itemList[31] = Item("COFFIN", true, "That's Disgusting.", 38, false, false );
  itemList[32] = Item("BOOKS", true, "They are Demonic Works.", 42, false, false );
  itemList[33] = Item("XZANFAR", false, "", -1, true, false );
  itemList[34] = Item("WALL",true, "The wall looks fragile.", -1, false, false );
  itemList[35] = Item("SPELLS", false, "", -1, true, false );
}

/**
*   @brief   Setup Haunted House Map
*   @details This function is used to setup the map for the game
*   @see     KeyEvent
*   @return  void
*/
void MyGame::setupHauntedHouseMap() {

  map = 0;
  mapList.setCell(0, Cell("Dark Corner", "You are in a dark corner of the gardens of the house.",
                          false, false, true, true, false, -1, false, -1, true));
  mapList.setCell(1, Cell("Overgrown Garden", "You are in an overgrown area in the gardens.",
                          false, true, true, false, false, -1, false, -1, true));
  mapList.setCell(2, Cell("By Woodpile", "You are by a woodpile in the Gardens.",
                          false, true, true, false, false, -1, false, -1, true));
  mapList.setCell(3, Cell("Yard", "You are in the yard area of the gardens.",
                          false, true, true, true, false, -1, false, -1, true));
  mapList.setCell(4, Cell("Weed Patch", "You are in a weed patch in the gardens of the house.",
                          false, true, true, false, false, -1, false, -1, true));
  mapList.setCell(5, Cell("Forest", "You are in the entry to the forest.",
                          false, true, true, false, false, -1, false, -1, true));
  mapList.setCell(6, Cell("Thick Forest", "You are deep in the forest.",
                          false, true, true, true, false, -1, false, -1, true));
  mapList.setCell(7, Cell("Blasted Tree", "You are in a corner of the forest by a blasted tree.",
                          false, true, false, true, false, -1, false, -1, true));
  mapList.setCell(8, Cell("Corner of House", "You are by the northwest corner of the house in the gardens.",
                          true, false, false, true, false, -1, false, -1, true));
  mapList.setCell(9, Cell("Entrance to Kitchen", "You are in the entrance to the kitchens.",
                          false, false, true, true, false, -1, false, -1, true));
  mapList.setCell(10, Cell("Kitchen", "You are in the main kitchen area.",
                           false, true, true, false, false, -1, false, -1, true));
  mapList.setCell(11, Cell("Scullery Door", "You are in the kitchen by the scullery door.",
                           true, true, false, false, false, -1, false, -1, true));
  mapList.setCell(12, Cell("Dusty Room", "You are in a dusty room near the rear turret.",
                           false, false, true, true, false, -1, false, -1, true));
  mapList.setCell(13, Cell("Rear Turret Room", "You are in the main room of the rear turret.",
                           false, true, false, false, false, -1, false, -1, true));
  mapList.setCell(14, Cell("Clearing", "You are in a clearing in the forest.",
                           true, false, true, false, false, -1, false, -1, true));
  mapList.setCell(15, Cell("Path", "You are on a pathway between the forest and the cliffs.",
                           true, true, false, true, false, -1, false, -1, true));
  mapList.setCell(16, Cell("Side of House", "You are in the gardens to the west of the house.",
                           true, false, false, true, false, -1, false, -1, true));
  mapList.setCell(17, Cell("Back of Hallway", "You are at the back of the main hallway by the entrance to the kitchen.",
                           true, false, false, true, false, -1, false, -1, true));
  mapList.setCell(18, Cell("Dark Alcove", "You are in a dark alcove of the house.",
                           false, false, true, true, false, -1, false, -1, false));
  mapList.setCell(19, Cell("Small Dark Room", "You are in a small dark room in the house.",
                           false, true, true, false, false, -1, false, -1, false));
  mapList.setCell(20, Cell("Spiral Staircase", "You are in a spiral staircase leading to the rear turret.",
                           true, true, false, false, true, 0, true, 1, true));
  mapList.setCell(21, Cell("Wide Passage", "You are in a wide passage leading to the cellar stairs.",
                           false, false, true, true, false, -1, false, -1, true));
  mapList.setCell(22, Cell("Slippery Steps", "You are in a slippery staircase leading down to the cellar.",
                           false, true, true, true, true, 1, true, 3, true));
  mapList.setCell(23, Cell("Clifftop", "You are on a clifftop path to the east of the house.",
                           true, false, false, true, false, -1, false, -1, true));
  mapList.setCell(24, Cell("Crumbling Wall", "You are by a crumbling wall in the gardens of the house.",
                           true, false, false, false, false, -1, false, -1, true));
  mapList.setCell(25, Cell("Gloomy Passage", "You are in a gloomy passageway leading to the kitchen.",
                           true, false, false, true, false, -1, false, -1, true));
  mapList.setCell(26, Cell("Pool of Light", "You are in a pool of light in the main sitting room.",
                           true, false, true, true, false, -1, false, -1, true));
  mapList.setCell(27, Cell("Vaulted Hall", "You are in a large vaulted hall.",
                           false, true, true, false, false, -1, false, -1, false));
  mapList.setCell(28, Cell("Hall", "You are in a hallway leading to the trophy room.",
                           false, true, true, false, false, -1, false, -1, false));
  mapList.setCell(29, Cell("Trophy Room", "You are in the Trophy Room.",
                           true, true, false, true, false, -1, false, -1, true));
  mapList.setCell(30, Cell("Cellar", "You are in the main cellar.",
                           true, false, false, true, false, -1, false, -1, false));
  mapList.setCell(31, Cell("Cliff Path", "You are on a clifftop path to the east of the house.",
                           true, false, false, true, false, -1, false, -1, true));
  mapList.setCell(32, Cell("Cupboard", "You are in a small cupboard.",
                           false, false, false, true, false, -1, false, -1, true));
  mapList.setCell(33, Cell("Front Hall", "You are in the front hallway of the house.",
                           true, false, true, true, false, -1, false, -1, true));
  mapList.setCell(34, Cell("Sitting Room", "You are in the sitting room.",
                           true, true, false, true, false, -1, false, -1, true));
  mapList.setCell(35, Cell("Secret Room", "You are in the secret room.",
                           false, false, false, true, false, -1, false, -1, true));
  mapList.setCell(36, Cell("Steep Marble Steps", "You are in a marble staircase leading up to the upper floor.",
                           true, false, false, true, true, 3, true, 0, true));
  mapList.setCell(37, Cell("Dining Room", "You are in the dining room.",
                           true, false, false, false, false, -1, false, -1, true));
  mapList.setCell(38, Cell("Deep Cellar", "You are in the deepest part of the cellar.",
                           true, false, false, false, false, -1, false, -1, true));
  mapList.setCell(39, Cell("Cliff Path", "You are on a clifftop path to the east of the house.",
                           true, false, false, true, false, -1, false, -1, true));
  mapList.setCell(40, Cell("Closet", "You are in a closet by the front entrance to the house.",
                           true, false, true, false, false, -1, false, -1, true));
  mapList.setCell(41, Cell("Front Lobby", "You are in the front Lobby.",
                           true, true, false, false, false, -1, false, -1, true));
  mapList.setCell(42, Cell("Library", "You are in the Library.",
                           true, false, true, false, false, -1, false, -1, true));
  mapList.setCell(43, Cell("Study", "You are in the study.",
                           false, true, false, false, false, -1, false, -1, true));
  mapList.setCell(44, Cell("Cobwebby Room", "You are in a room covered in cobwebs.",
                           true, false, true, true, false, -1, false, -1, true));
  mapList.setCell(45, Cell("Cold Chamber", "You are in a cold chamber.",
                           false, true, true, false, false, -1, false, -1, true));
  mapList.setCell(46, Cell("Spooky Room", "You are in a spooky room.",
                           false, true, false, false, false, -1, false, -1, true));
  mapList.setCell(47, Cell("Cliff Path by Marsh", "You are on a clifftop path leading down to the marsh.",
                           true, false, false, true, false, -1, false, -1, true));
  mapList.setCell(48, Cell("Verandah", "You are on the verandah which is covered in rubble.",
                           false, false, true, true, false, -1, false, -1, true));
  mapList.setCell(49, Cell("Front Porch", "You are on the front porch of the house.",
                           true, true, false, true, false, -1, false, -1, true));
  mapList.setCell(50, Cell("Front Tower", "You are in the front tower of the house.",
                           false, false, true, false, false, -1, false, -1, true));
  mapList.setCell(51, Cell("Sloping Corridor", "You are in a sloping corridor in the upper floor of the house.",
                           false, true, true, false, false, -1, false, -1, true));
  mapList.setCell(52, Cell("Upper Gallery", "You are in the upper gallery of the house.",
                           true, true, false, false, false, -1, false, -1, true));
  mapList.setCell(53, Cell("Marsh by Wall", "You are in the marsh by the wall of the house.",
                           false, false, false, true, false, -1, false, -1, true));
  mapList.setCell(54, Cell("Marsh", "You are in the marsh.",
                           false, true, false, true, false, -1, false, -1, true));
  mapList.setCell(55, Cell("Soggy Path", "You are on a soggy path leading to the marsh.",
                           true, true, false, false, false, -1, false, -1, true));
  mapList.setCell(56, Cell("Twisted Railings", "You are by some twisted railings at the front entrance to the house.",
                           true, false, true, false, false, -1, false, -1, true));
  mapList.setCell(57, Cell("Path", "You are on the path leading to the front of the house.",
                           true, true, true, false, false, -1, false, -1, true));
  mapList.setCell(58, Cell("Path by Railings", "You are on a path by some railings at the front of the house.",
                           false, true, true, false, false, -1, false, -1, true));
  mapList.setCell(59, Cell("Beneath Tower", "You are on a path beneath the Tower at the front of the house.",
                           false, true, true, false, false, -1, false, -1, true));
  mapList.setCell(60, Cell("Debris", "You are on a path with some debris at the front of the house.",
                           false, true, true, false, false, -1, false, -1, true));
  mapList.setCell(61, Cell("Fallen Brickwork", "You are on a path by some fallen brickwork at the front of the house.",
                           true, true, true, false, false, -1, false, -1, true));
  mapList.setCell(62, Cell("Stone Arch", "You are by a stone arch.",
                           true, true, true, false, false, -1, false, -1, true));
  mapList.setCell(63, Cell("Crumbling Clifftop", "You are on a crumbling clifftop overlooking the marsh.",
                           false, true, false, false, false, -1, false, -1, true));
  cellIndex = 57;
  currentCell = mapList.getCell(cellIndex);
}

/**
*   @brief   Setup Haunted House Events
*   @details This function is used to setup the events list for the game
*   @see     KeyEvent
*   @return  void
*/
void MyGame::setupHauntedHouseEvents(){
  numberEvents = 16;
  events[0] = Event(49, true, false, 4, MESSAGE, false, 0, -1, "The Door Slams Shut!", -1, false);
  events[1] = Event(12, true, false, 6, REMOVE_ITEM, true, 3, 25, "", -1, false);
  events[2] = Event(45, false, false, 6, OVERRIDE_COMMAND, false, 0, -1, "A Magical barrier to the west", -1, false);
  events[3] = Event(52, false, false, 7, OVERRIDE_COMMAND, false, 0, -1, "Ghosts won't let you move", 26, false);
  events[4] = Event(54, false, false, 5, OVERRIDE_COMMAND, false, 0, -1, "The boat is stuck",  14, true);
  events[5] = Event(53, false, false, 5, OVERRIDE_COMMAND, false, 0, -1, "You Can't Carry the Boat", 14, true);
  events[6] = Event(62, false, false, 4, OVERRIDE_COMMAND, false, 0, -1, "You Can't Carry the Boat", 14, true);
  events[7] = Event(52, false, false, 4, OVERRIDE_COMMAND, false, 0, -1, "Ghosts won't let you move", 26, false);
  events[8] = Event(52, false, false, 5, OVERRIDE_COMMAND, false, 0, -1, "Ghosts won't let you move", 26, false);
  events[9] = Event(52, false, false, 6, OVERRIDE_COMMAND, false, 0, -1, "Ghosts won't let you move", 26, false);
  events[10] = Event(13, false, false, 4, OVERRIDE_COMMAND, false, 0, -1, "Bats Attacking", 25, false);
  events[11] = Event(13, false, false, 5, OVERRIDE_COMMAND, false, 0, -1, "Bats Attacking", 25, false);
  events[12] = Event(13, false, false, 6, OVERRIDE_COMMAND, false, 0, -1, "Bats Attacking", 25, false);
  events[13] = Event(13, false, false, 7, OVERRIDE_COMMAND, false, 0, -1, "Bats Attacking", 25, false);
  events[14] = Event(55, false, false, 6, OVERRIDE_COMMAND, false, 0, -1, "Too deep to cross!", 14, false);
  events[15] = Event(53, false, false, 5, MESSAGE, false, 0, -1, "", 14, false);

}

/**
*   @brief   Setup Haunted House Events
*   @details This function is used to setup the events list for the game
*   @see     KeyEvent
*   @return  void
*/
void MyGame::setupHauntedHouseInventory() {
  itemsInInventory = 0;
  for (int i = 0; i < numberItems; i++)
  {
    inventory[i] = numberItems;
  }
}

/**
*   @brief   Setup Haunted House Commands
*   @details This function is used to setup the commands list for the game
*   @see     KeyEvent
*   @return  void
*/
void MyGame::setupHauntedHouseCommands(){
  numberCommands = 45;
  availableCommands[0] = Commands(0, false, false, 0, false, false, 0, false, false, 0, false, 0, INVALID, "");
  availableCommands[1] = Commands(1, false, false, 0, false, false, 0, false, false, 0, false, 0, LIST_VERBS, "");
  availableCommands[2] = Commands(2, false, false, 0, false, false, 0, false, false, 0, false, 0, LIST_INVENTORY, "");
  availableCommands[3] = Commands(3, false, false, 0, false, false, 0, false, false, 0, false, 0, DISPLAY_MESSAGE,
                                  "Go Where?");
  availableCommands[4] = Commands(4, false, false, 0, false, false, 0, false, false, 0, false, 0, GO_NORTH, "");
  availableCommands[5] = Commands(5, false, false, 0, false, false, 0, false, false, 0, false, 0, GO_SOUTH, "");
  availableCommands[6] = Commands(6, false, false, 0, false, false, 0, false, false, 0, false, 0, GO_WEST, "");
  availableCommands[7] = Commands(7, false, false, 0, false, false, 0, false, false, 0, false, 0, GO_EAST, "");
  availableCommands[8] = Commands(8, false, false, 0, false, false, 0, false, false, 0, false, 0, GO_UP, "");
  availableCommands[9] = Commands(9, false, false, 0, false, false, 0, false, false, 0, false, 0, GO_DOWN, "");
  availableCommands[10] = Commands(10, false, false, 0, false, false, 0, false, false, 0, false, 0, ADD_ITEM, "");
  availableCommands[11] = Commands(11, false, false, 0, false, false, 0, false, false, 0, false, 0, ADD_ITEM, "");
  availableCommands[12] = Commands(12, false, false, 0, false, false, 0, false, false, 0, false, 0, EXAMINE, "");
  availableCommands[13] = Commands(13, true, true, 17, false, false, 0, false, false, 0, true, 28, CREATE_EXIT_SOUTH, "");
  availableCommands[14] = Commands(14, true, false, 2, false, false, 0, false, false, 0, true,
                                   itemList[2].getLocationNumber(), FLIP_TELEPORT, "Use this word with care 'XZANFAR'.");
  availableCommands[15] = Commands(15, false, false, 14, false, false, 0, false, false, 0, false, 0, DISPLAY_MESSAGE,
                                   secondWord);
  availableCommands[16] = Commands(16, true, true, 11, false, false, 0, false, false, 0, false, 0, DISPLAY_MESSAGE,
                                   "You made a hole");
  availableCommands[17] = Commands(17, true, true, 12, false, false, 0, false, false, 0, false, 0, DISPLAY_MESSAGE,
                                   "You swung it.");
  availableCommands[18] = Commands(18, true, false, 13, false, false, 0, false, false, 0, false, 0, DISPLAY_MESSAGE,
                                   "It is not attached to anything.");
  availableCommands[19] = Commands(19, true, true, 16, false, false, 0, false, false, 0, false, 0, DISPLAY_MESSAGE,
                                   "Nothing to light it with.");
  availableCommands[20] = Commands(20, true, true, 16, true, true, 8, true, true, 7, false, 0, LIGHT_OFF,
                                   "Extinguished");
  availableCommands[21] = Commands(21, true, false, 25, true, true, 15, false, false, 0, false, 0,
                                   REMOVE_ITEM_FROM_CELL, "Pfft! Got them");
  availableCommands[22] = Commands(22, true, true, 9, true, true, 10, false, false, 0, false, 0, DISPLAY_MESSAGE,
                                   "Switched on.");
  availableCommands[23] = Commands(23, true, true, 17, false, false, 0, false, false, 0, true, 28, CREATE_EXIT_SOUTH,
                                   "The key turns.");
  availableCommands[24] = Commands(24, false, false, 0, false, false, 0, false, false, 0, false, 0, LEAVE_ITEM, "Done");
  availableCommands[25] = Commands(25, false, false, 0, false, false, 0, false, false, 0, false, 0, SCORE, "");
  availableCommands[26] = Commands(13, true, false, 27, false, false, 0, false, false, 0, true, 43, REVEAL_ITEM, "");
  availableCommands[27] = Commands(3, true, false, 19, false, false, 0, false, false, 0, false, 0, GO_SOUTH,
                                  "Go Where?");
  availableCommands[28] = Commands(3, true, false, 20, false, false, 0, false, false, 0, false, 0, GO_WEST,
                                  "Go Where?");
  availableCommands[29] = Commands(3, true, false, 21, false, false, 0, false, false, 0, false, 0, GO_EAST,
                                  "Go Where?");
  availableCommands[30] = Commands(3, true, false, 22, false, false, 0, false, false, 0, false, 0, GO_UP,
                                  "Go Where?");
  availableCommands[31] = Commands(3, true, false, 22, false, false, 0, false, false, 0, false, 0, GO_DOWN,
                                   "Go Where?");
  availableCommands[32] = Commands(14, true, false, 32, false, false, 0, false, false, 0, true,
                                   itemList[2].getLocationNumber(), EXAMINE, "");
  availableCommands[33] = Commands(15, true, false, 33, false, false, 0, false, false, 0, false, 0, TELEPORT,
                                   "");
  availableCommands[34] = Commands(13, true, false, 28, false, false, 0, false, false, 0, true, 43, REVEAL_ITEM, "");
  availableCommands[35] = Commands(12, true, false, 29, false, false, 0, false, false, 0, true, 32, REVEAL_ITEM, "");
  availableCommands[36] = Commands(17, true, true, 12, false, false, 0, false, false, 0, true, 43, CREATE_EXIT_NORTH,
                                   "You swung it.");
  availableCommands[37] = Commands(3, true, false, 17, false, false, 0, false, false, 0, false, 0, GO_NORTH,
                                   "Go Where?");
  availableCommands[38] = Commands(16, true, true, 11, false, false, 0, false, false, 0, true, 30, CREATE_EXIT_EAST, "");
  availableCommands[39] = Commands(18, true, false, 13, false, false, 0, false, false, 0, true, 7, DISPLAY_MESSAGE,
                                   "You see thick forest and Cliffs to the south.");
  availableCommands[40] = Commands(19, true, true, 16, true, true, 8, false, false, 0, false, 0, DISPLAY_MESSAGE,
                                   "It will burn your hands.");
  availableCommands[41] = Commands(19, true, true, 19, true, true, 16, true, true, 8, false, 0, LIGHT_ON,
                                   "It casts a flickering light.");
  availableCommands[42] = Commands(22, true, false, 26, true, true, 10, true, true, 9, true, 52, REMOVE_ITEM_FROM_CELL,
                                   "Vacuumed the ghosts up.");
  availableCommands[43] = Commands(14, true, false, 2, true, true, 2, false, false, 0, false, 0, FLIP_TELEPORT,
                                   "Use this word with care 'XZANFAR'.");
  availableCommands[44] = Commands(12, true, false, 31, false, false, 0, false, false, 0, true, 38, REVEAL_ITEM,
                                   "That's Disgusting.");

}

/**
*   @brief   Go North
*   @details This function is used to process a go north action
*   @see     KeyEvent
*   @return  void
*/
void MyGame::goNorth(){

  if(currentCell.getExit(0)){
    if(currentCell.isLit() || (!currentCell.isLit() && light && lightCounter > 0))
    {
      cellIndex -= mapList.getGridSize();
      Cell newCell = mapList.getCell(cellIndex);
      if (newCell.isLit() || (!newCell.isLit() && light && lightCounter > 0))
      {
        currentCell = mapList.getCell(cellIndex);

        displayAMessage = true;
        message = "You go North.";
      }
      else if(!newCell.isLit() && (!light || lightCounter >= 0))
      {

        displayAMessage = true;
        message = "Need a light.";
        cellIndex +=  mapList.getGridSize();
      }
    }
    else if(!currentCell.isLit() && (!light || lightCounter >= 0))
    {
      displayAMessage = true;
      message = "Too Dark to Move.";
    }

  }
  else {
    displayAMessage = true;
    message = "Can't go that way.";
  }
}

/**
*   @brief   Go West
*   @details This function is used to process a go west action
*   @see     KeyEvent
*   @return  void
*/
void MyGame::goWest(){

  if(currentCell.getExit(1)) {
    if (currentCell.isLit() || (!currentCell.isLit() && light && lightCounter > 0)) {
      cellIndex -= 1;
      Cell newCell = mapList.getCell(cellIndex);
      if (newCell.isLit() || (!newCell.isLit() && light && lightCounter > 0)) {
        currentCell = mapList.getCell(cellIndex);

        displayAMessage = true;
        message = "You go West.";
      } else if (!newCell.isLit() && (!light || lightCounter >= 0)) {

        displayAMessage = true;
        message = "Need a light.";
        cellIndex += 1;
      }
    } else if (!currentCell.isLit() && (!light || lightCounter >= 0)) {
      displayAMessage = true;
      message = "Too Dark to Move.";
    }
  }
  else {
    displayAMessage = true;
    message = "Can't go that way.";
  }
}

/**
*   @brief   Go East
*   @details This function is used to process a go east action
*   @see     KeyEvent
*   @return  void
*/
void MyGame::goEast(){

  if(currentCell.getExit(2)) {
    if (currentCell.isLit() || (!currentCell.isLit() && light && lightCounter > 0)) {
      cellIndex += 1;
      Cell newCell = mapList.getCell(cellIndex);
      if (newCell.isLit() || (!newCell.isLit() && light && lightCounter > 0)) {
        currentCell = mapList.getCell(cellIndex);

        displayAMessage = true;
        message = "You go East.";
      } else if (!newCell.isLit() && (!light || lightCounter >= 0)) {

        displayAMessage = true;
        message = "Need a light.";
        cellIndex -= 1;
      }
    }
  }
  else if(!currentCell.isLit() && (!light || lightCounter >= 0))
  {
    displayAMessage = true;
    message = "Too Dark to Move.";
  }
  else {
    displayAMessage = true;
    message = "Can't go that way.";
  }
}

/**
*   @brief   Go South
*   @details This function is used to process a go south action
*   @see     KeyEvent
*   @return  void
*/
void MyGame::goSouth(){

  if(currentCell.getExit(3)) {
    if (currentCell.isLit() || (!currentCell.isLit() && light && lightCounter > 0)) {
      cellIndex += mapList.getGridSize();
      Cell newCell = mapList.getCell(cellIndex);
      if (newCell.isLit() || (!newCell.isLit() && light && lightCounter > 0)) {
        currentCell = mapList.getCell(cellIndex);

        displayAMessage = true;
        message = "You go South.";
      } else if (!newCell.isLit() && (!light || lightCounter >= 0)) {

        displayAMessage = true;
        message = "Need a light.";
        cellIndex -= mapList.getGridSize();
      }
    }
  }
  else if(!currentCell.isLit() && (!light || lightCounter >= 0))
  {
    displayAMessage = true;
    message = "Too Dark to Move.";
  }
  else {
    displayAMessage = true;
    message = "Can't go that way.";
  }
}

/**
*   @brief   Go Up
*   @details This function is used to process a go up action
*   @see     KeyEvent
*   @return  void
*/
void MyGame::goUp(){
  if(currentCell.isUp())
  {
    switch (currentCell.getUpExit()){
      case 0 :
        goNorth();
            break;
      case 1 :
        goWest();
            break;
      case 2 :
        goEast();
            break;
      case 3 :
        goSouth();
            break;
      default :
        break;
    }
  }
  else {
    displayAMessage = true;
    message = "Can't go that way.";
  }
}

/**
*   @brief   Go North
*   @details This function is used to process a go down action
*   @see     KeyEvent
*   @return  void
*/
void MyGame::goDown(){
  if(currentCell.isDown())
  {
    switch (currentCell.getDownExit()){
      case 0 :
        goNorth();
            break;
      case 1 :
        goWest();
            break;
      case 2 :
        goEast();
            break;
      case 3 :
        goSouth();
            break;
      default :
        break;
    }
  }
  else {
    displayAMessage = true;
    message = "Can't go that way.";
  }
}

/**
*   @brief   Examine
*   @details This function is used to process an examine action
*   @see     KeyEvent
*   @return  void
*/
void MyGame::examine(){
  displayAMessage = true;
  bool foundItem = false;
  for(int i = 0; i < numberItems; i++)
  {
    if (secondWord == itemList[i].getItem())
    {
      foundItem = true;
      if (itemList[i].getExaminable())
      {
        message = itemList[i].getExamination();
      }
      else
      {
        message = "Can't examine that.";
      }
    }
  }
  if (!foundItem)
  {
    message = "What?";
  }
}

/**
*   @brief   Create North Exit
*   @details This function is used to process a create north exit action
*   @see     KeyEvent
*   @return  void
*/
void MyGame::createExitNorth(){
  currentCell.setExit(0, true);
  displayAMessage = false;
  message = "";
}

/**
*   @brief   Create West Exit
*   @details This function is used to process a create west exit action
*   @see     KeyEvent
*   @return  void
*/
void MyGame::createExitWest(){
  currentCell.setExit(1, true);
  displayAMessage = false;
  message = "";
}

/**
*   @brief   Create East Exit
*   @details This function is used to process a create east exit action
*   @see     KeyEvent
*   @return  void
*/
void MyGame::createExitEast(){
  currentCell.setExit(2, true);
  displayAMessage = false;
  message = "";
}

/**
*   @brief   Create South Exit
*   @details This function is used to process a create south exit action
*   @see     KeyEvent
*   @return  void
*/
void MyGame::createExitSouth(){
  currentCell.setExit(3, true);
  displayAMessage = false;
  message = "";
}

/**
*   @brief   Reveal Item
*   @details This function is used to process a reveal item action
*   @see     KeyEvent
*   @return  void
*/
void MyGame::revealItem(){
  for (int i = 0; i < numberItems; i++)
  {
    if(cellIndex == itemList[i].getLocationNumber() && itemList[i].getHidden())
    {
      itemList[i].setHidden(false);
      displayAMessage = true;
      message = "You found Something!";
    }
  }
}

/**
*   @brief   Teleport
*   @details This function is used to process a teleport action
*   @see     KeyEvent
*   @return  void
*/
void MyGame::teleport(){

  displayAMessage = true;
  message = "**Magic Occurs!**";
  cellIndex = rand() % (mapList.getGridSize() * mapList.getGridSize());
  currentCell = mapList.getCell(cellIndex);
}

/**
*   @brief   Light On
*   @details This function is used to process a light on action
*   @see     KeyEvent
*   @return  void
*/
void MyGame::lightOn() {
  if(lightCounter > 0)
  {
    light = true;
  }
}

/**
*   @brief   Light Off
*   @details This function is used to process a light on action
*   @see     KeyEvent
*   @return  void
*/
void MyGame::lightOff(){
  light = false;
}

/**
*   @brief   Add Item
*   @details This function is used to process an add item action
*   @see     KeyEvent
*   @return  void
*/
void MyGame::addItem(int itemIndex){


  if(checkInventory(itemIndex))
  {
    message = "You already have it'";
    displayAMessage = true;
  }
  else if (itemList[itemIndex].getLocationNumber() == cellIndex)
  {
    if(itemList[itemIndex].getAbleToTake())
    {
      if(!itemList[itemIndex].getHidden())
      {
        for(int i = 0; i < numberItems; i++)
        {
          if (inventory[i] == numberItems)
          {
            inventory[i] = itemIndex;
            itemList[itemIndex].setLocationNumber(-1);
            itemsInInventory++;
            message = "Got it.";
            displayAMessage = true;
            return;
          }
        }
      }
      else
      {
        message = "What " + secondWord;
        displayAMessage = true;
      }
    }
    else if(!itemList[itemIndex].getAbleToTake() )
    {
      message = "I can't get.";
      displayAMessage = true;
    }
  }
  else if(itemList[itemIndex].getLocationNumber() != cellIndex )
  {
    message = "It isn't here.";
    displayAMessage = true;
  }
  else
  {
    message = "What " + secondWord;
    displayAMessage = true;
  }
}

/**
*   @brief   Leave Item
*   @details This function is used to process a leave item action
*   @see     KeyEvent
*   @return  void
*/
void MyGame::leaveItem(int itemIndex){

  if(checkInventory(itemIndex))
  {
    for (int i = 0; i < numberItems; i++) {
      if (itemIndex == inventory[i])
      {
        inventory[i] = numberItems;
      }
    }
    itemList[itemIndex].setLocationNumber(cellIndex);
    itemsInInventory--;
    message = "Done";
    displayAMessage = true;
  } else{
    message = "What";
    displayAMessage = true;
  }
}

/**
*   @brief   Remove Item from Cell
*   @details This function is used to process a remove item from cell action
*   @see     KeyEvent
*   @return  void
*/
void MyGame::removeItemFromCell(int itemIndex){
  itemList[itemIndex].setLocationNumber(-1);
}

/**
*   @brief   Check Input
*   @details This function is used to check the player input
*   @see     KeyEvent
*   @return  void
*/
void MyGame::checkInput(){
  bool firstWordIsVerb = false;
  int verbIndex = 0;
  objectIndex = -1;
  displayLightWarning =false;
  displayLightOut = false;

  for (int i = 0; i < numberVerbs; i++)
  {
    if (firstWord == verbList[i].getVerb())
    {
      firstWordIsVerb = true;
      verbIndex = i;
    }
  }

  for (int i = 0; i < numberItems; i++)
  {
    if (secondWord == itemList[i].getItem())
    {
      objectIndex = i;
    }
  }
  if (firstWordIsVerb)
  {
    processCommand(verbIndex, objectIndex);
  }
  else
  {
    displayAMessage = true;
    message = "What";
  }
  checkLight();
}

/**
*   @brief   Check Light
*   @details This function is used to check and update the light status
*   @see     KeyEvent
*   @return  void
*/
void MyGame::checkLight() {
  if (light)
  {
    lightCounter--;
    if (lightCounter < 10)
    {
      displayLightWarning = true;
    }
    if (lightCounter < 1)
    {
      displayLightWarning = false;
      displayLightOut = true;
      lightOff();
    }
  }
}

/**
*   @brief   Check Events
*   @details This function is used to check the event list to see if an event has occured
*   @see     KeyEvent
*   @return  void
*/
void MyGame::checkEvents() {
  for (int i = 0; i < numberEvents; i++) {
    if(!events[i].isHappened() && cellIndex == events[i].getCellIndex())
    {
      if (commandToProcess == events[i].getCommand() || events[i].getCommand() == 0) {
        if(events[i].getItemRequired() == -1 || events[i].isItemRequiredInInventory() &&
                                                checkInventory(events[i].getItemRequired()) || !events[i].isItemRequiredInInventory()
                                                                                               && (itemList[events[i].getItemRequired()].getLocationNumber() == cellIndex ||
                                                                                                   !checkInventory(events[i].getItemRequired())))
        {
          if(events[i].isIsRandom())
          {
            if(rand() % events[i].getRandomMax() < 1)
            {
              eventToProcess = i;
              processEvent();
            }

          } else{
            eventToProcess = i;
            processEvent();
          }
        }

      }
    }
  }
}

/**
*   @brief   Process Event
*   @details This function is used to process any event that has occured
*   @see     KeyEvent
*   @return  void
*/
void MyGame::processEvent(){
  if(events[eventToProcess].isOneOff())
  {
    events[eventToProcess].setHappened(true);
  }
  switch(events[eventToProcess].getOutcome())
  {
    case OVERRIDE_COMMAND :
      eventMessage = events[eventToProcess].getMessage();
          displayEventMessage = true;
          commandToProcess = DISPLAY_EVENT_MESSAGE;
          break;
    case REMOVE_ITEM :
      removeItemFromCell(events[eventToProcess].getItemAffected());
          eventMessage = events[eventToProcess].getMessage();
          displayEventMessage = true;
          break;
    case MESSAGE :
      eventMessage = events[eventToProcess].getMessage();
          displayEventMessage = true;
          break;
    default :
      break;
  }
}

/**
*   @brief   Process Command
*   @details This function is used to check any valid commands and update which command should be processed
*   @see     KeyEvent
*   @return  void
*/
void MyGame::processCommand(int verbIndex, int objectIndex){

  commandToProcess = 0;
  for (int i = 0; i < numberCommands; i++)
  {
    if (verbIndex == availableCommands[i].getVerbOneIndex() && !availableCommands[i].isItemRequirement()
        && !availableCommands[i].isSecondItemRequirement() && !availableCommands[i].isThirdItemRequirement() &&
        !availableCommands[i].isCellRequirement()){
      commandToProcess = i;
    }
    else if (verbIndex == availableCommands[i].getVerbOneIndex() && availableCommands[i].isItemRequirement()
             && !availableCommands[i].isSecondItemRequirement() && !availableCommands[i].isThirdItemRequirement() &&
             !availableCommands[i].isCellRequirement() && !availableCommands[i].isItemRequiredInInventory()
             && objectIndex == availableCommands[i].getItemIndex()){
      commandToProcess = i;
    }
    else if (verbIndex == availableCommands[i].getVerbOneIndex() && availableCommands[i].isItemRequirement()
             && !availableCommands[i].isSecondItemRequirement() && !availableCommands[i].isThirdItemRequirement() &&
             availableCommands[i].isCellRequirement() && !availableCommands[i].isItemRequiredInInventory()
             && objectIndex == availableCommands[i].getItemIndex()
             && cellIndex == availableCommands[i].getCellIndex()){
      commandToProcess = i;
    }
    else if (verbIndex == availableCommands[i].getVerbOneIndex() && availableCommands[i].isItemRequirement()
             && !availableCommands[i].isSecondItemRequirement() && !availableCommands[i].isThirdItemRequirement() &&
             !availableCommands[i].isCellRequirement() && availableCommands[i].isItemRequiredInInventory()){
      if(checkInventory(availableCommands[i].getItemIndex()))
      {
        commandToProcess = i;
      }
    }
    else if (verbIndex == availableCommands[i].getVerbOneIndex() && availableCommands[i].isItemRequirement()
             && !availableCommands[i].isSecondItemRequirement() && !availableCommands[i].isThirdItemRequirement() &&
             availableCommands[i].isCellRequirement() && availableCommands[i].isItemRequiredInInventory()
             && cellIndex == availableCommands[i].getCellIndex()){
      if(checkInventory(availableCommands[i].getItemIndex()))
      {
        commandToProcess = i;
      }
    }

    else if (verbIndex == availableCommands[i].getVerbOneIndex() && availableCommands[i].isItemRequirement()
             && availableCommands[i].isSecondItemRequirement() && !availableCommands[i].isThirdItemRequirement() &&
             !availableCommands[i].isCellRequirement() && !availableCommands[i].isItemRequiredInInventory()
             && objectIndex == availableCommands[i].getItemIndex()&&
             availableCommands[i].isSecondItemRequiredInInventory()){
      if(checkInventory(availableCommands[i].getSecondItemIndex()))
      {
        commandToProcess = i;
      }
    }
    else if (verbIndex == availableCommands[i].getVerbOneIndex() && availableCommands[i].isItemRequirement()
             && availableCommands[i].isSecondItemRequirement() && !availableCommands[i].isThirdItemRequirement() &&
             availableCommands[i].isCellRequirement() && !availableCommands[i].isItemRequiredInInventory()
             && objectIndex == availableCommands[i].getItemIndex()
             && cellIndex == availableCommands[i].getCellIndex()&&
             availableCommands[i].isSecondItemRequiredInInventory()){
      if(checkInventory(availableCommands[i].getSecondItemIndex()))
      {
        commandToProcess = i;
      }
    }
    else if (verbIndex == availableCommands[i].getVerbOneIndex() && availableCommands[i].isItemRequirement()
             && availableCommands[i].isSecondItemRequirement() && !availableCommands[i].isThirdItemRequirement() &&
             !availableCommands[i].isCellRequirement() && availableCommands[i].isItemRequiredInInventory()&&
             availableCommands[i].isSecondItemRequiredInInventory()){

      if(checkInventory(availableCommands[i].getItemIndex()))
      {
        if(checkInventory(availableCommands[i].getSecondItemIndex())) {
          commandToProcess = i;
        }
      }


    }
    else if (verbIndex == availableCommands[i].getVerbOneIndex() && availableCommands[i].isItemRequirement()
             && availableCommands[i].isSecondItemRequirement() && !availableCommands[i].isThirdItemRequirement() &&
             availableCommands[i].isCellRequirement() && availableCommands[i].isItemRequiredInInventory()
             && cellIndex == availableCommands[i].getCellIndex()&&
             availableCommands[i].isSecondItemRequiredInInventory()){
      if(checkInventory(availableCommands[i].getItemIndex()))
      {
        if(checkInventory(availableCommands[i].getSecondItemIndex())) {
          commandToProcess = i;
        }
      }
    }

    else if (verbIndex == availableCommands[i].getVerbOneIndex() && availableCommands[i].isItemRequirement()
             && availableCommands[i].isSecondItemRequirement() && availableCommands[i].isThirdItemRequirement() &&
             !availableCommands[i].isCellRequirement() && !availableCommands[i].isItemRequiredInInventory()
             && objectIndex == availableCommands[i].getItemIndex()&&
             availableCommands[i].isSecondItemRequiredInInventory()&&
             availableCommands[i].isThirdItemRequiredInInventory()){
      if(checkInventory(availableCommands[i].getThirdItemIndex()))
      {
        if(checkInventory(availableCommands[i].getSecondItemIndex())) {
          commandToProcess = i;
        }
      }
    }
    else if (verbIndex == availableCommands[i].getVerbOneIndex() && availableCommands[i].isItemRequirement()
             && availableCommands[i].isSecondItemRequirement() && availableCommands[i].isThirdItemRequirement() &&
             availableCommands[i].isCellRequirement() && !availableCommands[i].isItemRequiredInInventory()
             && itemList[availableCommands[i].getItemIndex()].getLocationNumber() == cellIndex
             && cellIndex == availableCommands[i].getCellIndex()&&
             availableCommands[i].isSecondItemRequiredInInventory()&&
             availableCommands[i].isThirdItemRequiredInInventory()){
      if(checkInventory(availableCommands[i].getThirdItemIndex()))
      {
        if(checkInventory(availableCommands[i].getSecondItemIndex())) {
          commandToProcess = i;
        }
      }
    }
    else if (verbIndex == availableCommands[i].getVerbOneIndex() && availableCommands[i].isItemRequirement()
             && availableCommands[i].isSecondItemRequirement() && availableCommands[i].isThirdItemRequirement() &&
             !availableCommands[i].isCellRequirement() && availableCommands[i].isItemRequiredInInventory()&&
             availableCommands[i].isSecondItemRequiredInInventory()&&
             availableCommands[i].isThirdItemRequiredInInventory()){
      if(checkInventory(availableCommands[i].getThirdItemIndex()))
      {
        if(checkInventory(availableCommands[i].getSecondItemIndex())) {
          if(checkInventory(availableCommands[i].getItemIndex()))
          {
            commandToProcess = i;
          }
        }
      }
    }
    else if (verbIndex == availableCommands[i].getVerbOneIndex() && availableCommands[i].isItemRequirement()
             && availableCommands[i].isSecondItemRequirement() && availableCommands[i].isThirdItemRequirement() &&
             availableCommands[i].isCellRequirement() && availableCommands[i].isItemRequiredInInventory()
             && cellIndex == availableCommands[i].getCellIndex()&&
             availableCommands[i].isSecondItemRequiredInInventory()&&
             availableCommands[i].isThirdItemRequiredInInventory()){
      if(checkInventory(availableCommands[i].getThirdItemIndex()))
      {
        if(checkInventory(availableCommands[i].getSecondItemIndex())) {
          if(checkInventory(availableCommands[i].getItemIndex()))
          {
            commandToProcess = i;
          }
        }
      }
    }
  }
}

/**
*   @brief   Check Inventory
*   @details This function is used to check inventory for a specific item
*   @see     KeyEvent
*   @return  true if player has item
*/
bool MyGame::checkInventory(int itemIndex){
  bool isInInventory = false;
  for (int i = 0; i < numberItems; i++)
  {
    if(itemIndex == inventory[i])
    {
      isInInventory = true;
    }
  }
  return isInInventory;
}

/**
*   @brief   Perform Action
*   @details This function is used to perform the current action after event and command input checks
*   @see     KeyEvent
*   @return  void
*/
void MyGame::performAction() {
  switch(availableCommands[commandToProcess].getActionIndex())
  {
    case INVALID :
      message = availableCommands[commandToProcess].getMessage();
          displayAMessage = true;
          break;
    case LIST_VERBS :
      displayVerbList = true;
          break;
    case LIST_INVENTORY  :
      displayInventory = true;
          break;
    case GO_NORTH  :
      goNorth();
          break;
    case GO_WEST  :
      goWest();
          break;
    case  GO_EAST  :
      goEast();
          break;
    case GO_SOUTH :
      goSouth();
          break;
    case GO_UP :
      goUp();
          break;
    case GO_DOWN :
      goDown();
          break;
    case ADD_ITEM :
      addItem(objectIndex);
          break;
    case LEAVE_ITEM :
      leaveItem(objectIndex);
          break;
    case EXAMINE :
      examine();
          break;
    case CREATE_EXIT_NORTH :
      message = availableCommands[commandToProcess].getMessage();
          displayAMessage = true;
          createExitNorth();
          break;
    case CREATE_EXIT_WEST :
      message = availableCommands[commandToProcess].getMessage();
          displayAMessage = true;
          createExitWest();
          break;
    case CREATE_EXIT_EAST :
      message = availableCommands[commandToProcess].getMessage();
          displayAMessage = true;
          createExitEast();
          break;
    case CREATE_EXIT_SOUTH :
      message = availableCommands[commandToProcess].getMessage();
          displayAMessage = true;
          createExitSouth();
          break;
    case REVEAL_ITEM :
      revealItem();
          break;
    case TELEPORT :
      teleport();
          break;
    case DISPLAY_MESSAGE :
      message = availableCommands[commandToProcess].getMessage();
          displayAMessage = true;
          break;
    case LIGHT_ON :
      message = availableCommands[commandToProcess].getMessage();
          displayAMessage = true;
          lightOn();
          break;
    case LIGHT_OFF :
      message = availableCommands[commandToProcess].getMessage();
          displayAMessage = true;
          lightOff();
          break;
    case REMOVE_ITEM_FROM_CELL :
      message = availableCommands[commandToProcess].getMessage();
          displayAMessage = true;
          removeItemFromCell(availableCommands[commandToProcess].getItemIndex());
          break;
    case SCORE :
      displayTheScore = true;
          break;
    case FLIP_TELEPORT :
      canTeleport = true;
          message = availableCommands[commandToProcess].getMessage();
          displayAMessage = true;
          break;
    case DISPLAY_EVENT_MESSAGE :
      displayEventMessage = true;
    default :
      break;
  }
}

/**
*   @brief   Save Haunted House Game
*   @details This function is used to save the verb list for the game
*   @see     KeyEvent
*   @return  void
*/
void MyGame::saveVerbList(){
  ASGE::FILEIO::File outFile;
  ASGE::FILEIO::IOBuffer buffer;
  // save verb list array to file
  if (outFile.open("VerbList.txt", ASGE::FILEIO::File::IOMode::WRITE))
  {
    for (int i = 0; i < numberVerbs; i++)
    {

      std::string verb = verbList[i].getVerb();
      buffer.append(verb.c_str(), sizeof(verb));
    }
    outFile.write(buffer);
    outFile.close();
  }

}

/**
*   @brief   Load Haunted House Game
*   @details This function is used to load the verb list for the game
*   @see     KeyEvent
*   @return  void
*/
void MyGame::loadVerbList(){
  numberVerbs = 26;
  // load high scores
  std::ifstream inFile_one;
  inFile_one.open("VerbList.txt");
  if (!inFile_one.fail())
  {
    for (int i = 0; i < numberVerbs; i++)
    {
      std::string newVerb;
      getline(inFile_one, newVerb);
      verbList[i].setVerb(newVerb);
    }
    inFile_one.close();
  }
}
