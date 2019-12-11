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

void StandardProjectile::move()
{
    y -= vspeed;
    notifyObservers();
}

void StandardProjectile::update()
{
    move();
}