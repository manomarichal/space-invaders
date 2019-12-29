
/** \file RedAlienView.cpp
/// project: space_invaders
/// author: Mano Marichal
/// date: 12.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */
/// description:


#include "RedAlienView.h"
using namespace entities::enemies::red_alien;

RedAlienView::RedAlienView(const std::shared_ptr<RedAlien> &enemy)
:View(std::string("../resources/textures/redalien.png"), enemy)
{

}

void RedAlienView::onNotify()
{
    sprite->setPosition(entity->getX(), entity->getY());
}