// =====================================================================
// @name: ProjectileController.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 03.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_PROJECTILECONTROLLER_H
#define SPACE_INVADERS_PROJECTILECONTROLLER_H

#include "../Controller.h"
#include "./Projectile.h"

#include "./standard/StandardProjectile.h"

namespace entities::projectiles
{
    enum Type {standard};

    class ProjectileController: public Controller
    {
    private:
        std::vector<ProjectileView*> activeProjectiles;
    public:
        void createProjectile(int x, int y, Type type);

        void draw(sf::RenderWindow &window) override;
        void update() override ;
        ~ProjectileController() override;
    };
}

#endif //SPACE_INVADERS_PROJECTILECONTROLLER_H
