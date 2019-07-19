/**********************************************************************
Author: Shane
Purpose: Implementation of the LikeLike class
Date: Monday March 12th 2018
***********************************************************************/

#include "LikeLike.h"
#include <iostream>

using std::cout;
using std::endl;

/**********************************************************************
CONSTRUCTORS AND DESTRUCTOR
***********************************************************************/
LikeLike::LikeLike(Space* s) : Character(likelike) {
    numOfAttackDice = 1;
    numOfDefenseDice = 1;

    attackDiceSides = 6;
    defendDiceSides = 6;
    armor = 3;
    health = 10;
    representation = 'l';

    currentSpace = s;

    Character::initializeDice();
}

LikeLike::~LikeLike() {
    //does nothing for now
}


/**********************************************************************
COMBAT FUNCTIONS
***********************************************************************/
int LikeLike::attack() {
    int roll = 0;

    for(int i = 0; i < numOfAttackDice; i++) //for each attack dice
    {
        roll += attackDice[i]->roll(); //roll the dice and add it to the total
    }

    cout << "LikeLike attacked";

    return roll;
}

void LikeLike::defense(int a) {
    int roll = 0;
    int damage = 0;

    for(int i = 0; i < numOfDefenseDice; i++) //for each attack dice
    {
        roll += defenseDice[i]->roll(); //roll the dice and add it to the total
    }

    damage = a - roll - armor; //calculate the damage

    if(damage <= 0)
    {
        damage = 0;
    }

    cout << " and LikeLike defended but took " << damage << " points of damage." << endl;

    health -= damage; //decrement health accordingly

    if(health <= 0)
    {
        cout << "LikeLike died." << endl;
    }
}
