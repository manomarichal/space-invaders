// =====================================================================
// @name: PlayerShip.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 01.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "PlayerShip.h"

using namespace entities::playership;

PlayerShip::PlayerShip(float x, float y)
: Entity(x, y)
{
    xSize = 64;
    ySize = 64;
}

void PlayerShip::moveLeft()
{
    x -= 10;
    if (x < xSize/2) x = xSize/2;
    notifyObservers();
}

void PlayerShip::moveRight()
{
    x += 10;
    if (x + xSize/2> screensize::x) x = screensize::x-xSize/2;
    notifyObservers();
}

void PlayerShip::update()
{
}

void PlayerShip::takeDamage(unsigned int damage)
{
    hitpoints -= damage;
    notifyObservers();
}

