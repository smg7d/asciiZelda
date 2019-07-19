/**********************************************************************
Author: Shane
Purpose: Implementation of the Item class
Date: Monday March 12th 2018
***********************************************************************/

#include "Item.h"

/**********************************************************************
CONSTRUCTOR AND DESTRUCTOR
***********************************************************************/
Item::Item(itemType i) {
    iType = i;
    nextItem = nullptr;

    //sets the representation based off the type
    switch(i)
    {
        case sword :
            representation = 'S';
            break;
        case potion :
            representation = 'P';
            break;
        case shield :
            representation = 'D';
            break;
        case hammer :
            representation = 'H';
            break;
        case key :
            representation = 'K';
            break;
        case triforce :
            representation = 'V';
            break;
    }
}

Item::~Item() {
    //destructor does nothing for now
}

/**********************************************************************
SETTERS AND GETTERS
***********************************************************************/
itemType Item::getType() {
    return iType;
}

char Item::getRepresentation() {
    return representation;
}

Item* Item::getNextItem() {
    return nextItem;
}

void Item::setNextItem(Item *it) {
    nextItem = it;
}