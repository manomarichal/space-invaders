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

#include "SpaceSettings.h"
#include "../entities/abstract_classes/Entity.h"

#include <SFML/Graphics.hpp>

namespace util
{
    class Transformation
    {
    public:
        static float getXPixelValue(float x);

        static float getYPixelValue(float y);

        static float getXScale();

        static float getYScale();

        static void setScreenWidth(float screenWidth);

        static void setScreenHeight(float screenHeight);

        static float getScreenWidth();

        static float getScreenHeight();

        template <class T>
        static T transform(T sprite);

    private:
        static float screenWidth;
        static float screenHeight;
        Transformation()= default;

    public:
        // We do not want copies of our singleton
        Transformation(const Transformation &copy) = delete;
        Transformation& operator=(Transformation) = delete;

    };
}

#endif //SPACE_INVADERS_TRANSFORMATION_H
