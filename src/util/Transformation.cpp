
/** \file Transformation.cpp
* project: space_invaders
* author: Mano Marichal
* date: 14.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */


#include "./Transformation.h"
using namespace util;

float Transformation::screenHeight = 0;
float Transformation::screenWidth = 0;

float Transformation::getXScale()
{
    return screenWidth / util::SpaceSettings::width;
}

float Transformation::getYScale()
{
    return screenHeight / util::SpaceSettings::height;
}

float Transformation::getXPixelValue(float x)
{
    return (x * Transformation::getXScale()) + Transformation::screenWidth / 2;
}

float Transformation::getYPixelValue(float y)
{
    return (util::SpaceSettings::yMax - y) * Transformation::getYScale();
}

void Transformation::setScreenWidth(float screenWidth)
{
    Transformation::screenWidth = screenWidth;
}

void Transformation::setScreenHeight(float screenHeight)
{
    Transformation::screenHeight = screenHeight;
}

float Transformation::getScreenWidth()
{
    return screenWidth;
}

float Transformation::getScreenHeight()
{
    return screenHeight;
}

template <class T>
T Transformation::transform(T sprite)
{
    sprite.setScale(getXScale() * sprite.getScale().x, getYScale() * sprite.getScale().y);
    sprite.setPosition(Transformation::getXPixelValue(sprite.getPosition().x),
                       Transformation::getYPixelValue(sprite.getPosition().y));
    return sprite;
}

template sf::Sprite Transformation::transform(sf::Sprite sprite);
template sf::Text Transformation::transform(sf::Text sprite);
