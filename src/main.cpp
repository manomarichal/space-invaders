// =====================================================================
// @name: main.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 17.11.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

//TODO transformatie (singleton pattern)
//TODO achievements (observer pattern)
//TODO level loops
//TODO make it fancy
//TODO const correctness
//TODO optimizen
//TODO code documenteren
//TODO prog2 code standards
//TODO clion code inspection
//TODO rapport schrijven


#include <iostream>
#include "Game/Game.h"
int main()
{
    Game game;
    game.readLevelFromFile("../levels/single_enemy.json");
    game.startGame();
    return 0;
}