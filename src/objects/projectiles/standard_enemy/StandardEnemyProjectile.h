/** \file StandardEnemyProjectile.h
* project: space_invaders
* author: Mano Marichal
* date: 11.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#ifndef SPACE_INVADERS_STANDARDENEMYPROJECTILE_H
#define SPACE_INVADERS_STANDARDENEMYPROJECTILE_H

#include "../../abstract_classes/Entity.h"

namespace objects::projectiles::standard_enemy
{
    class StandardEnemyProjectile: public Entity
    {
    private:
        float vspeed;
    public:
        StandardEnemyProjectile(float x, float y);
        void move();
        void update() override;
        ~StandardEnemyProjectile() override = default;
    };
}


#endif //SPACE_INVADERS_STANDARDENEMYPROJECTILE_H
