// =====================================================================
// @name: Transformation.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 14.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "./Transformation.h"
using namespace entities;

unsigned int Transformation::screenHeight = 0;
unsigned int Transformation::screenWidth = 0;

float Transformation::transformXToPixelValues(float x)
{
    return (static_cast<float>(Transformation::screenWidth)/(screensize::x / x));
}

float Transformation::transformYToPixelValues(float y)
{
    return (static_cast<float>(Transformation::screenHeight)/(screensize::y / y));
}

void Transformation::setScreenWidth(unsigned int screenWidth)
{
    Transformation::screenWidth = screenWidth;
}

void Transformation::setScreenHeight(unsigned int screenHeight)
{
    Transformation::screenHeight = screenHeight;
}