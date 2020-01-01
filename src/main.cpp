// =====================================================================
// name: main.cpp
// project: space_invaders
// author: Mano Marichal
// date: 17.11.19
// copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// description:
// =====================================================================

//TODO exception handling
//TODO rapport
//TODO readme


// extra
/*
 * singletons deftig doen
 * endless + factory class voor enemies
 * game static maken
 * muziek
 * make it fancy
 * extra // comments overal
 * main page doxygen
 * sleep(1) in gameover
 * file descriptions
 * shields size kunnen customizen
 */

#include "game/Game.h"

int main()
{
    //Game("../resources/settings/different_coordinates.json").play();
    Game("../resources/settings/standard_setting.json").play();
    return 0;
}
