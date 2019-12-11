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

#include "../../abstract_classes/Entity.h"
#include "../../abstract_classes/Subject.h"
#include "../../abstract_classes/Enemy.h"

namespace entities::enemies::hexagon
{
    class Hexagon: public Entity, public Subject, public Enemy
    {
        const float vspeed = 0.7;
        const float hspeed = 2;
    public:
        int dir;
        int maxHp;
        Hexagon (int x, int y);
        void move();
        void update() override;
        void takeDamage() override;
        ~Hexagon() override = default;
    };
}


#endif //SPACE_INVADERS_HEXAGON_H
