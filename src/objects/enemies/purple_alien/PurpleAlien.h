/** \file PurpleAlien.h
 * project: space_invaders
 * author: Mano Marichal
 * date: 04.12.19
 * copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#ifndef SPACE_INVADERS_PURPLEALIEN_H
#define SPACE_INVADERS_PURPLEALIEN_H

#include "../Enemy.h"

namespace objects::enemies::purple_alien {
class PurpleAlien : public Enemy
{
public:
        float maxHp;
        PurpleAlien(float x, float y);
        void update() override;
        ~PurpleAlien() override = default;
};
} // namespace objects::enemies::purple_alien

#endif // SPACE_INVADERS_PURPLEALIEN_H
