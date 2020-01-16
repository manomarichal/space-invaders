/** \file ProjectileFactory.h
 * project: space_invaders
 * author: Mano Marichal
 * date: 06.12.19
 * copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#ifndef SPACE_INVADERS_PROJECTILEFACTORY_H
#define SPACE_INVADERS_PROJECTILEFACTORY_H

#include "../../util/Object.h"
#include "../../world/World.h"

namespace objects::projectiles {
class ProjectileFactory
{
public:
        /**
         * we use this to indicate which type of projectile we want to be created
         * */
        enum Type
        {
                Standard,
                Fast,
                EnemyStandard
        };
        /**
         *  creates a projectile
         * @param x the x coordinate where it should be created
         * @param y the y coordinate where it should be created
         * @param type the type of the projectile that should be created
         * @param world the world in which it should be created
         */
        static void createProjectile(float x, float y, Type type, World& world);

private:
        ProjectileFactory() = default; /// no instances of this class may be created
        /**
         * create a standard projectile
         * @param x the x coordinate where it should be created
         * @param y the y coordinate where it should be created
         * @param world the world in which it should be created
         * @return the objects
         */
        static util::Object createStandardProjectile(float x, float y, World& world);
        /**
         * create a standard enemy projectile
         * @param x the x coordinate where it should be created
         * @param y the y coordinate where it should be created
         * @param world the world in which it should be created
         * @return the objects
         */
        static util::Object createStandardEnemyProjectile(float x, float y, World& world);

public:
        // We do not want copies of our singleton
        ProjectileFactory(const ProjectileFactory& copy) = delete;
        ProjectileFactory& operator=(ProjectileFactory) = delete;
};
} // namespace objects::projectiles

#endif // SPACE_INVADERS_PROJECTILEFACTORY_H
