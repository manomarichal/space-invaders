// =====================================================================
// @name: PlayerShipController.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 05.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "PlayerShipController.h"
using namespace entities;

void PlayerShipController::createProjectile()
{
    projectiles::ProjectileFactory::createProjectile(entity->getX(), entity->getY(),projectiles::standard, game);
}
bool PlayerShipController::handleEvents(const std::vector<std::shared_ptr<Entity>> &entities)
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

    entity->move();
    return entity->hitpoints > 0;
}