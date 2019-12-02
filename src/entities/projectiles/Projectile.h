// =====================================================================
// @name: Projectile.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 02.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_PROJECTILE_H
#define SPACE_INVADERS_PROJECTILE_H

#include "../Entity.h"
namespace projectiles
{
    class Projectile: public Entity
    {
    protected:
        int x;
        int y;
    public:
        int getX() const
        {
            return x;
        }

        void setX(int x)
        {
            Projectile::x = x;
        }

        int getY() const
        {
            return y;
        }

        void setY(int y)
        {
            Projectile::y = y;
        }

        virtual bool move()=0;
    };
}

#endif //SPACE_INVADERS_PROJECTILE_H
