/**********************************************************************
Author: Shane
Purpose: Implementation of the ItemContainer class
Date: Monday March 12th 2018
***********************************************************************/

#include "ItemContainer.h"
#include <iostream>

using std::cout;
using std::endl;

/**********************************************************************
GETTERS AND SETTERS
***********************************************************************/
ItemContainer::ItemContainer() { //default constructor sets head to null
    head = nullptr;
    tail = nullptr;
}

ItemContainer::~ItemContainer() {
    Item* temp = head;
    Item* garbage;

    while(temp!= nullptr)
    {
        garbage = temp; //store the item to be deleted
        temp = temp->getNextItem(); //move the temp pointer down the list
        delete garbage; //de-allocate the memory
    }
}

/**********************************************************************
OTHER FUNCTIONS
***********************************************************************/
bool ItemContainer::isEmpty() {
    return head == nullptr;
}

void ItemContainer::addItem(Item *i) {
    if(isEmpty())
    {
        head = i;
        tail = i;
        i->setNextItem(nullptr);
    } else {
        //point the tail forward
        tail->setNextItem(i);
        //point the item to the null pointer
        i->setNextItem(nullptr);
        //update tail to point to the new item
        tail = i;
    }
}

void ItemContainer::removeItem(itemType t) {
    Item* target = head; //start at the head
    Item* temp;
    bool found = false;

    if(target->getType()==t) //if the target item is the first item in the container
    {
        head = target->getNextItem();
        found = true;
        delete target;

        if(head==nullptr) //if the list is now empty
        {
            tail = nullptr;
        }
    } else { //then the target is not the first item in the container

        temp = target; //save the previous item
        target = target->getNextItem(); //move the target pointer forward one
        while(target!= nullptr)
        {
            if(target->getType()==t) //then we want to remove this object
            {
                temp->setNextItem(target->getNextItem()); //point the previous item to the next one
                delete target; //deallocate the memory
                found = true;

                if(temp->getNextItem()== nullptr) //if we're deleting the last item on the list
                {
                    tail = temp; //then update the tail pointer
                }

                break;

            } else { //move the pointers forward one
                temp = target; //move the temp pointer forward one
                target = target->getNextItem(); //move the target pointer forward one
            }

        }
    }

    if(!found)
    {
        cout << "no item found/deleted." << endl;
    }
}

bool ItemContainer::inContainer(itemType i) {
    Item* temp = head;

    while(temp!= nullptr) //while there are items in the container
    {
        if(temp->getType()== i) //if the item type matches the target
        {
            return true; //return true
        } else {
            temp = temp->getNextItem(); //go to the next item
        }
    }

    return false; //if no match by now, return false
}

void ItemContainer::printItems() {
    Item* temp = head;

    while(temp!= nullptr)
    {
        cout << itemTypeStrings[temp->getType()] << " "; //throw the item into the output buffer
        temp = temp->getNextItem();
    }
}
