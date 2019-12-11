// =====================================================================
// @name: PentagonController.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 11.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "PentagonController.h"
using namespace entities::enemies::pentagon;

bool PentagonController::handleEvents(const std::vector<std::shared_ptr<Entity>> &entities)
{
    for (auto e:entities)
    {
        if (dynamic_cast<entities::projectiles::standard::StandardProjectile*>(e.get()) != nullptr)
        {
            if (entities::Collision::checkCollision(*entity, *e))
            {
                entity->takeDamage(10);
            }
        }
        else if (dynamic_cast<entities::enemies::Enemy*>(e.get()) != nullptr and e != entity)
        {
            if (entities::Collision::checkCollision(*entity, *e))
            {
                entity->dir = entity->dir * -1;
            }
        }
    }

    return entity->hitpoints > 0;
}