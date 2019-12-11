// =====================================================================
// @name: Hexagon.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 04.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "Hexagon.h"
using namespace entities::enemies;

Hexagon::Hexagon(int x, int y): Entity(x, y, hexagon)
{
    xSize=64;
    ySize=64;
    if (rand()%2 == 0) dir = 1;
    else dir = -1;
}
void Hexagon::setDir(int dir)
{
    this->dir = dir;
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
    notifyObservers();
}

int Hexagon::getDir() const
{
    return dir;
}
