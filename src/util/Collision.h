/** \file Collision.h
 * project: space_invaders
 * author: Mano Marichal
 * date: 09.12.19
 * copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#ifndef SPACE_INVADERS_COLLISION_H
#define SPACE_INVADERS_COLLISION_H

#include "../objects/abstract_classes/Entity.h"

namespace util {
class Collision
{
private:
        Collision() = default;

public:
        /**
         * checks collision between 2 objects
         * @param e1
         * @param e2
         * @return true means the 2 objects collide, false means they do not
         */
        static bool checkCollision(const objects::Entity& e1, const objects::Entity& e2);
        /**
         * checks collision between e1 and a shield entity
         * @param e1 the objects checking if it collides with a shield
         * @param e2 the shield entity
         * @return true means the 2 objects collide, false means they do not
         */
        static bool shield(const objects::Entity& e1, const std::shared_ptr<objects::Entity>& e2);
        /**
         * checks collision between e1 and an enemy entity
         * @param e1 the objects checking if it collides with an enemy
         * @param e2 the enemy entity
         * @return true means the 2 objects collide, false means they do not
         */
        static bool enemy(const objects::Entity& e1, const std::shared_ptr<objects::Entity>& e2);
        /**
         * checks collision between e1 and a playership entity
         * @param e1 the objects checking if it collides with a playership
         * @param e2 the playership entity
         * @return true means the 2 objects collide, false means they do not
         */
        static bool playership(const objects::Entity& e1, const std::shared_ptr<objects::Entity>& e2);
        /**
         * checks collision between e1 and a standardProjectile entity
         * @param e1 the objects checking if it collides with a standardProjectile
         * @param e2 the standardProjectile entity
         * @return true means the 2 objects collide, false means they do not
         */
        static bool standardProjectile(const objects::Entity& e1, const std::shared_ptr<objects::Entity>& e2);
        /**
         * checks collision between e1 and a standardEnemyProjectile entity
         * @param e1 the objects checking if it collides with a standardEnemyProjectile
         * @param e2 the standardEnemyProjectile entity
         * @return true means the 2 objects collide, false means they do not
         */
        static bool standardEnemyProjectile(const objects::Entity& e1, const std::shared_ptr<objects::Entity>& e2);
};
} // namespace util
#endif // SPACE_INVADERS_COLLISION_H
