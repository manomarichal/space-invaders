// =====================================================================
// @name: PlayerShipController.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 01.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "./PlayerShipController.h"
PlayerShipController::PlayerShipController()
{
    // create the object and it's view
    view = new PlayerShipView();
    object = new PlayerShip;

    view->object = object;
    projectileController = new projectiles::ProjectileController;
}

void PlayerShipController::handleEvent(const sf::Event &event)
{
}

void PlayerShipController::update(sf::RenderWindow &window)
{
    // move the player object
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) object->moveLeft();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) object->moveRight();
    object->move();

    // check if we are shooting and update all active projectiles
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        projectileController->createProjectile(object->x, object->y, projectiles::standard);
    projectileController->update(window);

    // draw the player object
    view->draw(window);
}

PlayerShipController::~PlayerShipController()
{
    delete object;
    view->object = nullptr;
    delete view;
    delete projectileController;
}