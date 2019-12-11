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
PlayerShipController::PlayerShipController(std::shared_ptr<PlayerShip> entity, std::shared_ptr<PlayerShipView> view, Game *game)
                                            :Controller(game), entity(std::move(entity)), view(std::move(view))
{
    stopwatch = std::make_unique<Stopwatch>(200);
}

void PlayerShipController::createProjectile()
{
    projectiles::ProjectileFactory::createProjectile(entity->getX(), entity->getY(),projectiles::Standard, game);
}

bool PlayerShipController::handleEvents([[maybe_unused]] const std::vector<std::shared_ptr<Entity>> &entities)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        entity ->moveLeft();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        entity ->moveRight();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and stopwatch->isReady())
    {
        createProjectile();
    }

    return entity->hitpoints > 0;
}