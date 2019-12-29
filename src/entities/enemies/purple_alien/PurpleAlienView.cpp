
/** \file PurpleAlienView.cpp
/// project: space_invaders
/// author: Mano Marichal
/// date: 08.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */
/// description:


#include "PurpleAlienView.h"

using namespace entities::enemies::purple_alien;

PurpleAlienView::PurpleAlienView(const std::shared_ptr<PurpleAlien> &alien)
: View(std::string("../resources/textures/purplealien.png"), alien)
{
    maxHP = alien->hitpoints;
}

void PurpleAlienView::onNotify()
{
    sprite->setScale(entity->getXSize()/texture->getSize().x, entity->getYSize()/texture->getSize().x);
    sprite->setPosition(entity->getX(), entity->getY());
}
