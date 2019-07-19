/**********************************************************************
Author: Shane
Purpose: declaration of the Aquamentus class
Date: Monday March 12th 2018
***********************************************************************/


#ifndef FINALPROJECT_AQUAMENTUS_H
#define FINALPROJECT_AQUAMENTUS_H

#include "Character.h"
#include "Space.h"


class Aquamentus : public Character {

public:
    Aquamentus(Space* s); //default constructor
    ~Aquamentus() override; //destructor

    int attack() override; //pure virtual attack function to be overridden in derived classes
    void defense(int a) override; //pure virtual attack function to be overridden in derived classes
};


#endif
