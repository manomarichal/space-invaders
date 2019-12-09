// =====================================================================
// @name: main.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 17.11.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

//TODO timer
//TODO collisoin
//TODO transformatie
//TODO achievements
//TODO level loops

#include <iostream>
#include "Game/Game.h"
int main()
{
    Game game;
    game.readLevelFromFile("../levels/level0.json");
    game.startGame();
    return 0;
}