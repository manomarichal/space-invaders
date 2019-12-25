// =====================================================================
// @name: screensize.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 02.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_SCREENSIZE_H
#define SPACE_INVADERS_SCREENSIZE_H

#include <cstdlib>

namespace screensize
{
    const float xMax = 8;
    const float xMin = -8;
    const float yMax = 6;
    const float yMin = -6;
    const float width = std::abs(xMin) + std::abs(xMax);
    const float height = std::abs(yMin) + std::abs(yMax);
}

#endif //SPACE_INVADERS_SCREENSIZE_H
