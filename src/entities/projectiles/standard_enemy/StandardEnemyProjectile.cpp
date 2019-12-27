// =====================================================================
// @name: StandardEnemyProjectile.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 11.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "StandardEnemyProjectile.h"
using namespace entities::projectiles::standard_enemy;

StandardEnemyProjectile::StandardEnemyProjectile(float x, float y)
:Entity(x, y)
{
    xSize = screensize::width/120;
    ySize = screensize::height/90;
    vspeed = screensize::height/50;
}

void StandardEnemyProjectile::move()
{
    y -= vspeed;
    onNotifyObservers();
}

void StandardEnemyProjectile::update()
{
    move();
}