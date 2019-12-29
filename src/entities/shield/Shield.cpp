
/** \file Shield.cpp
/// project: space_invaders
/// author: Mano Marichal
/// date: 27.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */
/// description:


#include "Shield.h"

using namespace entities::shield;

Shield::Shield(float x, float y)
        :Entity(x, y)
{
    xSize = SpaceSettings::width / 15;
    ySize = SpaceSettings::height / 70;
}
