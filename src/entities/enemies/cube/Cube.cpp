// =====================================================================
// @name: Cube.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 12.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "Cube.h"

using namespace entities::enemies::cube;

Cube::Cube(float x, float y): Enemy(x, y)
{
    xSize=32;
    ySize=32;
    hitpoints = 10;
}

void Cube::move()
{
    y += vspeed;
    notifyObservers();
}

void Cube::takeDamage(unsigned int damage)
{
    hitpoints -= damage;
    notifyObservers();
}

void Cube::update()
{
    move();
}