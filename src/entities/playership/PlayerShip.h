// =====================================================================
// @name: PlayerShip.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 01.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description:
// =====================================================================

#ifndef SPACE_INVADERS_PLAYERSHIP_H
#define SPACE_INVADERS_PLAYERSHIP_H

#include "../abstract_classes/Entity.h"

namespace entities::playership
{
    class PlayerShip: public Entity
    {
    public:
        PlayerShip(float x, float y);

        int hitpoints = 3;
        void moveLeft();
        void moveRight();
        void takeDamage(unsigned int damage);
        void update() override;
        ~PlayerShip() override = default;
    };
}

#endif //SPACE_INVADERS_PLAYERSHIP_H
