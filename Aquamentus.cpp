/**********************************************************************
Author: Shane
Purpose: Implementation of the Aquamentus class
Date: Monday March 12th 2018
***********************************************************************/

#include "Aquamentus.h"
#include <iostream>

using std::cout;
using std::endl;

/**********************************************************************
CONSTRUCTORS AND DESTRUCTOR
***********************************************************************/
Aquamentus::Aquamentus(Space* s) : Character(aquamentus) {
    numOfAttackDice = 3;
    numOfDefenseDice = 3;

    attackDiceSides = 5;
    defendDiceSides = 5;
    armor = 3;
    health = 20;
    representation = 'A';

    currentSpace = s;

    Character::initializeDice();
}

Aquamentus::~Aquamentus() {
    //does nothing for now
}


/**********************************************************************
COMBAT FUNCTIONS
***********************************************************************/
int Aquamentus::attack() {
    int roll = 0;
    bool fireBall = false;

    for(int i = 0; i < numOfAttackDice; i++) //for each attack dice
    {
        roll += attackDice[i]->roll(); //roll the dice and add it to the total
    }

    fireBall = static_cast<bool>(rand() % 2);

    if(fireBall)
    {
        cout << "Aquamentus attacked with fireball";
        roll+=3; //add 3 to the roll
    } else {
        cout << "Aquamentus attacked";
    }

    return roll;
}

void Aquamentus::defense(int a) {
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

    cout << " and Aquamentus defended but took " << damage << " points of damage." << endl;

    health -= damage; //decrement health accordingly

    if(health <= 0)
    {
        cout << "Aquamentus died." << endl;
    }
}