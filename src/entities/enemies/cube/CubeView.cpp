// =====================================================================
// @name: CubeView.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 12.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "CubeView.h"
using namespace entities::enemies::cube;

void CubeView::notify()
{
    sprite->setPosition(entity->getX(), entity->getY());
}