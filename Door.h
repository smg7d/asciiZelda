/**********************************************************************
Author: Shane
Purpose: Implementation of the Door class
Date: Monday March 12th 2018
***********************************************************************/
#ifndef FINALPROJECT_DOOR_H
#define FINALPROJECT_DOOR_H

#include "Space.h"

class Door : public Space {
public:
    Door(); //default constructor
    ~Door() override;//destructor

    void breakRock(Character* c) override; //pure abstract for rock
    bool sendBacktoStart(Character* c) override ; //pure abstract for vortex
    void unlockDoor(Character* c) override;//pure abstract for door

};

#endif //FINALPROJECT_DOOR_H
