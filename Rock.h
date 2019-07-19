/**********************************************************************
Author: Shane
Purpose: Implementation of the Rock class
Date: Monday March 12th 2018
***********************************************************************/
#ifndef FINALPROJECT_ROCK_H
#define FINALPROJECT_ROCK_H

#include "Space.h"

class Rock : public Space {
public:
    Rock(); //default constructor
    ~Rock() override;//destructor

    void breakRock(Character* c) override; //pure abstract for rock
    bool sendBacktoStart(Character* c) override ; //pure abstract for vortex
    void unlockDoor(Character* c) override;//pure abstract for door

};


#endif //FINALPROJECT_ROCK_H
