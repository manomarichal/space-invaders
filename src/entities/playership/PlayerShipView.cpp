// =====================================================================
// @name: PlayerShipView.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 05.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "PlayerShipView.h"

using namespace entities::playership;

PlayerShipView::PlayerShipView(std::shared_ptr<PlayerShip> ship)
:View("../textures/playershipleft.jpg", ship)
{
    dynamic_cast<Subject*>(entity.get())->subscribe(dynamic_cast<Observer*>(this));
}

void PlayerShipView::notify()
{
    sprite->setPosition(entity->getX(), entity->getY());
}
