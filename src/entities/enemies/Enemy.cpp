// =====================================================================
// @name: Enemy.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 16.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "Enemy.h"

using namespace entities::enemies;
Enemy::Enemy(float x, float y): Entity(x, y) {}

void Enemy::takeDamage(unsigned int damage) {hitpoints -= damage;}

void Enemy::move()
{
    count++;
    if (vertical)
    {
        y += speed;
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
    if (!vertical) x += speed * float(dir);
    onNotifyObservers();
}