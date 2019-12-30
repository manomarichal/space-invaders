/** \file Shield.h
* project: space_invaders
* author: Mano Marichal
* date: 27.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#ifndef SPACE_INVADERS_SHIELD_H
#define SPACE_INVADERS_SHIELD_H

#include "../abstract_classes/Entity.h"

namespace entities::shield
{
    class Shield: public Entity
    {
    public:
        Shield(float x, float y);
        void update() override {};
        ~Shield() override = default;
    };
}

#endif //SPACE_INVADERS_SHIELD_H
