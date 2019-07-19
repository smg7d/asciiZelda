/**********************************************************************
Author: Shane
Purpose: declaration of the Dice class
Date: Monday March 12th 2018
***********************************************************************/

#ifndef FINALPROJECT_DICE_H
#define FINALPROJECT_DICE_H


class Dice {
private:
    int sides;

public:
    Dice(); // default sides = 6
    Dice(int s); //primary constructor sets number of sides to s
    ~Dice(); //destructor does nothing

    void setSides(int s); //sets number of sides
    int getSides(); //returns number of sides
    int roll(); //"rolls" the dice, returns random number between 1 and sides

};


#endif //FINALPROJECT_DICE_H
