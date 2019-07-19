/**********************************************************************
Author: Shane
Purpose: Implementation of the Vortex class
Date: Monday March 12th 2018
***********************************************************************/

#ifndef FINALPROJECT_VORTEX_H
#define FINALPROJECT_VORTEX_H

#include "Space.h"

class Vortex : public Space {
public:
    Vortex(); //default constructor
    ~Vortex() override;//destructor

    void breakRock(Character* c) override; //pure abstract for rock
    bool sendBacktoStart(Character* c) override ; //pure abstract for vortex
    void unlockDoor(Character* c) override;//pure abstract for door

};

#endif //FINALPROJECT_VORTEX_H
