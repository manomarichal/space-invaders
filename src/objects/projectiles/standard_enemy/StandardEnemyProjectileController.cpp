/** \file StandardEnemyProjectileController.cpp
* project: space_invaders
* author: Mano Marichal
* date: 11.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#include "StandardEnemyProjectileController.h"

using namespace objects::projectiles::standard_enemy;

bool StandardEnemyProjectileController::handleEvents(const std::vector<std::shared_ptr<Entity>> &objects)
{
    for (const auto& e:objects)
    {
        if (util::Collision::playership(*entity, e)) return false;
        if (util::Collision::shield(*entity, e)) return false;
    }

    return entity->getY() > util::SpaceSettings::yMin;
}