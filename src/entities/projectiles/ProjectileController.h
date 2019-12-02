// =====================================================================
// @name: StandardProjectileController.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 02.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_PROJECTILECONTROLLER_H
#define SPACE_INVADERS_PROJECTILECONTROLLER_H


#include <vector>

#include "../Controller.h"
#include "standard/StandardProjectile.h"

namespace projectiles
{
    class ProjectileController: public Controller
    {
    private:
        projectiles::StandardProjectile* projectile;
    public:

        void update(sf::RenderWindow &window) override ;
        ~ProjectileController() override;
    };
}


#endif //SPACE_INVADERS_PROJECTILECONTROLLER_H
