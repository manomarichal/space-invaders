/** \file PlayerShip.cpp
* project: space_invaders
* author: Mano Marichal
* date: 01.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */#include "PlayerShip.h"

using namespace objects::playership;

PlayerShip::PlayerShip(float x, float y)
: Entity(x, y)
{
    xSize = util::SpaceSettings::width / 20;
    ySize = util::SpaceSettings::height / 15;
    hitpoints = 3;
}

void PlayerShip::moveLeft()
{
    x -= util::SpaceSettings::width / 120;
    if (x - xSize/2 < util::SpaceSettings::xMin) x = util::SpaceSettings::xMin + xSize / 2;
    onNotifyObservers();
}

void PlayerShip::moveRight()
{
    x += util::SpaceSettings::width / 120;
    if (x + xSize/2 > util::SpaceSettings::xMax) x = util::SpaceSettings::xMax - xSize / 2;
    onNotifyObservers();
}

void PlayerShip::update()
{
}

void PlayerShip::takeDamage([[maybe_unused]] float damage)
{
    hitpoints -= 1;
    onNotifyObservers();
}

