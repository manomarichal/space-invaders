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
#include "../View.h"
#include "./standard/StandardProjectile.h"

namespace projectiles
{
    enum type {standard};

    class ProjectileController: public Controller
    {
    private:
        std::vector<View*> activeProjectiles;
    public:
        void createProjectile(int x, int y, projectiles::type type);

        void update() override ;
        ~ProjectileController() override;
    };
}


#endif //SPACE_INVADERS_PROJECTILECONTROLLER_H
