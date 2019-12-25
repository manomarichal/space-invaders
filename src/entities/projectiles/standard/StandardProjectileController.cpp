// =====================================================================
// @name: StandardProjectileController.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 06.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "StandardProjectileController.h"

using namespace entities::projectiles::standard;

//TODO delete projectiles
bool StandardProjectileController::handleEvents(const std::vector<std::shared_ptr<Entity>> &entities)
{
    for (auto e:entities)
    {
        if (std::dynamic_pointer_cast<entities::enemies::Enemy>(e) != nullptr)
        {
            if (util::Collision::checkCollision(*entity, *e))
            {
                return false;
            }
        }
    }
    return entity->getY() < screensize::yMax;
}