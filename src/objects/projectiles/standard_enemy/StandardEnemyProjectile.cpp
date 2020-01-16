/** \file StandardEnemyProjectile.cpp
 * project: space_invaders
 * author: Mano Marichal
 * date: 11.12.19
 * copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#include "StandardEnemyProjectile.h"

using namespace objects::projectiles::standard_enemy;

StandardEnemyProjectile::StandardEnemyProjectile(float x, float y) : Entity(x, y)
{
        xSize = util::SpaceSettings::width / 120;
        ySize = util::SpaceSettings::height / 90;
        vspeed = util::SpaceSettings::height / 60;
}

void StandardEnemyProjectile::move()
{
        y -= vspeed;
        notify();
}

void StandardEnemyProjectile::update() { move(); }