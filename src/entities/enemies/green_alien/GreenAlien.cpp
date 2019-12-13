// =====================================================================
// @name: GreenAlien.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 11.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "GreenAlien.h"

using namespace entities::enemies::green_alien;

GreenAlien::GreenAlien(float x, float y): Enemy(x, y)
{
    xSize=64;
    ySize=64;
    hitpoints = 10;
    maxHp = hitpoints;
}

void GreenAlien::move()
{
    y += vspeed;
    notifyObservers();
}

void GreenAlien::takeDamage(unsigned int damage)
{
    hitpoints -= damage;
    notifyObservers();
}

void GreenAlien::update()
{
    move();
}