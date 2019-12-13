// =====================================================================
// @name: LevelLoader.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 11.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_LEVELLOADER_H
#define SPACE_INVADERS_LEVELLOADER_H

#include "./Game.h"
#include "../entities/enemies/red_alien/RedAlienController.h"
#include "../entities/enemies/green_alien/GreenAlienController.h"
#include "../entities/enemies/purple_alien/PurpleAlienController.h"

class LevelLoader
{
private:
    LevelLoader()=default;
public:
    static void loadLevel(Game &game, std::string filename);
};


#endif //SPACE_INVADERS_LEVELLOADER_H
