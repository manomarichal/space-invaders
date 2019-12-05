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

void PlayerShip::moveLeft()
{
    if (vx > 0) vx = 0;
    vx -= ax;
    vx *= friction;

    if (vx < -max_v) vx = -max_v;
    notifyObservers();
}

void PlayerShip::moveRight()
{
    if (vx < 0) vx = 0;

    vx *= friction;
    vx += ax;

    if (vx > max_v) vx = max_v;
    notifyObservers();
}

void PlayerShip::move()
{
    vx *= friction;
    x += vx;

    if (x < 0) x = 0;
    if (x + xSize> screensize::x) x = screensize::x-xSize;
}

bool PlayerShip::update()
{
    move();
    return false;
}

PlayerShip::~PlayerShip()=default;
