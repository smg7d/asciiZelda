/**********************************************************************
Author: Shane
Purpose: Implementation of the Space class
Date: Monday March 12th 2018
***********************************************************************/

#include "Space.h"

/**********************************************************************
CONSTRUCTOR AND DESTRUCTOR
***********************************************************************/
Space::Space() {
    up = nullptr;
    right = nullptr;
    down = nullptr;
    left = nullptr;

    character = nullptr;
    item = nullptr;
    representation = ' ';
    occupied = false;

    sType = blank;
}

Space::Space(spaceType s) {
    up = nullptr;
    right = nullptr;
    down = nullptr;
    left = nullptr;

    character = nullptr;
    item = nullptr;
    representation = ' ';
    occupied = false;

    sType = s;
}

Space::Space(Space *u, Space *r, Space *d, Space *l) {
    up = u;
    right = r;
    down = d;
    left = l;

    character = nullptr;
    item = nullptr;
    representation = ' ';
    occupied = false;
    sType = blank;
}

Space::~Space() {
    if(character!=nullptr)
    {
        delete character;
    }

    if(item!= nullptr)
    {
        delete item;
    }
}

/**********************************************************************
GETTERS AND SETTERS
***********************************************************************/
Space* Space::getUp() {
    return up;
}

Space* Space::getRight() {
    return right;
}

Space* Space::getDown() {
    return down;
}

Space* Space::getLeft() {
    return left;
}

bool Space::isOccupied() {
    return occupied;
}

void Space::setOccupied(bool b) {
    occupied = b;
}

spaceType Space::getSpaceType() {
    return sType;
}

Character* Space::getCharacter() {
    return character;
}

void Space::setCharacter(Character *c) {
    character = c;
}

Item* Space::getItem() {
    return item;
}

void Space::setItem(Item *i) {
    item = i;
    if(i==nullptr){
        occupied = false;
    } else{
        occupied = true;
    }
}

void Space::setPointers(Space *u, Space *r, Space *d, Space *l) {
    up = u;
    right = r;
    down = d;
    left = l;
}

char Space::getRepresentation() {
    if(character!= nullptr)
    {
        return character->getRepresentation();
    }

    if(item!= nullptr)
    {
        return item->getRepresentation();
    }

    return representation;
}