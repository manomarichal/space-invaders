// =====================================================================
// @name: PlayerShipController.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 05.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "PlayerShipController.h"

using namespace entities::playership;

void PlayerShipController::createProjectile()
{
    projectiles::ProjectileFactory::createProjectile(entity->x+entity->xSize/2, entity->y,projectiles::standard, game);
}
bool PlayerShipController::handleEvents()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        entity ->moveLeft();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        entity ->moveRight();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        createProjectile();
    }

    return entity->hitpoints < 0;
}