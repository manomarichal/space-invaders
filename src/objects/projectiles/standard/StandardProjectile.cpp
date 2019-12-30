/** \file StandardProjectile.cpp
* project: space_invaders
* author: Mano Marichal
* date: 06.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#include "StandardProjectile.h"

using namespace objects::projectiles::standard;

StandardProjectile::StandardProjectile(float x, float y)
:Entity(x, y)
{
    xSize = util::SpaceSettings::width / 120;
    ySize = util::SpaceSettings::height / 90;
    vspeed = util::SpaceSettings::height / 50;
}

void StandardProjectile::move()
{
    y += vspeed;
    onNotifyObservers();
}

void StandardProjectile::update()
{
    move();
}