// =====================================================================
// @name: Game.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 15.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "Game.h"

void Game::playLevels(const std::vector<std::string> &levels)
{
    World world("../settings/standard_setting.json");
    for (const auto &level:levels)
    {
        Loader::loadLevel(world, level);
        world.start();
        world.reset();
    }
}