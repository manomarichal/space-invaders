/** \file StandardProjectileView.cpp
 * project: space_invaders
 * author: Mano Marichal
 * date: 06.12.19
 * copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#include "StandardProjectileView.h"
using namespace objects::projectiles::standard;

void StandardProjectileView::onNotify() { sprite->setPosition(entity->getX(), entity->getY()); }
