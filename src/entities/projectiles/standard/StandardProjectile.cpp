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
    xSize = screensize::width/120;
    ySize = screensize::height/90;
    vspeed = screensize::height/50;
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