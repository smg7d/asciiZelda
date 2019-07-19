/**********************************************************************
Author: Shane
Purpose: Implementation of the Link class
Date: Monday March 12th 2018
***********************************************************************/

#include "Link.h"
#include <iostream>

using std::cout;
using std::endl;

/**********************************************************************
CONSTRUCTORS AND DESTRUCTOR
***********************************************************************/
Link::Link(Space* s) : Character(link) {
    numOfAttackDice = 2;
    numOfDefenseDice = 2;

    attackDiceSides = 6;
    defendDiceSides = 6;
    armor = 0;
    health = 30;
    representation = 'X';

    currentSpace = s;

    Character::initializeDice();
}

Link::~Link() {
    //does nothing for now
}


/**********************************************************************
COMBAT FUNCTIONS
***********************************************************************/
int Link::attack() {
    int roll = 0;

    for(int i = 0; i < numOfAttackDice; i++) //for each attack dice
    {
        roll += attackDice[i]->roll(); //roll the dice and add it to the total
    }

    if(hasItem(sword))
    {
        cout << "Link attacked with his sword";
        return roll + 3; //if link has a sword, add 3
    } else {
        cout << "Link attacked";
        return roll;
    }

}

void Link::defense(int a) {
    int roll = 0;
    int damage = 0;

    for(int i = 0; i < numOfDefenseDice; i++) //for each attack dice
    {
        roll += defenseDice[i]->roll(); //roll the dice and add it to the total
    }

    if(hasItem(shield))
    {
        cout << " and Link defended with his shield,";
        roll += 3;
    } else {
        cout << " and Link defended the attack,";
    }

    damage = a - roll - armor; //calculate the damage

    if(damage <= 0)
    {
        damage = 0;
    }

    cout << " but took " << damage << " points of damage." << endl;

    health -= damage; //decrement health accordingly

    if(health <= 0)
    {
        cout << "Oh no! You've run out of health. Game over!" << endl;
    }
}
