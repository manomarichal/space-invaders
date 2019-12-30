// =====================================================================
// name: main.cpp
// project: space_invaders
// author: Mano Marichal
// date: 17.11.19
// copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// description:
// =====================================================================

//TODO exception handling
//TODO levels
//TODO rapport
//TODO readme


// extra
/*
 * make it fancy
 * extra // comments overal
 * main page doxygen
 * sleep(1) in gameover
 * file descriptions
 */

#include "game/Game.h"

int main()
{
    Game("../resources/settings/standard_setting.json").play();
    return 0;
}
