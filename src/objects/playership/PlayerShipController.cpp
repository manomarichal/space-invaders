/** \file PlayerShipController.cpp
 * project: space_invaders
 * author: Mano Marichal
 * date: 05.12.19
 * copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#include "PlayerShipController.h"

using namespace objects::playership;

PlayerShipController::PlayerShipController(const std::shared_ptr<Entity>& entity, const std::shared_ptr<View>& view,
                                           World& world)
    : Controller(world, entity, view)
{
        stopwatch = std::make_unique<util::Stopwatch>(300);
}

void PlayerShipController::createProjectile()
{
        projectiles::ProjectileFactory::createProjectile(std::dynamic_pointer_cast<PlayerShip>(entity)->getX(),
                                                         std::dynamic_pointer_cast<PlayerShip>(entity)->getY(),
                                                         projectiles::ProjectileFactory::Standard, world);
}

bool PlayerShipController::handleEvents([[maybe_unused]] const std::vector<std::shared_ptr<Entity>>& objects)
{
        // check for keyboard input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                std::dynamic_pointer_cast<PlayerShip>(entity)->moveLeft();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                std::dynamic_pointer_cast<PlayerShip>(entity)->moveRight();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and stopwatch->isReady()) {
                createProjectile();
        }

        // check for collision
        for (const auto& e : objects) {
                if (util::Collision::standardEnemyProjectile(*entity, e) or util::Collision::enemy(*entity, e))
                        std::dynamic_pointer_cast<PlayerShip>(entity)->takeDamage(1);
        }

        return std::dynamic_pointer_cast<PlayerShip>(entity)->hitpoints >= 0;
}