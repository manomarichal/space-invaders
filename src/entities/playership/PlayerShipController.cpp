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
    view = new PlayerShipView();
    object = view->getObject();
}

void PlayerShipController::handleEvent(const sf::Event &event)
{
}

void PlayerShipController::update(sf::RenderWindow &window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) object->moveLeft();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) object->moveRight();
    object->move();
    view->draw(window);
}

PlayerShipController::~PlayerShipController()
{
    delete view;
}