/**********************************************************************
Author: Shane
Purpose: Implementation of the Blank class
Date: Monday March 12th 2018
***********************************************************************/

#ifndef FINALPROJECT_GAME_H
#define FINALPROJECT_GAME_H

#include "Board.h"
#include "Menu.h"
#include "Character.h"
#include <string>
#include <vector>

using std::vector;

class Game {
private:

    //vector of characters
    vector <Character*> cVector;
    Board* gBoard;

    Character* playerLink = nullptr;

    bool gameOver = false;
    void updateCharacterVector();

public:
    Game(); //default constructor
    ~Game(); //default destructor removes additional characters and items

    void runTurn();
    void runGame();
    void printTurn();

    void landingScreen();
    void infoScreen();


};


#endif //FINALPROJECT_GAME_H
