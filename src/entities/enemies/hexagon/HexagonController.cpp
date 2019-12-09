// =====================================================================
// @name: HexagonController.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 08.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "HexagonController.h"
using namespace entities::enemies;

bool HexagonController::handleEvents(const std::vector<std::shared_ptr<Entity>> &entities)
{
    entity->move();
    // check collision
    for (auto e:entities)
    {
        if (dynamic_cast<entities::projectiles::StandardProjectile*>(e.get()) != nullptr)
        {
            if (entities::Collision::checkCollision(*entity, *e))
            {
                entity->hitpoints -= 1;
            }

        }
    }
    return entity->hitpoints > 0;
}