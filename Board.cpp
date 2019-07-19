/**********************************************************************
Author: Shane
Purpose: implementation of the Board class
Date: Monday March 12th 2018
***********************************************************************/

#include "Board.h"

#include "Blank.h"
#include "Rock.h"
#include "Door.h"
#include "Vortex.h"

#include "Link.h"
#include "Tektite.h"
#include "Octorok.h"
#include "LikeLike.h"
#include "Aquamentus.h"

#include "Item.h"
#include <iostream>

using std::cout;
using std::endl;

/**********************************************************************
CONSTRUCTOR AND DESTRUCTOR
***********************************************************************/
Board::Board() {
    numCols = 30; //set board width
    numRows = 10; //set board height

    gameBoard = new Space**[numRows];

    //create a 2D array of unlinked blank spaces
    for(int i = 0; i < numRows; i++)
    {
        gameBoard[i] = new Space*[numCols];
        for(int j = 0; j < numCols; j++)
        {
            gameBoard[i][j] = new Blank();
        }
    }

    //then, populate the board with new spaces, characters, and items
    populateInitialBoard();

    //now, link all of the spaces
    linkSpaces();

}

Board::~Board() {
    for(int i = 0; i < numRows; i++)
    {

        for(int j = 0; j < numCols; j++)
        {
            delete gameBoard[i][j]; //delete the space pointer
        }

        delete[] gameBoard[i]; //then, delete the pointer to the row of space pointers
    }

    delete[] gameBoard; //finally, delete the pointer to the array of rows
}

/**********************************************************************
PRIVATE HELPER FUNCTIONS FOR SETTING THE BOARD
***********************************************************************/
void Board::populateInitialBoard() {

    //start
    createCharacter(link, 0, 0);
    startSpace = gameBoard[0][0];
    createItem(sword, 0, 3);

    //Shield obstacle
    replaceSpace(rock, 0,8);
    createItem(shield, 0,7);
    replaceSpace(rock, 1,8);
    replaceSpace(rock, 1,7);
    replaceSpace(rock, 1,6);
    createCharacter(octorok, 2, 8);
    createCharacter(octorok, 4, 6);
    createCharacter(octorok, 4, 3);
    createItem(potion, 4,7);

    //Hammer is in middle
    createItem(hammer, 4, 15);
    createCharacter(likelike, 3, 15);
    createCharacter(likelike, 3, 16);
    createCharacter(likelike, 5, 12);
    createCharacter(likelike, 7, 8);
    createItem(potion, 3, 17);

    //key obstacle on top
    replaceSpace(rock, 3, 29);
    replaceSpace(rock, 3, 28);
    replaceSpace(rock, 4, 28);
    replaceSpace(rock, 5, 28);
    replaceSpace(rock, 5, 29);
    createItem(key, 4, 29);
    createCharacter(tektite, 0, 25);
    createCharacter(tektite, 3, 25);
    createCharacter(tektite, 4, 19);
    createCharacter(tektite, 5, 20);
    createItem(potion, 4, 20);

    //Aquamentus guards triforce
    replaceSpace(vortex, 8,28);
    replaceSpace(vortex, 8,27);
    replaceSpace(vortex, 8,26);
    replaceSpace(door, 8,25);
    replaceSpace(vortex, 8,24);
    replaceSpace(vortex, 9,24);
    createCharacter(aquamentus, 9, 25);
    createItem(triforce, 9, 29);


    //random enemies and spaces
    createItem(potion, 1, 24);
    createItem(potion, 8, 12);
    createItem(potion, 9, 20);
    createCharacter(tektite, 2, 16);
    createCharacter(tektite, 3, 17);
    createCharacter(octorok, 9, 0);
    createCharacter(octorok, 8, 3);
    createCharacter(likelike, 7, 11);

}

void Board::replaceSpace(spaceType s, int x, int y) { //note, this does not link spaces

    Space *oldSpace = gameBoard[x][y];
    Space* newSpace = nullptr;

    //allocate memory for the new space
    switch(s)
    {
        case blank :
            newSpace = new Blank();
            break;
        case rock :
            newSpace = new Rock();
            break;
        case door :
            newSpace = new Door();
            break;
        case vortex :
            newSpace = new Vortex();
            break;
    }

    //copy the pointers over
    newSpace->setPointers(oldSpace->getUp(), oldSpace->getRight(), oldSpace->getDown(), oldSpace->getLeft());

    //delete the old space
    delete oldSpace;

    //update the gameBoard to point to the new space
    gameBoard[x][y] = newSpace;
}

void Board::createCharacter(characterType t, int x, int y) {

    //allocates memory for a new character, pointers for both space and character updated
    switch(t)
    {
        case link :
            gameBoard[x][y]->setCharacter(new Link(gameBoard[x][y]));
            break;
        case tektite :
            gameBoard[x][y]->setCharacter(new Tektite(gameBoard[x][y]));
            break;
        case octorok :
            gameBoard[x][y]->setCharacter(new Octorok(gameBoard[x][y]));
            break;
        case likelike :
            gameBoard[x][y]->setCharacter(new LikeLike(gameBoard[x][y]));
            break;
        case aquamentus :
            gameBoard[x][y]->setCharacter(new Aquamentus(gameBoard[x][y]));
            break;
    }
}

void Board::createItem(itemType t, int x, int y) {

    switch(t)
    {
        case sword :
            gameBoard[x][y]->setItem(new Item(sword));
            break;
        case potion :
            gameBoard[x][y]->setItem(new Item(potion));
            break;
        case shield :
            gameBoard[x][y]->setItem(new Item(shield));
            break;
        case hammer :
            gameBoard[x][y]->setItem(new Item(hammer));
            break;
        case key :
            gameBoard[x][y]->setItem(new Item(key));
            break;
        case triforce :
            gameBoard[x][y]->setItem(new Item(triforce));
            break;
    }
}

void Board::linkSpaces() {
    Space* u = nullptr;
    Space* r = nullptr;
    Space* d = nullptr;
    Space* l = nullptr;

    for(int i=0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            //choose up
            if(i==0) //if top of the board
            {
                u = nullptr; //set to nullptr
            } else {
                u = gameBoard[i-1][j]; //otherwise, set to space above
            }

            //choose right
            if(j==(numCols-1)) //if right edge of the board
            {
                r = nullptr; //point to nullptr
            } else {
                r = gameBoard[i][j+1]; //otherwise, point to space to the right
            }

            //choose down
            if(i==(numRows-1)) //if bottom of the board
            {
                d = nullptr; //set it to nullptr
            } else {
                d = gameBoard[i+1][j]; //otherwise, set it to square below
            }

            //choose left
            if(j==0) //if left edge of the board
            {
                l = nullptr; //set it to nullptr
            } else {
                l = gameBoard[i][j-1]; //otherwise, set it to the square to the left
            }

            gameBoard[i][j]->setPointers(u, r, d, l); //now, set all the pointers of the square
        }
    }

}

/**********************************************************************
BOARD MOVE LOGIC FUNCTIONS
***********************************************************************/
void Board::moveCharacter(Character *c, direction d) {

    //set the space pointers
    Space* a = c->getCurrentSpace(); //set the current space
    Space* b = nextSpace(a, d); //get the next space

    //if off the board, quit the function
    if(offBoard(b)) {
        if(c->getCharacterType()==link) {
            cout << "Can't move off the board!" << endl;
        }
        return;
    }

    //handle space event - does not move, just updates occupied status (except vortex which does move link)
    switch(b->getSpaceType())
    {
        case door :
            b->unlockDoor(c); //updates occupied status if it's link and he has a key (removes key)
            break;
        case rock :
            b->breakRock(c); //updates occupied status if it's link and he has a hammer
            break;
        case vortex :
            if(b->sendBacktoStart(c)) //if it's link
            {
                boardMove(c, a, startSpace); //send him back to the start
            }
            return; //turn is over so return
        case blank :
            //do nothing
            break;
    }

    //handle item event - updates occupied status, moves and picks up item
    if(b->getItem()!= nullptr && c->getCharacterType()==link) //if there's an item and it's link
    {
        //move link to the square
        b->setOccupied(false); //allow the space to be occupied
        boardMove(c, a, b);

        //pick up the item
        switch(b->getItem()->getType())
        {
            case potion : //if it's a potion, delete the item and restore his health
                cout << "You picked up a potion and restored your health!" << endl;
                c->setHealth(30);
                delete b->getItem();
                b->setItem(nullptr);
                return;
            case triforce : //if its the triforce, flag the game as over
                triforceScreen();
                gameOver = true;
                break;
            default :
                cout << "You picked up a " << itemTypeStrings[b->getItem()->getType()] << "!" << endl;
                break;
        }
        c->addItem(b->getItem()); //add it to the character's container
        b->setItem(nullptr); //remove the item from the square
        return; //move is now over so return
    }

    //handle character fight event
    if(b->getCharacter()!=nullptr) //if there is a character in the square
    {
        //if one of the two is link, then fight, otherwise don't fight and don't move, but return
        if(c->getCharacterType()==link || b->getCharacter()->getCharacterType()==link)
        {
            if(fight(c, b->getCharacter()))
            {
                //attacker wins fight
                if(b->getCharacter()->getCharacterType()==link)
                {
                    gameOver = true; //if link was the defender, flag game as over
                }

                delete b->getCharacter(); //kill the defender
                b->setCharacter(nullptr); //remove the dangling pointer
                boardMove(c, a, b); //move player to square
                return; //exit the function

            } else {
                //the defender wins the fight
                if(c->getCharacterType()==link)
                {
                    gameOver = true; //if link was the attacker, flag game as over
                }

                delete c; //kill the attacker
                a->setCharacter(nullptr); //remove the dangling pointer
                return; //move is over, so exit the function
            }

        } else {
            return;
        }
    }

    //now that space events, item events and fighting events have been considered, move the character
    boardMove(c, a, b);

}

void Board::boardMove(Character *c, Space *a, Space *b) {
    if(!b->isOccupied()) //if the space is not occupied
    {
        a->setCharacter(nullptr); //remove from space a
        b->setCharacter(c); //move to space b
        c->setCurrentSpace(b); //update the character's current space
    }
}

bool Board::offBoard(Space *s) {
    return (s==nullptr);
}

Space* Board::nextSpace(Space* a, direction d) {
    switch(d)
    {
        case up :
            return a->getUp();
        case right :
            return a->getRight();
        case down :
            return a->getDown();
        case left :
            return a->getLeft();
        default:
            return a;
    }
}

bool Board::fight(Character *a, Character *b) {
    bool aWins = true;

    cout << "**********************************FIGHT**********************************" << endl;
    cout << characterTypeStrings[a->getCharacterType()] << " wants to fight " << characterTypeStrings[b->getCharacterType()] << endl;
    while(a->getHealth() > 0 && b->getHealth() > 0)
    {
        b->defense(a->attack()); //player A attacks first
        aWins = true;
        if(b->getHealth() > 0) //if player B is still alive
        {
            a->defense(b->attack()); //player B attacks second
            aWins = false;
        }
    }

    return aWins;
}
/**********************************************************************
GETTERS AND SETTERS
***********************************************************************/
bool Board::getGameOver() {
    return gameOver;
}

int Board::getNumRows() {
    return numRows;
}

int Board::getNumCols() {
    return numCols;
}

Character* Board::getSpaceCharacter(int x, int y) {
    return gameBoard[x][y]->getCharacter();
}

/**********************************************************************
BOARD PRINT FUNCTION
***********************************************************************/
void Board::printBoard() {

    cout << "————————————————————————————————" << endl;

    for(int i = 0; i < numRows; i++)
    {
        cout << "|";
        for(int j =0 ; j < numCols; j++)
        {
            cout << gameBoard[i][j]->getRepresentation();
        }
        cout << "|" << endl;
    }

    cout << "————————————————————————————————" << endl;
}

void Board::triforceScreen() {

    cout << "---------------------------------" << endl;
    cout << "    YOU GOT THE TRIFORCE!        " << endl;
    cout << "---------------------------------" << endl;
    cout << "*********************************" << endl;
    cout << "                *                " << endl;
    cout << "               ***               " << endl;
    cout << "              *****              " << endl;
    cout << "             *******             " << endl;
    cout << "            *       *            " << endl;
    cout << "           ***     ***           " << endl;
    cout << "          *****   *****          " << endl;
    cout << "         ******* *******         " << endl;
    cout << "*********************************" << endl;
    cout << "You won! Game over." << endl;

}