// =====================================================================
// @name: main.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 17.11.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

//TODO exceptions
//TODO singletons
//TODO observer
//TODO damage systeem projectiles

// FASE 2
//TODO const correctness
//TODO code documenteren
//TODO prog2 code standards
//TODO clion code inspection

//FASE 3
//TODO make it fancy
//TODO rapport schrijven

#include "game/Game.h"

int main()
{
    Game("../resources/settings/standard_setting.json").play();
    return 0;
}
