/**********************************************************************
Author: Shane
Purpose: Implementation of the Tektite class
Date: Monday March 12th 2018
***********************************************************************/

#include "Tektite.h"
#include <iostream>

using std::cout;
using std::endl;

/**********************************************************************
CONSTRUCTORS AND DESTRUCTOR
***********************************************************************/
Tektite::Tektite(Space* s) : Character(tektite) {
    numOfAttackDice = 1;
    numOfDefenseDice = 2;

    attackDiceSides = 10;
    defendDiceSides = 6;
    armor = 1;
    health = 12;
    representation = 't';

    currentSpace = s;

    Character::initializeDice();
}

Tektite::~Tektite() {
    //does nothing for now
}


/**********************************************************************
COMBAT FUNCTIONS
***********************************************************************/
int Tektite::attack() {
    int roll = 0;

    for(int i = 0; i < numOfAttackDice; i++) //for each attack dice
    {
        roll += attackDice[i]->roll(); //roll the dice and add it to the total
    }

    cout << "Tektite attacked";

    return roll;
}

void Tektite::defense(int a) {
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

    cout << " and Tektite defended but took " << damage << " points of damage." << endl;

    health -= damage; //decrement health accordingly

    if(health <= 0)
    {
        cout << "Tektite died." << endl;
    }
}