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

#include "../Subject.h"
#include "../Entity.h"

#include "../../settings/screensize.h"

namespace entities::playership
{
    class PlayerShip: public Entity, public Subject
    {
    private:
        double vx=0;  // horizontal velocity
        double ax = 6;
        const double max_v = 30; // max horizontal velocity
        const double friction = 0.90;

    public:
        PlayerShip() {x = screensize::x/2; y = screensize::y-(screensize::y/10);};
        unsigned int xSize = 64;

        void moveLeft();
        void moveRight();
        void move();
        void update() override;

        ~PlayerShip() override;
    };
}

#endif //SPACE_INVADERS_PLAYERSHIP_H
