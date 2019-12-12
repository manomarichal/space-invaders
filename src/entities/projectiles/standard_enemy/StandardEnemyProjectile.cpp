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

void StandardEnemyProjectile::move()
{
    y += vspeed;
    notifyObservers();
}

void StandardEnemyProjectile::update()
{
    move();
}