/** \file PurpleAlien.cpp
* project: space_invaders
* author: Mano Marichal
* date: 04.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#include "PurpleAlien.h"

using namespace objects::enemies::purple_alien;

PurpleAlien::PurpleAlien(float x, float y): Enemy(x, y)
{
    xSize = util::SpaceSettings::width / 20;
    ySize = util::SpaceSettings::height / 15;
    hitpoints = 30;
    maxHp = hitpoints;
}

void PurpleAlien::update()
{
    xSize = util::SpaceSettings::width / 20 * (hitpoints / maxHp);
    ySize = util::SpaceSettings::height / 15 * (hitpoints / maxHp);
    move();
}