
/** \file StandardProjectileController.cpp
/// project: space_invaders
/// author: Mano Marichal
/// date: 06.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */
/// description:


#include "StandardProjectileController.h"
#include "../../shield/Shield.h"

using namespace entities::projectiles::standard;

//TODO delete projectiles
bool StandardProjectileController::handleEvents(const std::vector<std::shared_ptr<Entity>> &entities)
{
    for (const auto& e:entities)
    {
        if (util::Collision::enemy(*entity, e)) return false;
        if (util::Collision::shield(*entity, e)) return false;
    }
    return entity->getY() < SpaceSettings::yMax;
}