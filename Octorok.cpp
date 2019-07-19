/**********************************************************************
Author: Shane
Purpose: Implementation of the Octorok class
Date: Monday March 12th 2018
***********************************************************************/

#include "Octorok.h"
#include <iostream>

using std::cout;
using std::endl;

/**********************************************************************
CONSTRUCTORS AND DESTRUCTOR
***********************************************************************/
Octorok::Octorok(Space* s) : Character(octorok) {
    numOfAttackDice = 1;
    numOfDefenseDice = 1;

    attackDiceSides = 12;
    defendDiceSides = 6;
    armor = 0;
    health = 8;
    representation = 'o';

    currentSpace = s;

    Character::initializeDice();
}

Octorok::~Octorok() {
    //does nothing for now
}


/**********************************************************************
COMBAT FUNCTIONS
***********************************************************************/
int Octorok::attack() {
    int roll = 0;

    for(int i = 0; i < numOfAttackDice; i++) //for each attack dice
    {
        roll += attackDice[i]->roll(); //roll the dice and add it to the total
    }

    cout << "Octorok attacked";

    return roll;
}

void Octorok::defense(int a) {
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

    cout << " and Octorok defended but took " << damage << " points of damage." << endl;

    health -= damage; //decrement health accordingly

    if(health <= 0)
    {
        cout << "Octorok died." << endl;
    }
}