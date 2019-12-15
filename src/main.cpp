// =====================================================================
// @name: main.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 17.11.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

// FASE 1
//TODO coordinaten systeem omzetten
//TODO make it fancy
//TODO zigzag

// FASE 2
//TODO const correctness
//TODO code documenteren
//TODO prog2 code standards
//TODO clion code inspection

//FASE 3
//TODO rapport schrijven

#include "game/Game.h"

int main()
{
    Game::playLevels({"../levels/level0.json", "../levels/level1.json"});
    return 0;
}