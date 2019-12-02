// =====================================================================
// @name: StandardProjectile.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 02.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_STANDARDPROJECTILE_H
#define SPACE_INVADERS_STANDARDPROJECTILE_H



#include "../Projectile.h"

namespace projectiles
{
    class StandardProjectile: public projectiles::Projectile
    {
    private:
        const int vspeed = 50;
    public:
        StandardProjectile(int x, int y): Projectile(x, y) {};
        bool move() override ;
        ~StandardProjectile() override = default;
    };
}


#endif //SPACE_INVADERS_STANDARDPROJECTILE_H
