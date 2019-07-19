/**********************************************************************
Author: Shane
Purpose: Implementation of the Character class
Date: Monday March 12th 2018
***********************************************************************/


#include "Character.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;


/**********************************************************************
CONSTRUCTORS AND DESTRUCTOR
***********************************************************************/
Character::Character() {
    numOfAttackDice = 0;
    numOfDefenseDice = 0;

    attackDice = nullptr;
    defenseDice = nullptr;
}

Character::Character(characterType t) {

    cType = t;

    numOfAttackDice = 0;
    numOfDefenseDice = 0;

    attackDice = nullptr;
    defenseDice = nullptr;

}

Character::~Character() {
    if(attackDice!= nullptr) //if there is an attack dice array
    {
        for(int i = 0; i < numOfAttackDice; i++) //for each dice in the array
        {
            delete attackDice[i]; //delete it
        }

        delete[] attackDice; //and then delete the pointer to the array
    }

    if(defenseDice!=nullptr) //if there is a defense dice array
    {
        for(int i =0; i <numOfDefenseDice; i++) //for each dice in the array
        {
            delete defenseDice[i]; //delete it
        }

        delete[] defenseDice; //and then delete the pointer to the array
    }
}

/**********************************************************************
PRIVATE FUNCTIONS
***********************************************************************/
void Character::initializeDice() {
    //initialize the attack dice array
    if(numOfAttackDice > 0) { //if there is 1 or more attack dice

        attackDice = new Dice*[numOfAttackDice]; //create a pointer to a new array of dice pointers
        for(int i = 0; i < numOfAttackDice; i++)
        {
            attackDice[i] = new Dice(attackDiceSides); //fill the array with dice pointers
        }
    } else {
        attackDice = nullptr; //if there are no dice, make the pointer null
    }


    //initialize the defense dice array
    if(numOfDefenseDice > 0) { //if there is 1 or more defense dice

        defenseDice = new Dice*[numOfDefenseDice]; //create a pointer to a new array of dice pointers
        for(int i = 0; i < numOfDefenseDice; i++)
        {
            defenseDice[i] = new Dice(defendDiceSides); //fill the array with dice pointers
        }
    } else {
        defenseDice = nullptr;
    }
}

/**********************************************************************
GETTERS AND SETTERS
***********************************************************************/
Space* Character::getCurrentSpace() {
    return currentSpace;
}

void Character::setCurrentSpace(Space *s) {
    currentSpace = s;
}

int Character::getHealth() {
    return health;
}

characterType Character::getCharacterType() {
    return cType;
}

void Character::setHealth(int a) {
    health = a;
}

char Character::getRepresentation() {
    return representation;
}

/**********************************************************************
FOR ITEM CONTAINERS
***********************************************************************/
void Character::addItem(Item *i) {
    items.addItem(i);
}

void Character::removeItem(itemType t) {
    items.removeItem(t);
}

bool Character::hasItem(itemType t) {
    return items.inContainer(t);
}

void Character::printItems() {
    items.printItems();
}