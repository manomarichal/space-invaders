// =====================================================================
// @name: Enemy.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 11.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_ENEMY_H
#define SPACE_INVADERS_ENEMY_H

#include "./Entity.h"

namespace entities::enemies
{
    class Enemy: public Entity
    {
    public:
        Enemy(float x, float y):Entity(x, y) {};

        int hitpoints;
        virtual void takeDamage(unsigned int damage)=0;
        virtual ~Enemy()= default;
    };
}
#endif //SPACE_INVADERS_ENEMY_H
