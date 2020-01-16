/** \file StandardEnemyProjectileView.cpp
 * project: space_invaders
 * author: Mano Marichal
 * date: 11.12.19
 * copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#include "StandardEnemyProjectileView.h"
using namespace objects::projectiles::standard_enemy;

void StandardEnemyProjectileView::onNotify() { sprite->setPosition(entity->getX(), entity->getY()); }
