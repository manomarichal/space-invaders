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

void PlayerShipView::notify()
{
    sprite->setPosition(entity->getX(), entity->getY());
}
