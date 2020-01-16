/** \file GreenAlienController.cpp
 * project: space_invaders
 * author: Mano Marichal
 * date: 11.12.19 */

#include "GreenAlienController.h"
#include "../../projectiles/ProjectileFactory.h"

using namespace objects::enemies::green_alien;

GreenAlienController::GreenAlienController(const std::shared_ptr<Entity>& entity, const std::shared_ptr<View>& view,
                                           World& world)
    : Controller(world, entity, view)
{
        stopwatch = std::make_unique<util::Stopwatch>(1000);
}
bool GreenAlienController::handleEvents(const std::vector<std::shared_ptr<Entity>>& objects)
{
        for (const auto& e : objects) {
                if (util::Collision::standardProjectile(*entity, e))
                        std::dynamic_pointer_cast<Enemy>(entity)->takeDamage(10);
                if (util::Collision::shield(*entity, e) or util::Collision::playership(*entity, e))
                        return false;
        }

        if (stopwatch->isReady()) {
                projectiles::ProjectileFactory::createProjectile(entity->getX(), entity->getY(),
                                                                 projectiles::ProjectileFactory::EnemyStandard, world);
        }

        return std::dynamic_pointer_cast<Enemy>(entity)->hitpoints > 0;
}