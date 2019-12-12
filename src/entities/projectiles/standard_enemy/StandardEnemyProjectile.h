// =====================================================================
// @name: StandardEnemyProjectile.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 11.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_STANDARDENEMYPROJECTILE_H
#define SPACE_INVADERS_STANDARDENEMYPROJECTILE_H

#include "../../abstract_classes/Entity.h"
#include "../../abstract_classes/Subject.h"

namespace entities::projectiles::standard_enemy
{
    class StandardEnemyProjectile: public Entity
    {
    private:
        float vspeed = 5;
    public:
        StandardEnemyProjectile(int x, int y): Entity(x, y) {xSize = 8; ySize = 8;};
        void move();
        void update() override;
        ~StandardEnemyProjectile() override = default;
    };
}


#endif //SPACE_INVADERS_STANDARDENEMYPROJECTILE_H