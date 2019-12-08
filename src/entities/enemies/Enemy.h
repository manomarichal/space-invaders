// =====================================================================
// @name: Enemy.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 04.12.19
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
    private:
        unsigned int hitpoints;
    public:
        bool isHit();
    };
}
#endif //SPACE_INVADERS_ENEMY_H
