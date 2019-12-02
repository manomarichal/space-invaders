// =====================================================================
// @name: main.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 17.11.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include <iostream>
#include "./Game.h"
int main()
{
    Game game;
    game.initializeGame();
    game.startGame();
    return 0;
}