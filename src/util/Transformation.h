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

#include "screensize.h"
#include "../entities/abstract_classes/Entity.h"
#include <SFML/Graphics.hpp>

namespace util
{
    class Transformation
    {
    private:
        static unsigned int screenWidth;
        static unsigned int screenHeight;
        Transformation()= default;
    public:
        static float getXPixelValue(float x);
        static float getYPixelValue(float y);
        static float getXScale();
        static float getYScale();
        static void setScreenWidth(unsigned int screenWidth);
        static void setScreenHeight(unsigned int screenHeight);
        static unsigned int getScreenWidth();
        static unsigned int getScreenHeight();

        template <class T>
        static T transform(T sprite)
        {
            sprite.setPosition(util::Transformation::getXPixelValue(sprite.getPosition().x),
                               util::Transformation::getYPixelValue(sprite.getPosition().y));
            sprite.setScale(util::Transformation::getXScale() * sprite.getScale().x,
                            util::Transformation::getYScale() * sprite.getScale().y);
            return sprite;
        }

    };
}

#endif //SPACE_INVADERS_TRANSFORMATION_H
