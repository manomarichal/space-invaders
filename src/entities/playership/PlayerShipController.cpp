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
}

void PlayerShipController::update(sf::RenderWindow &window)
{
    view->draw(window);
}

PlayerShipController::~PlayerShipController()
{
    delete view;
}