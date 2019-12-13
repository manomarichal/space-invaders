// =====================================================================
// @name: GreenAlien.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 11.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_GREENALIEN_H
#define SPACE_INVADERS_GREENALIEN_H


#include "../Enemy.h"

namespace entities::enemies::green_alien
{
    class GreenAlien: public Enemy
    {
        const float vspeed = 0.3;
    public:
        int maxHp;
        GreenAlien (float x, float y);
        void move();
        void update() override;
        void takeDamage(unsigned int damage) override;
        ~GreenAlien() override = default;
    };
}


#endif //SPACE_INVADERS_GREENALIEN_H
