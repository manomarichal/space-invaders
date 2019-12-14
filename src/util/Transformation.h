// =====================================================================
// @name: Transformation.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 14.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_TRANSFORMATION_H
#define SPACE_INVADERS_TRANSFORMATION_H

#include "../settings/screensize.h"

namespace entities
{
    class Transformation
    {
    private:
        static unsigned int screenWidth;
        static unsigned int screenHeight;
        Transformation()= default;
    public:
        static float transformXToPixelValues(float x);
        static float transformYToPixelValues(float y);
        static void setScreenWidth(unsigned int screenWidth);
        static void setScreenHeight(unsigned int screenHeight);
    };
}

#endif //SPACE_INVADERS_TRANSFORMATION_H
