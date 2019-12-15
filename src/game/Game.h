// =====================================================================
// @name: Game.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 15.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_GAME_H
#define SPACE_INVADERS_GAME_H

#include "../world/World.h"
#include "../world/Loader.h"

class Game
{
private:
    Game()=default;
public:
    static void playLevels(const std::vector<std::string> &levels);

};


#endif //SPACE_INVADERS_GAME_H
