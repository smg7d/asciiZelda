/***************************************************
Author: Shane
Purpose: the implementation file of the Menu class
Date: Friday January 26th 2018
***************************************************/

#include "Menu.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

/*********************************************
Menu::Menu
the default constructor for the menu class
**********************************************/
Menu::Menu(int n, string* a)
{
    numOptions = n;
    arrPtr = a;
}

/*********************************************
Menu::~Menu
the destructor for the menu class
**********************************************/
Menu::~Menu()
{

}

/*********************************************
Menu::getChoice
method to get the user choice of the menu
**********************************************/
int Menu::getChoice()
{
    int choice;
    double cinChoice;

    //display the menu
    for(int i = 0; i < numOptions; i++)
    {
        cout << i + 1 << ". " << arrPtr[i] << endl;
    }

    //get the choice, check to see if it is within bounds and of integer type
    cin >> cinChoice;

    while((cinChoice < 1 || cinChoice > numOptions) || (cin.fail() || cinChoice!= static_cast<int>(cinChoice))) //if not
    {
        //reset input buffer
        cin.clear();
        cin.ignore(100, '\n');

        //reprompt for input
        cout << "Invalid choice. Enter a positive integer corresponding to your choice on the menu." << endl;
        cin >> cinChoice;
    }

    //reset and flush the input stream
    cin.clear();
    cin.ignore(100, '\n');

    //cast and return the choice
    choice = static_cast<int>(cinChoice);
    return choice;
}