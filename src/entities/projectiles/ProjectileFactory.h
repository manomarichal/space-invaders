
/** \file ProjectileFactory.h
* project: space_invaders
* author: Mano Marichal
* date: 06.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */
/// description: Factory class used to create projectiles


#ifndef SPACE_INVADERS_PROJECTILEFACTORY_H
#define SPACE_INVADERS_PROJECTILEFACTORY_H

#include "../../world/World.h"
#include "../../util/Object.h"
#include "./standard/StandardProjectileController.h"
#include "./standard_enemy/StandardEnemyProjectileController.h"

namespace entities::projectiles
{
    enum Type {Standard, Fast, EnemyStandard}; /*!< we use this to indicate which type of projectile we want to be created */
    class ProjectileFactory
    {
    public:
        static void createProjectile(float x, float y, Type type, World &world);

    private:
        ProjectileFactory()= default;   /// no instances of this class may be created
        /**
         * create a standard projectile
         * @param x the x coordinate where it should be created
         * @param y the y coordinate where it should be created
         * @param world the world in which it should be created
         * @return the object
         */
        util::Object k;
        static util::Object createStandardProjectile(float x, float y, World &world);
        /**
         * create a standard enemy projectile
         * @param x the x coordinate where it should be created
         * @param y the y coordinate where it should be created
         * @param world the world in which it should be created
         * @return the object
         */
        static util::Object createStandardEnemyProjectile(float x, float y, World &world);
    public:
        /// We do not want copies of our singleton
        ProjectileFactory(const ProjectileFactory &copy) = delete;
        ProjectileFactory& operator=(ProjectileFactory) = delete;
    };
}



#endif //SPACE_INVADERS_PROJECTILEFACTORY_H
