// =====================================================================
// @name: ProjectileController.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 03.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "ProjectileController.h"

using namespace entities::projectiles;

void ProjectileController::update()
{
    for (auto it=activeProjectiles.begin();it!=activeProjectiles.end();it++)
    {
        (*it)->projectile->move();
    }
}

void ProjectileController::draw(sf::RenderWindow &window)
{
    for (const auto &projectile:activeProjectiles)
    {
        projectile->draw(window);
    }
}

void ProjectileController::createProjectile(int x, int y, Type type)
{
    switch (type)
    {
        case standard:
            activeProjectiles.emplace_back(new StandardProjectileView(new StandardProjectile(x, y)));
            break;
        default:
            break;
    }
}
ProjectileController::~ProjectileController()
{
    for (auto &projectile:activeProjectiles) delete projectile;
}