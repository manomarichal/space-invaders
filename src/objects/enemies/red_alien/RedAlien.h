/** \file RedAlien.h
* project: space_invaders
* author: Mano Marichal
* date: 12.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */#ifndef SPACE_INVADERS_REDALIEN_H
#define SPACE_INVADERS_REDALIEN_H


#include "../Enemy.h"

namespace objects::enemies::red_alien
{
    class RedAlien: public Enemy
    {
    public:
        RedAlien (float x, float y);
        void update() override;
        ~RedAlien() override = default;
    };
}

#endif //SPACE_INVADERS_REDALIEN_H
