/**********************************************************************
Author: Shane
Purpose: implementation of the Dice class
Date: Monday March 12th 2018
***********************************************************************/

#include "Dice.h"
#include <ctime>
#include <iostream>

using std::time;
using std::srand;
using std::rand;

using std::cout;
using std::endl;

/**********************************************************************
CONSTRUCTORS AND DESTRUCTOR
***********************************************************************/
Dice::Dice() {
    setSides(6); //default sides is 6
}

Dice::Dice(int s) {
    setSides(s); //sets sides to s
}

Dice::~Dice() {
    //does nothing right now
}

/**********************************************************************
SETTERS AND GETTERS
***********************************************************************/
void Dice::setSides(int s) {
    sides = s;
}

int Dice::getSides() {
    return sides;
}

/**********************************************************************
ROLL
***********************************************************************/
int Dice::roll() {
    int temp = 0;

    temp = rand() % (sides) + 1;

    return temp;
}