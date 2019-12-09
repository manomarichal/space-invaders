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

#include "../abstract_classes/Subject.h"
#include "../abstract_classes/Entity.h"

#include "../../settings/screensize.h"

namespace entities
{
    class PlayerShip: public Entity, public Subject
    {
    private:
        float vx=0;  // horizontal velocity
        float ax = 6;
        const float max_v = 30; // max horizontal velocity
        const float friction = 0.90;

    public:
        PlayerShip(int x, int y): Entity(x, y, playership) {xSize = 64; ySize = 64;};

        int hitpoints = 10;
        void moveLeft();
        void moveRight();
        void move();
        ~PlayerShip() override;
    };
}

#endif //SPACE_INVADERS_PLAYERSHIP_H
