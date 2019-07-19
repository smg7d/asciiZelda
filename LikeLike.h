/**********************************************************************
Author: Shane
Purpose: declaration of the LikeLike class
Date: Monday March 12th 2018
***********************************************************************/

#ifndef FINALPROJECT_LIKELIKE_H
#define FINALPROJECT_LIKELIKE_H

#include "Character.h"
#include "Space.h"

class LikeLike : public Character {

public:
    LikeLike(Space* s); //default constructor
    ~LikeLike() override; //destructor

    int attack() override; //pure virtual attack function to be overridden in derived classes
    void defense(int a) override; //pure virtual attack function to be overridden in derived classes
};


#endif