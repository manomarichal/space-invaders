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
    xSize = screensize::width/20;
    ySize = screensize::height/15;
    hitpoints = 3;
}

void PlayerShip::moveLeft()
{
    x -= screensize::width/120;
    if (x - xSize/2 < screensize::xMin) x = screensize::xMin+xSize/2;
    onNotifyObservers();
}

void PlayerShip::moveRight()
{
    x += screensize::width/120;
    if (x + xSize/2> screensize::xMax) x = screensize::xMax-xSize/2;
    onNotifyObservers();
}

void PlayerShip::update()
{
}

void PlayerShip::takeDamage([[maybe_unused]] float damage)
{
    hitpoints -= 1;
    onNotifyObservers();
}

