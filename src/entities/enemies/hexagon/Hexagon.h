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
        uint vspeed = 1;
    public:
        Hexagon (int x, int y): Entity(x, y, hexagon) {xSize=64; ySize=64;};
        int hitpoints = 5;
        void move();
        ~Hexagon() override = default;
    };
}


#endif //SPACE_INVADERS_HEXAGON_H
