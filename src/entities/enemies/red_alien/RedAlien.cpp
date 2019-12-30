/** \file RedAlien.cpp
* project: space_invaders
* author: Mano Marichal
* date: 12.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */



#include "RedAlien.h"

using namespace entities::enemies::red_alien;

RedAlien::RedAlien(float x, float y): Enemy(x, y)
{
    xSize = util::SpaceSettings::width / 20;
    ySize = util::SpaceSettings::height / 15;
    hitpoints = 10;
}

void RedAlien::update()
{
    move();
}