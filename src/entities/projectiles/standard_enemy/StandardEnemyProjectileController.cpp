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
        if (dynamic_cast<entities::playership::PlayerShip*>(e.get()) != nullptr)
        {
            if (entities::Collision::checkCollision(*entity, *e))
            {
                return false;
            }
        }
    }
    return true;
}