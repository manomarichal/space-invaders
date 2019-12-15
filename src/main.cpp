// =====================================================================
// @name: main.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 17.11.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

// FASE 1
//TODO level loops
//TODO make it fancy
//TODO coordinaten systeem omzetten
//TODO zigzag

// FASE 2
//TODO const correctness
//TODO code documenteren
//TODO prog2 code standards
//TODO clion code inspection

//FASE 3
//TODO rapport schrijven

#include "game/Loader.h"
int main()
{
    Game game;
    Loader::loadLevel(game, "../levels/level0.json");
    game.startGame();
    return 0;
}