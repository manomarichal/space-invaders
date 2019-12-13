// =====================================================================
// @name: RedAlien.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 12.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "RedAlien.h"

using namespace entities::enemies::red_alien;

RedAlien::RedAlien(float x, float y): Enemy(x, y)
{
    xSize=64;
    ySize=64;
    hitpoints = 10;
}

void RedAlien::move()
{
    y += vspeed;
    notifyObservers();
}

void RedAlien::takeDamage(unsigned int damage)
{
    hitpoints -= damage;
    notifyObservers();
}

void RedAlien::update()
{
    move();
}