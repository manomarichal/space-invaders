// =====================================================================
// @name: HexagonView.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 08.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "HexagonView.h"

using namespace entities::enemies::hexagon;

HexagonView::HexagonView(std::shared_ptr<Hexagon> hexagon)
: View(std::string("../textures/redsquare.jpg"), hexagon)
{
    maxHP = hexagon->hitpoints;
}

void HexagonView::notify()
{
    sprite->setScale(static_cast<float>(dynamic_cast<Hexagon*>(entity.get())->hitpoints)/maxHP, static_cast<float >(dynamic_cast<Hexagon*>(entity.get())->hitpoints) /maxHP);
    sprite->setPosition(entity->getX(), entity->getY());
}
