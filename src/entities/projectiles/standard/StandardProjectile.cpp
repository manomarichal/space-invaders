// =====================================================================
// @name: StandardProjectile.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 06.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "StandardProjectile.h"
using namespace entities::projectiles::standard;

StandardProjectile::StandardProjectile(float x, float y)
:Entity(x, y)
{
    xSize = SpaceSettings::width / 120;
    ySize = SpaceSettings::height / 90;
    vspeed = SpaceSettings::height / 50;
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