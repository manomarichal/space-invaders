
/** \file Enemy.cpp
/// project: space_invaders
/// author: Mano Marichal
/// date: 16.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */
/// description:


#include "Enemy.h"

using namespace entities::enemies;
Enemy::Enemy(float x, float y):
        Entity(x, y), vspeed(SpaceSettings::height / 1000), hspeed(SpaceSettings::width / 1000), dir(1), count(100), vertical(false), hitpoints(10) {}

void Enemy::takeDamage(float damage) {hitpoints -= damage;}

void Enemy::move()
{
    count++;
    if (vertical)
    {
        y -= vspeed;
        count++;
        if (count == 50)
        {
            count = 0;
            vertical = false;
        }
    }
    else if (count == 200)
    {
        dir *= -1;
        count = 0;
        vertical = true;
    }
    if (!vertical) x += hspeed * dir;
    onNotifyObservers();
}