// =====================================================================
// @name: Collision.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 09.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

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
        static bool checkCollision(const entities::Entity &e1, const entities::Entity &e2);
        static bool shield(const entities::Entity &e1, const std::shared_ptr<entities::Entity> &e2);
        static bool enemy(const entities::Entity &e1, const std::shared_ptr<entities::Entity> &e2);
        static bool playership(const entities::Entity &e1, const std::shared_ptr<entities::Entity> &e2);
        static bool standardProjectile(const entities::Entity &e1, const std::shared_ptr<entities::Entity> &e2);
        static bool standardEnemyProjectile(const entities::Entity &e1, const std::shared_ptr<entities::Entity> &e2);
    };
}
#endif //SPACE_INVADERS_COLLISION_H
