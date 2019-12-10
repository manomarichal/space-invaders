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
        else if (dynamic_cast<entities::enemies::Hexagon*>(e.get()) != nullptr and e != entity)
        {
            if (entities::Collision::checkCollision(*entity, *e))
            {
                entity->setDir(entity->getDir()*-1);
            }

        }
    }

    if (entity->getX() - entity->getXSize()/2 < 0) entity->setDir(1);
    if (entity->getX() + entity->getXSize()/2 > screensize::x) entity->setDir(-1);


    entity->move();

    return entity->hitpoints > 0;
}