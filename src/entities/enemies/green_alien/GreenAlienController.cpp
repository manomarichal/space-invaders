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

GreenAlienController::GreenAlienController(std::shared_ptr<GreenAlien> entity, std::shared_ptr<GreenAlienView> view, Game &game)
        :Controller(game), entity(std::move(entity)), view(std::move(view))
{
    stopwatch = std::make_unique<Stopwatch>(2000);
}
bool GreenAlienController::handleEvents(const std::vector<std::shared_ptr<Entity>> &entities)
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
    }

    if (stopwatch->isReady())
    {
        projectiles::ProjectileFactory::createProjectile(entity->getX(), entity->getY(), projectiles::EnemyStandard, game);
    }

    return entity->hitpoints > 0;
}