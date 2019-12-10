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

namespace entities::enemies
{
    class Hexagon: public Entity
    {
        int vspeed = 1;
        int hspeed = 4;
        int dir;
    public:
        Hexagon (int x, int y);
        int hitpoints = 5;
        void move();
        void setDir(int dir);

        [[nodiscard]] int getDir() const;

        ~Hexagon() override = default;
    };
}


#endif //SPACE_INVADERS_HEXAGON_H
