
/** \file Transformation.h
/// project: space_invaders
/// author: Mano Marichal
/// date: 14.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */
/// description: Used to calculate the transformations between the game coördinate system and the screen size


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
        /**
         * transforms an x coördinate from game logic to the actual screen size
         * @param x the x to be transformed
         * @return the transformed x
         */
        static float getXPixelValue(float x);
        /**
         * transforms an y coördinate from game logic to the actual screen size
         * @param y the y to be transformed
         * @return the transformed y
         */
        static float getYPixelValue(float y);
        /**
         * calculates how wide the game logic width is compared to the screen size width
         * @return the scale
         */
        static float getXScale();
        /**
         * calculates how high the game logic height is compared to the screen size height
         * @return the scale
         */
        static float getYScale();

        /// GETTERS AND SETTERS
        static void setScreenWidth(float screenWidth);

        static void setScreenHeight(float screenHeight);

        static float getScreenWidth();

        static float getScreenHeight();

        /**
         * sprites have coördinates corresponding to their entity, but when they need to be drawn their
         * coördinates need to get transformed to the screensize of our window, that is what this function does
         * @tparam T can be an sf::Sprite or sf::Text
         * @param sprite the object that needs their coördinates transformed
         * @return a copy of the initial object but with transformed coördinates
         */
        template <class T>
        static T transform(T sprite);

    private:
        static float screenWidth;
        static float screenHeight;
        Transformation()= default;

    public:
        /// We do not want copies of our singleton
        Transformation(const Transformation &copy) = delete;
        Transformation& operator=(Transformation) = delete;
    };
}

#endif //SPACE_INVADERS_TRANSFORMATION_H
