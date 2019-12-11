// =====================================================================
// @name: StandardProjectileController.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 06.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "StandardProjectileController.h"
#include "../../enemies/hexagon/Hexagon.h"

using namespace entities::projectiles::standard;

//TODO delete projectiles
bool StandardProjectileController::handleEvents(const std::vector<std::shared_ptr<Entity>> &entities)
{
    for (auto e:entities)
    {
        if (dynamic_cast<entities::enemies::hexagon::Hexagon*>(e.get()) != nullptr)
        {
            if (entities::Collision::checkCollision(*entity, *e))
            {
                std::cout << "hit" << std::endl;
                return false;
            }
        }
    }
    return entity->getY() > 0;
}