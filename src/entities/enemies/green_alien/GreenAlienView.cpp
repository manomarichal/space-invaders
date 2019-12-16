// =====================================================================
// @name: GreenAlienView.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 11.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "GreenAlienView.h"

using namespace entities::enemies::green_alien;

GreenAlienView::GreenAlienView(const std::shared_ptr<GreenAlien> &alien)
:View("../textures/greenalien.png", alien) {}

void GreenAlienView::notify()
{
    sprite->setPosition(entity->getX(), entity->getY());
}
