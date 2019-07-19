/**********************************************************************
Author: Shane
Purpose: declaration of the Octorok class
Date: Monday March 12th 2018
***********************************************************************/

#ifndef FINALPROJECT_OCTOROK_H
#define FINALPROJECT_OCTOROK_H

#include "Character.h"
#include "Space.h"


class Octorok : public Character {

public:
    Octorok(Space* s); //default constructor
    ~Octorok() override; //destructor

    int attack() override; //pure virtual attack function to be overridden in derived classes
    void defense(int a) override; //pure virtual attack function to be overridden in derived classes
};


#endif //FINALPROJECT_OCTOROK_H
