/**********************************************************************
Author: Shane
Purpose: declaration of the Board class
Date: Monday March 12th 2018
***********************************************************************/

#ifndef FINALPROJECT_BOARD_H
#define FINALPROJECT_BOARD_H

#include "Space.h"

enum direction {up, right, down, left};

class Board {
private:
    int numCols;
    int numRows;
    Space* startSpace = nullptr;
    bool gameOver = false;

    Space*** gameBoard;

    void linkSpaces(); //link all of the spaces on the board together
    void populateInitialBoard(); //populates the grid with space types, characters and items

    void replaceSpace(spaceType s, int x, int y); //replaces board space old with new
    void createCharacter(characterType t, int x, int y);
    void createItem(itemType t, int x, int y);

    Space* nextSpace(Space* a, direction d);
    bool offBoard(Space* s); //returns true if it's a nullptr
    void boardMove(Character* c, Space* a, Space* b); //the logic for moving a character from a to b, orthogonal to scenarios

public:
    Board(); //creates a grid of space pointers
    ~Board(); //destroys all spaces on board, which destroy all characters (and character items, then dice) and items on the board

    //getters and setters
    bool getGameOver(); //returns game over status
    int getNumRows();
    int getNumCols();
    Character* getSpaceCharacter(int x, int y);

    //game logic functions
    void moveCharacter(Character* c, direction d); //logic from moving character c in direction d
    bool fight(Character* a, Character* b); //sends two characters to fight, returns true if A wins

    void printBoard(); //prints the board to the screen
    void triforceScreen(); //for getting the triforce






};


#endif //FINALPROJECT_BOARD_H
