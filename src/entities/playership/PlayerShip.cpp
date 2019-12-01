// =====================================================================
// @name: PlayerShip.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 01.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "PlayerShip.h"

void PlayerShip::moveLeft()
{
    x -= hspeed;
}

void PlayerShip::moveRight()
{
    x += hspeed;
}

double PlayerShip::getHspeed() const
{
    return hspeed;
}

void PlayerShip::setHspeed(double hspeed)
{
    PlayerShip::hspeed = hspeed;
}

double PlayerShip::getVspeed() const
{
    return vspeed;
}

void PlayerShip::setVspeed(double vspeed)
{
    PlayerShip::vspeed = vspeed;
}

double PlayerShip::getX() const
{
    return x;
}

void PlayerShip::setX(double x)
{
    PlayerShip::x = x;
}

double PlayerShip::getY() const
{
    return y;
}

void PlayerShip::setY(double y)
{
    PlayerShip::y = y;
}

