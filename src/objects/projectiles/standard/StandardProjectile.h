/** \file StandardProjectile.h
 * project: space_invaders
 * author: Mano Marichal
 * date: 06.12.19
 * copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#ifndef SPACE_INVADERS_STANDARDPROJECTILE_H
#define SPACE_INVADERS_STANDARDPROJECTILE_H

#include "../../abstract_classes/Entity.h"

namespace objects::projectiles::standard {
class StandardProjectile : public Entity
{
private:
        float vspeed;

public:
        StandardProjectile(float x, float y);
        void move();
        void update() override;
        ~StandardProjectile() override = default;
};
} // namespace objects::projectiles::standard

#endif // SPACE_INVADERS_STANDARDPROJECTILE_H
