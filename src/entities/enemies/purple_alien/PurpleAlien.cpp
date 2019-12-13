// =====================================================================
// @name: PurpleAlien.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 04.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "PurpleAlien.h"
using namespace entities::enemies::purple_alien;

PurpleAlien::PurpleAlien(float x, float y): Enemy(x, y)
{
    xSize=64;
    ySize=64;
    hitpoints = 30;
    maxHp = hitpoints;
}

void PurpleAlien::move()
{
    y += vspeed;
    notifyObservers();
}

void PurpleAlien::takeDamage(unsigned int damage)
{
    hitpoints -= damage;
    notifyObservers();
}

void PurpleAlien::update()
{
    xSize = 64 * hitpoints/maxHp;
    ySize = 64*  hitpoints/maxHp;
    move();
}