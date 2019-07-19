/**********************************************************************
Author: Shane
Purpose: declaration of the Link class
Date: Monday March 12th 2018
***********************************************************************/

#ifndef FINALPROJECT_LINK_H
#define FINALPROJECT_LINK_H

#include "Character.h"
#include "Space.h"


class Link : public Character {

public:
    Link(Space* s); //default constructor
    ~Link() override; //destructor

    int attack() override; //pure virtual attack function to be overridden in derived classes
    void defense(int a) override; //pure virtual attack function to be overridden in derived classes
};


#endif
