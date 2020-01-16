/** \file Shield.cpp
 * project: space_invaders
 * author: Mano Marichal
 * date: 27.12.19
 * copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#include "Shield.h"

using namespace objects::shield;

Shield::Shield(float x, float y) : Entity(x, y)
{
        xSize = util::SpaceSettings::width / 15;
        ySize = util::SpaceSettings::height / 70;
}
