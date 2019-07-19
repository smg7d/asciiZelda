/**********************************************************************
Author: Shane
Purpose: declaration of the Tektite class
Date: Monday March 12th 2018
***********************************************************************/

#ifndef FINALPROJECT_TEKTITE_H
#define FINALPROJECT_TEKTITE_H

#include "Character.h"
#include "Space.h"


class Tektite : public Character {

public:
    Tektite(Space* s); //default constructor
    ~Tektite() override; //destructor

    int attack() override; //pure virtual attack function to be overridden in derived classes
    void defense(int a) override; //pure virtual attack function to be overridden in derived classes
};


#endif
