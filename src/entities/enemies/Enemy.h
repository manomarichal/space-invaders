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

#include "../abstract_classes/Entity.h"

namespace entities::enemies
{
    class Enemy: public Entity
    {
    protected:
        const float speed;
        int dir;
        int count;
        bool vertical;
    public:
        int hitpoints;

        Enemy(float x, float y);
        virtual void move();
        virtual void takeDamage(float damage);
        virtual ~Enemy()= default;
    };
}
#endif //SPACE_INVADERS_ENEMY_H
