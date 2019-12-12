// =====================================================================
// @name: main.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 17.11.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

//TODO notify() komt in meerdere dingen voor
//TODO transformatie (singleton pattern)
//TODO level loops
//TODO make it fancy
//TODO const correctness
//TODO optimizen
//TODO code documenteren
//TODO prog2 code standards
//TODO clion code inspection
//TODO rapport schrijven

#include "game/LevelLoader.h"
int main()
{
    Game game;
    LevelLoader::loadLevel(&game, "../levels/level0.json");
    game.startGame();
    return 0;
}