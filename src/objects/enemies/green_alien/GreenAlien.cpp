/** \file GreenAlien.cpp
* project: space_invaders
* author: Mano Marichal
* date: 11.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#include "GreenAlien.h"

using namespace objects::enemies::green_alien;

GreenAlien::GreenAlien(float x, float y): Enemy(x, y)
{
    xSize = util::SpaceSettings::width / 20;
    ySize = util::SpaceSettings::height / 15;
    hitpoints = 10;
}

void GreenAlien::update()
{
    move();
}
