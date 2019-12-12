// =====================================================================
// @name: PentagonView.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 11.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "PentagonView.h"

using namespace entities::enemies::pentagon;

PentagonView::PentagonView(std::shared_ptr<Pentagon> pentagon)
:View("../textures/bluesquare.jpg", pentagon)
{
    maxHP = pentagon->hitpoints;
}

void PentagonView::notify()
{
    sprite->setScale(static_cast<float>(dynamic_cast<Enemy*>(entity.get())->hitpoints)/maxHP, static_cast<float >(dynamic_cast<Enemy*>(entity.get())->hitpoints) /maxHP);
    sprite->setPosition(entity->getX(), entity->getY());
}
