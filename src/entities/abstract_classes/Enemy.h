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

namespace entities::enemies
{
    class Enemy
    {
    public:
        int hitpoints;

        virtual void takeDamage()=0;
        virtual ~Enemy()= default;
    };
}
#endif //SPACE_INVADERS_ENEMY_H
