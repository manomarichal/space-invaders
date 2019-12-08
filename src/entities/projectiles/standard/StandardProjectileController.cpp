// =====================================================================
// @name: StandardProjectileController.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 06.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "StandardProjectileController.h"

using namespace entities::projectiles;

//TODO delete projectiles
bool StandardProjectileController::handleEvents()
{
    return entity->getY() > 0;
}