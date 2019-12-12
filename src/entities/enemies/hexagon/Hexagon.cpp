// =====================================================================
// @name: Hexagon.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 04.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "Hexagon.h"
using namespace entities::enemies::hexagon;

Hexagon::Hexagon(float x, float y): Enemy(x, y)
{
    xSize=32;
    ySize=32;
    hitpoints = 20;
    maxHp = hitpoints;
    
    if (rand()%2 == 0) hDir = 1;
    else hDir = -1;

    vDir = 1;
}

void Hexagon::move()
{
    y += vspeed * vDir;
    notifyObservers();
}

void Hexagon::takeDamage(unsigned int damage)
{
    hitpoints -= damage;
    notifyObservers();
}

void Hexagon::update()
{
    xSize = 64 * hitpoints/maxHp;
    ySize = 64*  hitpoints/maxHp;

    move();
    if (getX() - getXSize()/2 < 0) hDir = 1;
    if (getX() + getXSize()/2 > screensize::x) hDir = -1;
}