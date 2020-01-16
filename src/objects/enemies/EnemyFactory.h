// =====================================================================
// @name: EnemyFactory.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 01.01.20
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description:
// =====================================================================

#ifndef SPACE_INVADERS_ENEMYFACTORY_H
#define SPACE_INVADERS_ENEMYFACTORY_H

#include "../../util/Object.h"
#include "../../world/World.h"

namespace objects::enemies {
class EnemyFactory
{
public:
        /**
         * we use this to indicate which type of enemy we want to be created
         * */
        enum Type
        {
                RedAlien,
                GreenAlien,
                PurpleAlien
        };
        /**
         *  creates an enemy
         * @param x the x coordinate where it should be created
         * @param y the y coordinate where it should be created
         * @param type the type of enemy that should be created
         * @param world the world in which it should be created
         */
        static void createEnemy(float x, float y, Type type, World& world);

private:
        EnemyFactory() = default;
        static util::Object createRedAlien(float x, float y, World& world);
        static util::Object createGreenAlien(float x, float y, World& world);
        static util::Object createPurpleAlien(float x, float y, World& world);

public:
        // We do not want copies of our singleton
        EnemyFactory(const EnemyFactory& copy) = delete;
        EnemyFactory& operator=(EnemyFactory) = delete;
};
} // namespace objects::enemies

#endif // SPACE_INVADERS_ENEMYFACTORY_H
