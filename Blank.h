/**********************************************************************
Author: Shane
Purpose: Implementation of the Blank class
Date: Monday March 12th 2018
***********************************************************************/

#ifndef FINALPROJECT_BLANK_H
#define FINALPROJECT_BLANK_H

#include "Space.h"

class Blank : public Space {
public:
    Blank(); //default constructor sends all pointers to nullptr
    Blank(Space* u, Space* r, Space* d, Space* l); //default constructor
    ~Blank() override;//destructor

    void breakRock(Character* c) override; //pure abstract for rock
    bool sendBacktoStart(Character* c) override ; //pure abstract for vortex
    void unlockDoor(Character* c) override;//pure abstract for door

};

#endif //FINALPROJECT_BLANK_H
