// =====================================================================
// @name: StandardProjectileController.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 02.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "ProjectileController.h"

void projectiles::ProjectileController::update(sf::RenderWindow &window)
{
    for (auto it=activeProjectiles.begin();it!=activeProjectiles.end();it++)
    {
    }
}

void projectiles::ProjectileController::createProjectile(int x, int y, projectiles::type type)
{
    switch (type)
    {
        case projectiles::standard:
            //activeProjectiles.emplace_back(new StandardProjectile(x, y));
            break;
        default:
            break;
    }
}
projectiles::ProjectileController::~ProjectileController()
{
    for (auto &projectile:activeProjectiles) delete projectile;
}