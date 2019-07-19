/**********************************************************************
Author: Shane
Purpose: Implementation of the Blank class
Date: Monday March 12th 2018
***********************************************************************/

#include "Blank.h"
#include <iostream>

using std::cout;
using std::endl;

/**********************************************************************
CONSTRUCTOR AND DESTRUCTOR
***********************************************************************/
Blank::Blank() {
    up = nullptr;
    right = nullptr;
    down = nullptr;
    left = nullptr;

    representation = ' ';
    occupied = false;
    sType = blank;
}

Blank::Blank(Space *u, Space *r, Space *d, Space *l) : Space(u, r, d, l) {
    representation = ' ';
    occupied = false;
    sType = blank;
}

Blank::~Blank() {
    //destructor does nothing for now
}

/**********************************************************************
OTHER MEMBER FUNCTIONS
***********************************************************************/
void Blank::breakRock(Character* c) {
    cout << "Error: Blank can't be a broken rock." << endl;
}

bool Blank::sendBacktoStart(Character *c) {
    cout << "Error: Blank can't send people back to the start." << endl;
}

void Blank::unlockDoor(Character* c) {
    cout << "Error: Blank can't be unlocked!" << endl;
}
