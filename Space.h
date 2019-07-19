/**********************************************************************
Author: Shane
Purpose: Implementation of the Item class
Date: Monday March 12th 2018
***********************************************************************/

#ifndef FINALPROJECT_SPACE_H
#define FINALPROJECT_SPACE_H

#include "Character.h"
#include "Item.h"
#include <string>

using std::string;

enum spaceType { blank, rock, door, vortex };
const string spaceTypeStrings[4] = { "blank space", "rock", "door", "vortex"};

class Space {
protected:
    spaceType sType;

    //pointers to the adjacent spaces
    Space* up = nullptr;
    Space* right = nullptr;
    Space* down = nullptr;
    Space* left = nullptr;

    Character* character; //points to the character occupying the space
    Item* item; //points to an item in the space
    char representation; //is how it's represented on the game board
    bool occupied = false; //denotes if something is occupying the space

public:
    Space(); //default constructor
    Space(spaceType s);
    Space(Space* u, Space* r, Space* d, Space* l); //constructor initializes private vars
    virtual ~Space(); //destructor destroys characters, items in its space

    Space* getUp(); //returns the "north" space
    Space* getRight(); //returns the "east" space
    Space* getDown(); //returns the "south" space
    Space* getLeft(); //returns the "west" space

    bool isOccupied(); //returns if the space is occupied or not
    void setOccupied(bool b); //updates the "occupied" field
    spaceType getSpaceType(); //returns the space type

    Character* getCharacter(); //returns the character pointer
    void setCharacter(Character* c); //sets the character pointer to the character
    Item* getItem(); //returns the item pointer
    void setItem(Item* i); //sets the item pointer to the passed item
    char getRepresentation(); //returns the representation of the space
    void setPointers(Space* u, Space* r, Space* d, Space* l); //set the pointers of the adjacent spaces

    virtual void breakRock(Character* c) = 0; //pure abstract for rock
    virtual bool sendBacktoStart(Character* c) = 0; //pure abstract for vortex
    virtual void unlockDoor(Character* c) = 0;//pure abstract for door



};


#endif //FINALPROJECT_SPACE_H
