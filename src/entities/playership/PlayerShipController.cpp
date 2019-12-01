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
    object->setHspeed(5);
    object->setVspeed(5);
    object->setX(300);
    object->setY(900);
}

void PlayerShipController::update(sf::RenderWindow &window)
{
    object->moveLeft();
    view->draw(window);
}

PlayerShipController::~PlayerShipController()
{
    delete view;
}