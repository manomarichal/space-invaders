// =====================================================================
// @name: StandardProjectile.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 06.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_STANDARDPROJECTILE_H
#define SPACE_INVADERS_STANDARDPROJECTILE_H

#include "../../abstract_classes/Entity.h"
#include "../../abstract_classes/Subject.h"
namespace entities::projectiles
{
    class StandardProjectile: public Entity, public Subject
    {
    private:
        double vspeed = 50;
    public:
        StandardProjectile(int x, int y): Entity(x, y) {};
        void update() override;
        ~StandardProjectile() override = default;
    };
}

#endif //SPACE_INVADERS_STANDARDPROJECTILE_H
