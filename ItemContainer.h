/**********************************************************************
Author: Shane
Purpose: Implementation of the ItemContainer class
Date: Monday March 12th 2018
 this holds the items for each character
***********************************************************************/

#ifndef FINALPROJECT_ITEMCONTAINER_H
#define FINALPROJECT_ITEMCONTAINER_H

#include "Item.h"


class ItemContainer {
private:
    Item* head;
    Item* tail;

public:
    ItemContainer(); // default constructor
    ~ItemContainer(); //destructor destroys items in the container

    void addItem(Item* i); //adds an item to the back of the container
    bool isEmpty(); //returns whether or not the container is empty
    void removeItem(itemType t); //removes and deletes an item of a given type from the container
    bool inContainer(itemType i); //iterates through container and returns true if item is in it
    void printItems();

};


#endif //FINALPROJECT_ITEMCONTAINER_H
