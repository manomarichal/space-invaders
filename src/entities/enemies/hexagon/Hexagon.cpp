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

Hexagon::Hexagon(int x, int y): Entity(x, y)
{
    xSize=64;
    ySize=64;
    hitpoints = 3;
    maxHp = hitpoints;
    
    if (rand()%2 == 0) dir = 1;
    else dir = -1;
}

void Hexagon::move()
{
    y += vspeed;
    x += hspeed * dir;
    notifyObservers();
}

void Hexagon::takeDamage()
{
    hitpoints -= 1;
    xSize = 64 * hitpoints/maxHp;
    ySize = 64*  hitpoints/maxHp;
    notifyObservers();
}

void Hexagon::update()
{
    move();
    if (getX() - getXSize()/2 < 0) dir = 1;
    if (getX() + getXSize()/2 > screensize::x) dir = -1;
}