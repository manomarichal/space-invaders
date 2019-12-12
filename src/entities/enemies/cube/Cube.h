// =====================================================================
// @name: Cube.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 12.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_CUBE_H
#define SPACE_INVADERS_CUBE_H

#include "../../abstract_classes/Subject.h"
#include "../Enemy.h"

namespace entities::enemies::cube
{
    class Cube: public Enemy
    {
        const float vspeed = 1.5;
    public:
        Cube (float x, float y);
        void move();
        void update() override;
        void takeDamage(unsigned int damage) override;
        ~Cube() override = default;
    };
}

#endif //SPACE_INVADERS_CUBE_H
