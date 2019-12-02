// =====================================================================
// @name: PlayerShip.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 01.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "PlayerShip.h"
#include "../../settings/screensize.h"

PlayerShip::PlayerShip()
{
    x = screensize::x/2;
    y = screensize::y-(screensize::y/10);
}
void PlayerShip::moveLeft()
{
    if (vx > 0) vx = 0;
    vx -= ax;
    vx *= friction;

    if (vx < -max_v) vx = -max_v;
}

void PlayerShip::moveRight()
{
    if (vx < 0) vx = 0;

    vx *= friction;
    vx += ax;

    if (vx > max_v) vx = max_v;
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

void PlayerShip::move()
{
    vx *= friction;
    x += vx;

    if (x < 0) x = 0;
    if (x + xSize> screensize::x) x = screensize::x-xSize;

}

void PlayerShip::setXSize(unsigned int xSize)
{
    PlayerShip::xSize = xSize;
}

void PlayerShip::setYSize(int ySize)
{
    PlayerShip::ySize = ySize;
}
