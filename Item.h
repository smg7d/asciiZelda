/**********************************************************************
Author: Shane
Purpose: declaration of the Item class
Date: Monday March 12th 2018
***********************************************************************/

#ifndef FINALPROJECT_ITEM_H
#define FINALPROJECT_ITEM_H

#include <string>
using std::string;

enum itemType { sword, potion, shield, hammer, key, triforce };
const string itemTypeStrings[6] = {"Sword", "Potion", "Shield", "Hammer", "Key", "Triforce"};

class Item {
private:
    itemType iType;
    char representation;
    Item* nextItem = nullptr;

public:
    Item(itemType i); //sets the type of item it is
    ~Item(); //default destructor does nothing for now

    itemType getType(); //returns the type of item it is
    char getRepresentation(); //returns the representation of the item
    Item* getNextItem(); //returns the pointer to the next item
    void setNextItem(Item* it); //sets the nextItem pointer to the passed argument

};


#endif //FINALPROJECT_ITEM_H
