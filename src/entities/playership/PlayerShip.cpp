// =====================================================================
// @name: PlayerShip.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 01.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "PlayerShip.h"

double PlayerShip::getHspeed() const
{
    return hspeed;
}

double PlayerShip::getVspeed() const
{
    return vspeed;
}

void PlayerShip::moveLeft()
{
    x -= hspeed;
}

void PlayerShip::moveRight()
{
    x += hspeed;
}

double PlayerShip::getX() const
{
    return x;
}

double PlayerShip::getY() const
{
    return y;
}
