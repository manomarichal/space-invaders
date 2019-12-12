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

entities::Object ProjectileFactory::createStandardProjectile(int x, int y, Game* game)
{
    auto projectile = std::make_shared<standard::StandardProjectile>(x, y);
    auto view = std::make_shared<standard::StandardProjectileView>(projectile);
    auto controller = std::make_shared<standard::StandardProjectileController>(projectile, view, game);

    return std::make_tuple(std::move(projectile), std::move(view), std::move(controller));
}

entities::Object ProjectileFactory::createStandardEnemyProjectile(int x, int y, Game* game)
{
    auto projectile = std::make_shared<standard_enemy::StandardEnemyProjectile>(x, y);
    auto view = std::make_shared<standard_enemy::StandardEnemyProjectileView>(projectile);
    auto controller = std::make_shared<standard_enemy::StandardEnemyProjectileController>(projectile, view, game);

    return std::make_tuple(std::move(projectile), std::move(view), std::move(controller));
}

void ProjectileFactory::createProjectile(int x, int y, entities::projectiles::Type type, Game* game)
{
    Object object;

    switch(type)
    {
        case Standard:
            object = ProjectileFactory::createStandardProjectile(x, y, game);
            break;
        case Fast:
            break;
        case EnemyStandard:
            object = ProjectileFactory::createStandardEnemyProjectile(x, y, game);
            break;
        default:
            break;
    }

    game->addObject(std::move(object));
}