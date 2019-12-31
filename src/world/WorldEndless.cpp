// =====================================================================
// @name: WorldEndless.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 31.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "./World.h"
#include "../objects/enemies/green_alien/GreenAlienController.h"
#include "../objects/enemies/purple_alien/PurpleAlienController.h"
#include "../objects/enemies/red_alien/RedAlienController.h"
#include "../objects/shield/ShieldController.h"
#include "../objects/shield/ShieldView.h"
#include "../objects/shield/Shield.h"

void World::enterEndless()
{
    reset();
    float x = util::SpaceSettings::width/float(rand()%15);
    int type = rand()%3;
    std::string eType;
    running = true;
}