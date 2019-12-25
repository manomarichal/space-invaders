// =====================================================================
// @name: ProjectileFactory.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 06.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "ProjectileFactory.h"

using namespace entities::projectiles;

entities::Object ProjectileFactory::createStandardProjectile(float x, float y, World &world)
{
    auto projectile = std::make_shared<standard::StandardProjectile>(x, y);
    auto view = std::make_shared<standard::StandardProjectileView>(projectile);
    view->init();
    auto controller = std::make_shared<standard::StandardProjectileController>(projectile, view, world);

    return std::make_tuple(std::move(projectile), std::move(view), std::move(controller));
}

entities::Object ProjectileFactory::createStandardEnemyProjectile(float x, float y, World &world)
{
    auto projectile = std::make_shared<standard_enemy::StandardEnemyProjectile>(x, y);
    auto view = std::make_shared<standard_enemy::StandardEnemyProjectileView>(projectile);
    view->init();
    auto controller = std::make_shared<standard_enemy::StandardEnemyProjectileController>(projectile, view, world);

    return std::make_tuple(std::move(projectile), std::move(view), std::move(controller));
}

void ProjectileFactory::createProjectile(float x, float y, entities::projectiles::Type type, World &world)
{
    Object object;

    switch(type)
    {
        case Standard:
            object = ProjectileFactory::createStandardProjectile(x, y, world);
            break;
        case Fast:
            break;
        case EnemyStandard:
            object = ProjectileFactory::createStandardEnemyProjectile(x, y, world);
            break;
        default:
            break;
    }

    world.addObject(std::move(object));
}