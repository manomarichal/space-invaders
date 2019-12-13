// =====================================================================
// @name: PurpleAlienView.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 08.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "PurpleAlienView.h"

using namespace entities::enemies::purple_alien;

PurpleAlienView::PurpleAlienView(const std::shared_ptr<PurpleAlien> &alien)
: View(std::string("../textures/purplealien.png"), alien)
{
    maxHP = alien->hitpoints;
}

void PurpleAlienView::notify()
{
    sprite->setScale(static_cast<float>(dynamic_cast<PurpleAlien*>(entity.get())->hitpoints) / maxHP, static_cast<float >(dynamic_cast<PurpleAlien*>(entity.get())->hitpoints) / maxHP);
    sprite->setPosition(entity->getX(), entity->getY());
}