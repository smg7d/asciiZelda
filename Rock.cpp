/**********************************************************************
Author: Shane
Purpose: Implementation of the Rock class
Date: Monday March 12th 2018
***********************************************************************/

#include "Rock.h"
#include <iostream>

using std::cout;
using std::endl;

/**********************************************************************
CONSTRUCTOR AND DESTRUCTOR
***********************************************************************/
Rock::Rock() {
    representation = 'R';
    occupied = true;
    sType = rock;
}

Rock::~Rock() {
    //destructor does nothing for now
}

/**********************************************************************
OTHER MEMBER FUNCTIONS
***********************************************************************/
void Rock::breakRock(Character* c) {
    if(c->hasItem(hammer))
    {
        cout << "You used your hammer to break the rock!" << endl;
        representation = ' ';
        occupied = false;
    } else if(c->getCharacterType()==link){
        cout << "This is a rock. You need a hammer to break it" << endl;
    }
}

bool Rock::sendBacktoStart(Character *c) {
    cout << "Error: Rock can't send people back to the start." << endl;
}

void Rock::unlockDoor(Character* c) {
    cout << "Error: rock can't be unlocked!" << endl;
}

