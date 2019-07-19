/**********************************************************************
Author: Shane
Purpose: Implementation of the Door class
Date: Monday March 12th 2018
***********************************************************************/

#include "Door.h"
#include <iostream>

using std::cout;
using std::endl;

/**********************************************************************
CONSTRUCTOR AND DESTRUCTOR
***********************************************************************/
Door::Door() {
    representation = 'd';
    occupied = true;
    sType = door;
}

Door::~Door() {
    //destructor does nothing for now
}

/**********************************************************************
OTHER MEMBER FUNCTIONS
***********************************************************************/
void Door::breakRock(Character* c) {
    cout << "Error: Door can't break rock." << endl;
}

bool Door::sendBacktoStart(Character *c) {
    cout << "Error: Door can't send people back to the start." << endl;
}

void Door::unlockDoor(Character* c) {
    if(c->hasItem(key) && c->getCharacterType()==link) //if it's link and he has a key
    {
        cout << "you used your key to unlock the door! your key is now gone." << endl;
        c->removeItem(key);
        representation = ' ';
        occupied = false;
    } else if(c->getCharacterType()==link){
        cout << "This is a door. you need a key (k) to unlock it!" << endl;
    }
}

