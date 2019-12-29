// =====================================================================
// @name: main.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 17.11.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================


//TODO exception handling
//TODO code documenteren
//TODO levels
//TODO code laaste keer nakijken & inspection
//TODO rapport
//TODO make it fancy

#include "game/Game.h"

int main()
{
    Game("../resources/settings/standard_setting.json").play();
    return 0;
}
