// =====================================================================
// @name: StandardEnemyProjectileController.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 11.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "StandardEnemyProjectileController.h"
using namespace entities::projectiles::standard_enemy;

bool StandardEnemyProjectileController::handleEvents(const std::vector<std::shared_ptr<Entity>> &entities)
{
    for (auto e:entities)
    {
        if (std::dynamic_pointer_cast<entities::playership::PlayerShip>(e) != nullptr)
        {
            if (util::Collision::checkCollision(*entity, *e))
            {
                return false;
            }
        }
    }

    return true;
}