// =====================================================================
// @name: GreenAlienController.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 11.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "GreenAlienController.h"

using namespace entities::enemies::green_alien;

GreenAlienController::GreenAlienController(const std::shared_ptr<Entity> &entity, const std::shared_ptr<View> &view, World &world)
        :Controller(world, entity, view)
{
    stopwatch = std::make_unique<Stopwatch>(2000);
}
bool GreenAlienController::handleEvents(const std::vector<std::shared_ptr<Entity>> &entities)
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

    if (stopwatch->isReady())
    {
        projectiles::ProjectileFactory::createProjectile(entity->getX(), entity->getY(), projectiles::EnemyStandard, world);
    }

    return std::dynamic_pointer_cast<Enemy>(entity)->hitpoints > 0;
}