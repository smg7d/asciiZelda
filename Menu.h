/**********************************************************************
Author: Shane
Purpose: declaration of the menu class
Date: Friday January 26th 2018
Pass an integer for the number of options to be displayed, and a pointer
to an array of strings for the menu options, to define the object. then
use obj.getChoice() to get the integer that corresponds to the user's
choice
***********************************************************************/

#ifndef FINALPROJECT_MENU_H
#define FINALPROJECT_MENU_H

#include <string>

using std::string;

class Menu
{
private:
    int numOptions;
    string* arrPtr;

public:
    Menu(int n, string* a); // constructor initializes member variables
    ~Menu(); //destructor. deallocate memory here

    //function prototypes
    int getChoice(); //returns user choice as an integer

};

#endif