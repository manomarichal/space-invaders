/** \file PlayerShip.h
 * project: space_invaders
 * author: Mano Marichal
 * date: 01.12.19
 * copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#ifndef SPACE_INVADERS_PLAYERSHIP_H
#define SPACE_INVADERS_PLAYERSHIP_H

#include "../abstract_classes/Entity.h"

namespace objects::playership {
class PlayerShip : public Entity
{
public:
        PlayerShip(float x, float y);

        float hitpoints;
        /**
         * moves the ship to the left
         */
        void moveLeft();
        /**
         * moves the ship to the right
         */
        void moveRight();
        /**
         * makes the ship take damage
         * @param damage amount of damage
         */
        void takeDamage(float damage);

        void update() override;

        ~PlayerShip() override = default;
};
} // namespace objects::playership

#endif // SPACE_INVADERS_PLAYERSHIP_H
