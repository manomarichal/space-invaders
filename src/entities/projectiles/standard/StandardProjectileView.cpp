// =====================================================================
// @name: StandardProjectileView.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 06.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "StandardProjectileView.h"
using namespace entities::projectiles::standard;

StandardProjectileView::StandardProjectileView(std::shared_ptr<StandardProjectile> projectile)
:View("../textures/whitesquare.png", projectile)
{
    dynamic_cast<Subject*>(entity.get())->subscribe(this);
}

void StandardProjectileView::notify()
{
    sprite->setPosition(entity->getX(), entity->getY());
}
