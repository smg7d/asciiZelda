/**********************************************************************
Author: Shane
Purpose: implementation of the Game class
Date: Monday March 12th 2018
***********************************************************************/
#include "Game.h"
#include "Rock.h"
#include "Door.h"
#include "Vortex.h"

#include "Link.h"
#include "Octorok.h"
#include "Tektite.h"
#include "LikeLike.h"
#include "Aquamentus.h"


#include <iostream>

using std::cout;
using std::endl;

/**********************************************************************
CONSTRUCTORS AND DESTRUCTOR
***********************************************************************/
Game::Game() {
    gBoard = new Board(); //create a new board
}

Game::~Game() {
    delete gBoard; //deallocate memory for the board
}

/**********************************************************************
MEMBER FUNCTIONS
***********************************************************************/
void Game::runTurn() {
    const int GAMEMENUNUMS = 6;
    string gameMenuOptions[GAMEMENUNUMS] = { "Move up", "Move right", "Move down", "Move left", "Info", "Quit"};
    Menu gameMenu(GAMEMENUNUMS, gameMenuOptions);

    int choice = 0;
    direction randMoveDirection = up;
    updateCharacterVector(); //get the existing characters

    //show the screen to the screen
    printTurn();

    //Let Link run his turn
    cout << "--------------------------------" << endl;
    cout << "           ACTION MENU          " << endl;
    cout << "--------------------------------" << endl;

    choice = gameMenu.getChoice();

    switch(choice)
    {
        case 1 :
            gBoard->moveCharacter(playerLink, up);
            playerLink->setHealth(playerLink->getHealth() - 1);
            break;
        case 2 :
            gBoard->moveCharacter(playerLink, right);
            playerLink->setHealth(playerLink->getHealth() - 1);
            break;
        case 3 :
            gBoard->moveCharacter(playerLink, down);
            playerLink->setHealth(playerLink->getHealth() - 1);
            break;
        case 4 :
            gBoard->moveCharacter(playerLink, left);
            playerLink->setHealth(playerLink->getHealth() - 1);
            break;
        case 5 :
            infoScreen();
            return;
        case 6 :
            cout << "Game has been quit." << endl;
            gameOver = true;
            return;
    }

    if(playerLink->getHealth() <= 0 && !gBoard->getGameOver()) //if the step count has run health down to zero, end the game
    {
        gameOver = true;
        cout << "You ran out of health from walking! Game over." << endl;
        return;
    }

    if(!gBoard->getGameOver()) //if the game is still going
    {
        updateCharacterVector(); //get the existing characters

        //move all the other characters
        for(int i = 0; i < cVector.size(); i++)
        {
            randMoveDirection = static_cast<direction>(rand() % 4);
            gBoard->moveCharacter(cVector[i], randMoveDirection);
        }
    }

    gameOver = (gBoard->getGameOver() || playerLink->hasItem(triforce)); //update game over status

}

void Game::runGame() {
    //menu variable declarations and definitions
    const int MAINMENUNUMS = 3;
    string mainMenuOptions[MAINMENUNUMS] = { "Play", "Info", "Quit"};
    Menu mainMenu(MAINMENUNUMS, mainMenuOptions);
    int mainChoice = 0;

    bool exitProgram = false;

    landingScreen();

    while(!exitProgram) {
        //display the menu

        cout << "-----------------------------------------------" << endl;
        cout << "                  MAIN MENU                    " << endl;
        cout << "-----------------------------------------------" << endl;
        mainChoice = mainMenu.getChoice();

        switch(mainChoice)
        {
            case 1 : //play a new game
                while(!gameOver)
                {
                    runTurn();
                }
                break;
            case 2 : //print info
                infoScreen();
                break;
            case 3 : //quit the program
                exitProgram = true;
                break;
        }
    }

    cout << "Program over. Powering off." << endl;
}

/**********************************************************************
PRIVATE HELPER FUNCTIONS
***********************************************************************/
void Game::updateCharacterVector() {
    //clear the vector
    cVector.clear();

    //for each space on the game board
    for(int i = 0; i < gBoard->getNumRows(); i++)
    {
        for(int j = 0; j < gBoard->getNumCols(); j++)
        {
            if(gBoard->getSpaceCharacter(i, j)!=nullptr) //if there is a character on the space
            {
                if(gBoard->getSpaceCharacter(i, j)->getCharacterType()==link) //and if that character is link
                {
                    playerLink = gBoard->getSpaceCharacter(i, j); //then update the link pointer
                } else {
                    cVector.push_back(gBoard->getSpaceCharacter(i, j)); //otherwise, add the character to the vector
                }
            }
        }
    }
}

/**********************************************************************
PRINTING FUNCTIONS HELPER FUNCTIONS
***********************************************************************/
void Game::landingScreen() {
    cout << "***********************************************" << endl;
    cout << "   ******  *****  **     *****       ***      " << endl;
    cout << "     **    **     **     **   **    ** **     " << endl;
    cout << "    **     *****  **     **    **  **   **    " << endl;
    cout << "   **      **     **     **    ** *********   " << endl;
    cout << "  *******  *****  *****  **********       **  " << endl;
    cout << "***********************************************" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "        WELCOME TO THE LEGEND OF ZELDA         " << endl;
    cout << "-----------------------------------------------" << endl;

}

void Game::infoScreen() {
    Item t(triforce);
    Item s(sword);
    Item d(shield);
    Item p(potion);
    Item k(key);
    Item h(hammer);

    Character* l = new Link(nullptr);
    Character* o = new Octorok(nullptr);
    Character* e = new Tektite(nullptr);
    Character* i = new LikeLike(nullptr);
    Character* a = new Aquamentus(nullptr);

    Space* localRock = new Rock();
    Space* localDoor = new Door();
    Space* localVortex = new Vortex();


    //Mission
    cout << "------------------------------------------------------------------" << endl;
    cout << "                              MISSION                             " << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Welcome to the Legend of Zelda!" << endl;
    cout << "Your mission is to move Link (" << l->getRepresentation() << ") to obtain the triforce (" << t.getRepresentation() <<")." << endl;

    //Enemies
    cout << "------------------------------------------------------------------" << endl;
    cout << "                              ENEMIES                             " << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Enemies with various strength and capabilities will attack to try" << endl;
    cout << "and prevent you on your quest." << endl;
    cout << "Octoroks (" << o->getRepresentation() << ") have " << o->getHealth() << " health." << endl;
    cout << "Tektites (" << e->getRepresentation() << ") have " << e->getHealth() << " health." << endl;
    cout << "LikeLikes (" << i->getRepresentation() << ") have " << i->getHealth() << " health." << endl;
    cout << "The dragon boss Aquamentus (" << a->getRepresentation() << ") has " << a->getHealth() << " health." << endl;

    //Items
    cout << "------------------------------------------------------------------" << endl;
    cout << "                               ITEMS                              " << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "There are various items to help you on your quest." << endl;
    cout << "A sword (" << s.getRepresentation() << ") will increase your attack by 3." << endl;
    cout << "A shield (" << d.getRepresentation() << ") will increase your defense by 3." << endl;
    cout << "A potion (" << p.getRepresentation() << ") will restore your health." << endl;

    //Spaces
    cout << "------------------------------------------------------------------" << endl;
    cout << "                              TERRAIN                             " << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "The terrain presents some difficulty." << endl;
    cout << "A rock (" << localRock->getRepresentation() << ") will prevent you from moving"
         " but you can break it with" << endl;
    cout << "a hammer (" << h.getRepresentation() << ")." << endl;

    cout << "A door (" << localDoor->getRepresentation() << ") will also prevent you from moving"
            " but you can open it" << endl;
    cout << "with a key (" << k.getRepresentation() << ")." << endl;

    cout << "A vortex (" << localVortex->getRepresentation() << ") will send you back to the start" << endl;
    cout << "Finally, walking takes away Link's strength, so be sure to use" << endl;
    cout << "potions to restore his health regularly!" << endl;

    cout << "That's it! Good luck on your quest." << endl;

    delete l;
    delete o;
    delete e;
    delete i;
    delete a;

    delete localRock;
    delete localDoor;
    delete localVortex;

}

void Game::printTurn() {
    cout << "********************************" << endl;
    cout << "Health: " << playerLink->getHealth() << endl;
    cout << "Items: ";
    playerLink->printItems();
    cout << endl;
    gBoard->printBoard();
}
