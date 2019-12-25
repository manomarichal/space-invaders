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
    xSize = screensize::width/20;
    ySize = screensize::height/15;
    hitpoints = 10;
}

void GreenAlien::update()
{
    move();
}
