
/** \file ShieldView.cpp
/// project: space_invaders
/// author: Mano Marichal
/// date: 27.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */
/// description:


#include "./ShieldView.h"

using namespace entities::shield;

ShieldView::ShieldView(const std::shared_ptr<Entity> &entity) :View("../resources/textures/whitesquare.png", entity)
{sprite->setPosition(entity->getX(), entity->getY());}

void ShieldView::onNotify()
{
}