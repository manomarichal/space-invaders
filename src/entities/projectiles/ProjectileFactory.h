// =====================================================================
// @name: ProjectileFactory.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 06.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_PROJECTILEFACTORY_H
#define SPACE_INVADERS_PROJECTILEFACTORY_H

#include "../../util/Object.h"
#include "../../Game.h"
#include "./standard/StandardProjectileController.h"

namespace entities::projectiles
{
    enum Type {standard, fast};
    class ProjectileFactory
    {
    private:
        ProjectileFactory()= default;
        static Object createStandardProjectile(int x, int y, Game* game);
    public:
        static void createProjectile(int x, int y, Type type, Game* game);
    };
}



#endif //SPACE_INVADERS_PROJECTILEFACTORY_H
