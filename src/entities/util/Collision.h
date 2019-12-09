// =====================================================================
// @name: Collision.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 09.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_COLLISION_H
#define SPACE_INVADERS_COLLISION_H

#include "../abstract_classes/Entity.h"

namespace entities
{
    class Collision
    {
    private:
        Collision()= default;
    public:
        static bool checkCollision(const Entity &e1, const Entity &e2)
        {
            return e1.getX() + e1.getXSize()/2 >= e2.getX() - e2.getXSize()/2 &&
                   e1.getX() - e1.getXSize()/2 <= e2.getX() + e2.getXSize()/2 &&
                   e1.getY() + e1.getYSize()/2 >= e2.getY() - e2.getYSize()/2 &&
                   e1.getY() - e1.getYSize()/2 <= e2.getY() + e2.getYSize()/2;
        }
    };
}
#endif //SPACE_INVADERS_COLLISION_H
