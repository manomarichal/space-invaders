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

#include "../../world/World.h"
#include "../../util/Object.h"
#include "./standard/StandardProjectileController.h"
#include "./standard_enemy/StandardEnemyProjectileController.h"

namespace entities::projectiles
{
    enum Type {Standard, Fast, EnemyStandard};
    class ProjectileFactory
    {
    private:
        ProjectileFactory()= default;   // no instances of this class may be created
        static entities::Object createStandardProjectile(int x, int y, World &world);
        static entities::Object createStandardEnemyProjectile(int x, int y, World &world);
    public:
        static void createProjectile(int x, int y, Type type, World &world);
    };
}



#endif //SPACE_INVADERS_PROJECTILEFACTORY_H
