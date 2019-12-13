// =====================================================================
// @name: RedAlien.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 12.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_REDALIEN_H
#define SPACE_INVADERS_REDALIEN_H


#include "../Enemy.h"

namespace entities::enemies::red_alien
{
    class RedAlien: public Enemy
    {
        const float vspeed = 0.3;
    public:
        RedAlien (float x, float y);
        void move();
        void update() override;
        void takeDamage(unsigned int damage) override;
        ~RedAlien() override = default;
    };
}

#endif //SPACE_INVADERS_REDALIEN_H
