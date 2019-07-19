

#include <iostream>
#include "Game.h"
#include <vector>
#include "Board.h"

using std::vector;

using std::cout;
using std::cin;
using std::endl;

/**********************************************************************
TO DO LIST
 -check memory leaks
***********************************************************************/

int main() {

    srand(time(NULL));
    Game mainGame;

    mainGame.runGame();

    return 0;
}