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

PlayerShipController::PlayerShipController(const std::shared_ptr<Entity> &entity, const std::shared_ptr<View> &view,
                                           World &world) :Controller(world, entity, view)
{
    stopwatch = std::make_unique<Stopwatch>(500);
}

void PlayerShipController::createProjectile()
{
    projectiles::ProjectileFactory::createProjectile(std::dynamic_pointer_cast<PlayerShip>(entity)->getX(), std::dynamic_pointer_cast<PlayerShip>(entity)->getY(),projectiles::Standard, world);
}

bool PlayerShipController::handleEvents([[maybe_unused]] const std::vector<std::shared_ptr<Entity>> &entities)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        std::dynamic_pointer_cast<PlayerShip>(entity)-> moveLeft();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        std::dynamic_pointer_cast<PlayerShip>(entity)->moveRight();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and stopwatch->isReady())
    {
        createProjectile();
    }

    for (const auto& e:entities)
    {
        if (std::dynamic_pointer_cast<projectiles::standard_enemy::StandardEnemyProjectile>(e) != nullptr)
        {
            if (util::Collision::checkCollision(*entity, *e))
            {
                std::dynamic_pointer_cast<PlayerShip>(entity)->takeDamage(10);
            }
        }
    }
    return std::dynamic_pointer_cast<PlayerShip>(entity)->hitpoints >= 0;
}