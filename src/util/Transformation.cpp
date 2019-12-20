// =====================================================================
// @name: Transformation.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 14.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "./Transformation.h"
using namespace util;

unsigned int util::Transformation::screenHeight = 0;
unsigned int util::Transformation::screenWidth = 0;

float util::Transformation::getXPixelValue(float x)
{
    return (static_cast<float>(util::Transformation::screenWidth)/(screensize::x / x));
}

float util::Transformation::getYPixelValue(float y)
{
    return (static_cast<float>(util::Transformation::screenHeight)/(screensize::y / y));
}

void util::Transformation::setScreenWidth(unsigned int screenWidth)
{
    util::Transformation::screenWidth = screenWidth;
}

void util::Transformation::setScreenHeight(unsigned int screenHeight)
{
    util::Transformation::screenHeight = screenHeight;
}

float util::Transformation::getXScale()
{
    return static_cast<float>(screenWidth) / static_cast<float>(screensize::x);

}

float util::Transformation::getYScale()
{
    return static_cast<float>(screenHeight) / static_cast<float>(screensize::y);

}

unsigned int util::Transformation::getScreenWidth()
{
    return screenWidth;
}

unsigned int util::Transformation::getScreenHeight()
{
    return screenHeight;
}

template <class T>
T Transformation::transform(T sprite)
{
    sprite.setPosition(util::Transformation::getXPixelValue(sprite.getPosition().x),
                       util::Transformation::getYPixelValue(sprite.getPosition().y));
    sprite.setScale(util::Transformation::getXScale() * sprite.getScale().x,
                    util::Transformation::getYScale() * sprite.getScale().y);
    return sprite;
}

template sf::Sprite Transformation::transform(sf::Sprite sprite);
template sf::Text Transformation::transform(sf::Text sprite);
