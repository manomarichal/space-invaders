// =====================================================================
// @name: Pentagon.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 11.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_PENTAGON_H
#define SPACE_INVADERS_PENTAGON_H

#include "../../abstract_classes/Subject.h"
#include "../../abstract_classes/Enemy.h"

namespace entities::enemies::pentagon
{
    class Pentagon: public Enemy, public Subject
    {
        const float vspeed = 0.1;
        const float hspeed = 0;
    public:
        int dir;
        int maxHp;
        Pentagon (float x, float y);
        void move();
        void update() override;
        void takeDamage(unsigned int damage) override;
        ~Pentagon() override = default;
    };
}


#endif //SPACE_INVADERS_PENTAGON_H
