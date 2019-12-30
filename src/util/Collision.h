
/** \file Collision.h
* project: space_invaders
* author: Mano Marichal
* date: 09.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */


#ifndef SPACE_INVADERS_COLLISION_H
#define SPACE_INVADERS_COLLISION_H

#include "../entities/abstract_classes/Entity.h"

namespace util
{
    class Collision
    {
    private:
        Collision()= default;
    public:
        /**
         * checks collision between 2 entities
         * @param e1
         * @param e2
         * @return true means the 2 entities collide, false means they do not
         */
        static bool checkCollision(const entities::Entity &e1, const entities::Entity &e2);
        /**
         * checks collision between e1 and a shield entity
         * @param e1 the object checking if it collides with a shield
         * @param e2 the shield entity
         * @return true means the 2 entities collide, false means they do not
         */
        static bool shield(const entities::Entity &e1, const std::shared_ptr<entities::Entity> &e2);
        /**
         * checks collision between e1 and an enemy entity
         * @param e1 the object checking if it collides with an enemy
         * @param e2 the enemy entity
         * @return true means the 2 entities collide, false means they do not
         */
        static bool enemy(const entities::Entity &e1, const std::shared_ptr<entities::Entity> &e2);
        /**
         * checks collision between e1 and a playership entity
         * @param e1 the object checking if it collides with a playership
         * @param e2 the playership entity
         * @return true means the 2 entities collide, false means they do not
         */
        static bool playership(const entities::Entity &e1, const std::shared_ptr<entities::Entity> &e2);
        /**
         * checks collision between e1 and a standardProjectile entity
         * @param e1 the object checking if it collides with a standardProjectile
         * @param e2 the standardProjectile entity
         * @return true means the 2 entities collide, false means they do not
         */
        static bool standardProjectile(const entities::Entity &e1, const std::shared_ptr<entities::Entity> &e2);
        /**
         * checks collision between e1 and a standardEnemyProjectile entity
         * @param e1 the object checking if it collides with a standardEnemyProjectile
         * @param e2 the standardEnemyProjectile entity
         * @return true means the 2 entities collide, false means they do not
         */
        static bool standardEnemyProjectile(const entities::Entity &e1, const std::shared_ptr<entities::Entity> &e2);
    };
}
#endif //SPACE_INVADERS_COLLISION_H
