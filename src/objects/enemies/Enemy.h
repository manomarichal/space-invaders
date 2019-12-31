/** \file Enemy.h
* project: space_invaders
* author: Mano Marichal
* date: 11.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#ifndef SPACE_INVADERS_ENEMY_H
#define SPACE_INVADERS_ENEMY_H

#include "../abstract_classes/Entity.h"

namespace objects::enemies
{
    class Enemy: public Entity
    {
    protected:
        const float vspeed;
        const float hspeed;
        float dir;
        int count;
        bool vertical;
    public:
        float hitpoints;

        Enemy(float x, float y);
        virtual void move();
        virtual void takeDamage(float damage);
        ~Enemy() override = default;
    };
}
#endif //SPACE_INVADERS_ENEMY_H
