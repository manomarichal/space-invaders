// =====================================================================
// @name: PurpleAlienController.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 08.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "PurpleAlienController.h"
using namespace entities::enemies::purple_alien;

PurpleAlienController::PurpleAlienController(const std::shared_ptr<Entity> &entity, const std::shared_ptr<View> &view,
                                             World &world) :Controller(world, entity, view)
{}

bool PurpleAlienController::handleEvents(const std::vector<std::shared_ptr<Entity>> &entities)
{
    for (const auto& e:entities)
    {
        if (std::dynamic_pointer_cast<entities::projectiles::standard::StandardProjectile>(e) != nullptr)
        {
            if (util::Collision::checkCollision(*entity, *e))
            {
                std::dynamic_pointer_cast<Enemy>(entity)->takeDamage(10);
            }
        }
    }

    return std::dynamic_pointer_cast<Enemy>(entity)->hitpoints > 0;
}