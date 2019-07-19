/**********************************************************************
Author: Shane
Purpose: Implementation of the Vortex class
Date: Monday March 12th 2018
***********************************************************************/

#include "Vortex.h"
#include "Board.h"
#include <iostream>

using std::cout;
using std::endl;


/**********************************************************************
CONSTRUCTOR AND DESTRUCTOR
***********************************************************************/
Vortex::Vortex() {
    representation = 'E';
    occupied = true; //don't allow anyone here
    sType = vortex;
}

Vortex::~Vortex() {
    //destructor does nothing for now
}

/**********************************************************************
OTHER MEMBER FUNCTIONS
***********************************************************************/
void Vortex::breakRock(Character* c) {
    cout << "Error: Vortex can't be a broken rock." << endl;
}

bool Vortex::sendBacktoStart(Character *c) {
    if(c->getCharacterType()==link)
    {
        cout << "You stepped into a vortex! you are now back at the start." << endl;
        return true;
    }

    return false;

}

void Vortex::unlockDoor(Character* c) {
    cout << "Error: rock can't be unlocked!" << endl;
}
