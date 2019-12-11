// =====================================================================
// @name: Pentagon.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 11.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "Pentagon.h"

using namespace entities::enemies::pentagon;

Pentagon::Pentagon(float x, float y): Enemy(x, y)
{
    xSize=128;
    ySize=128;
    hitpoints = 200;
    maxHp = hitpoints;
}

void Pentagon::move()
{
    y += vspeed;
    notifyObservers();
}

void Pentagon::takeDamage(unsigned int damage)
{
    hitpoints -= damage;
    notifyObservers();
}

void Pentagon::update()
{
    xSize = 128 * hitpoints/maxHp;
    ySize = 128 *  hitpoints/maxHp;

    move();
    if (getX() - getXSize()/2 < 0) dir = 1;
    if (getX() + getXSize()/2 > screensize::x) dir = -1;
}
