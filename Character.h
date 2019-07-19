/**********************************************************************
Author: Shane
Purpose: declaration of the Character class
Date: Monday March 12th 2018
***********************************************************************/

#ifndef FINALPROJECT_CHARACTER_H
#define FINALPROJECT_CHARACTER_H

#include "Dice.h"
#include "ItemContainer.h"
//#include "Space.h"
#include <string>

class Space; //forward declaration to avoid circular dependencies

using std::string;

enum characterType { link, tektite, octorok, likelike, aquamentus };
const string characterTypeStrings[5] = { "Link", "Tektite", "Octorok", "LikeLike", "Aquamentus" };

class Character {
protected:
    characterType cType;
    int numOfAttackDice;
    int numOfDefenseDice;
    int attackDiceSides;
    int defendDiceSides;
    int armor;
    int health;
    char representation;

    ItemContainer items;

    Space* currentSpace;

    Dice** attackDice;
    Dice** defenseDice;

    void initializeDice(); //creates and fills the dice arrays based on dice information

public:
    Character(); //default constructor
    Character(characterType t); //primary constructor
    virtual ~Character(); //destroys the dice

    //getters and setters
    Space* getCurrentSpace(); //returns the current space
    void setCurrentSpace(Space* s); //sets the current space

    int getHealth(); //returns the health
    void setHealth(int a); //sets the strength of a character

    characterType getCharacterType(); //returns the character type
    char getRepresentation(); //returns the representation of the character in the game

    //combat functions
    virtual int attack() = 0; //pure virtual attack function to be overridden in derived classes
    virtual void defense(int a) = 0; //pure virtual attack function to be overridden in derived classes

    //item container functions
    void addItem(Item* i);
    void removeItem(itemType t);
    bool hasItem(itemType t);
    void printItems();

};

#endif //FINALPROJECT_CHARACTER_H
