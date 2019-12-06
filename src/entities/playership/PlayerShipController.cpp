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
    projectiles::ProjectileFactory::createProjectile(object->x+object->xSize/2, object->y,projectiles::standard, game);
}
void PlayerShipController::handleEvents()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        object ->moveLeft();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        object ->moveRight();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        createProjectile();
    }
}