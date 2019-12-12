// =====================================================================
// @name: Hexagon.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 04.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_HEXAGON_H
#define SPACE_INVADERS_HEXAGON_H

#include "../../abstract_classes/Subject.h"
#include "../Enemy.h"

namespace entities::enemies::hexagon
{
    class Hexagon: public Enemy
    {
        const float vspeed = 0.7;
        const float hspeed = 2;
    public:
        int hDir;
        int vDir;
        int maxHp;
        Hexagon (float x, float y);
        void move();
        void update() override;
        void takeDamage(unsigned int damage) override;
        ~Hexagon() override = default;
    };
}


#endif //SPACE_INVADERS_HEXAGON_H
