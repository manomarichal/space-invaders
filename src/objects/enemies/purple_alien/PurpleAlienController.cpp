/** \file PurpleAlienController.cpp
* project: space_invaders
* author: Mano Marichal
* date: 08.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#include "PurpleAlienController.h"

using namespace objects::enemies::purple_alien;

PurpleAlienController::PurpleAlienController(const std::shared_ptr<Entity> &entity, const std::shared_ptr<View> &view,
                                             World &world) :Controller(world, entity, view)
{}

bool PurpleAlienController::handleEvents(const std::vector<std::shared_ptr<Entity>> &objects)
{
    for (const auto& e:objects)
    {
        if (util::Collision::standardProjectile(*entity, e))
            std::dynamic_pointer_cast<Enemy>(entity)->takeDamage(10);
        if (util::Collision::shield(*entity, e) or util::Collision::playership(*entity, e)) return false;
    }

    return std::dynamic_pointer_cast<Enemy>(entity)->hitpoints > 0;
}