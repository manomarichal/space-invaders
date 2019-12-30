
/** \file PlayerShipView.cpp
* project: space_invaders
* author: Mano Marichal
* date: 05.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */
/// description:


#include "PlayerShipView.h"

using namespace entities::playership;

PlayerShipView::PlayerShipView(std::shared_ptr<PlayerShip> ship)
:View("../resources/textures/spaceship.png", ship)
{
    hud = std::make_shared<PlayerLivesView>(std::move(ship));
    hud->init();
    onNotify();
}

void PlayerShipView::onNotify()
{
    sprite->setPosition(entity->getX(), entity->getY());
}

void PlayerShipView::draw(sf::RenderWindow &window) const
{
    View::draw(window);
    hud->draw(window);
}
