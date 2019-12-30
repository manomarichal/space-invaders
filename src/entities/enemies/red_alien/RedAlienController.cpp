
/** \file RedAlienController.cpp
* project: space_invaders
* author: Mano Marichal
* date: 12.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */
/// description:


#include "RedAlienController.h"
#include "../../shield/Shield.h"

using namespace entities::enemies::red_alien;

bool RedAlienController::handleEvents(const std::vector<std::shared_ptr<Entity>> &entities)
{
    for (const auto& e:entities)
    {
        if (util::Collision::standardProjectile(*entity, e))
            std::dynamic_pointer_cast<Enemy>(entity)->takeDamage(10);
        if (util::Collision::shield(*entity, e)) return false;
    }

    return std::dynamic_pointer_cast<Enemy>(entity)->hitpoints > 0;
}