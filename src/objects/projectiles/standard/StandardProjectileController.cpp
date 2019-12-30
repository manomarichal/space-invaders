/** \file StandardProjectileController.cpp
* project: space_invaders
* author: Mano Marichal
* date: 06.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#include "StandardProjectileController.h"

using namespace objects::projectiles::standard;

//TODO delete projectiles
bool StandardProjectileController::handleEvents(const std::vector<std::shared_ptr<Entity>> &objects)
{
    for (const auto& e:objects)
    {
        if (util::Collision::enemy(*entity, e)) return false;
        if (util::Collision::shield(*entity, e)) return false;
    }
    return entity->getY() < util::SpaceSettings::yMax;
}