// =====================================================================
// @name: PlayerShipView.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 05.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "PlayerShipView.h"

using namespace entities;

PlayerShipView::PlayerShipView(std::shared_ptr<PlayerShip> ship)
{
    entity = std::move(ship);
    entity->subscribe(this);

    texture = std::make_unique<sf::Texture>();
    texture->loadFromFile("../textures/playershipleft.jpg", sf::IntRect(0, 0, 64, 64));

    sprite = std::make_unique<sf::Sprite>();
    sprite->setTexture(*texture);
    sprite->setOrigin(entity->getXSize()/2, entity->getYSize()/2);
}

void PlayerShipView::notify()
{
    sprite->setPosition(entity->getX(), entity->getY());
}
void PlayerShipView::draw(sf::RenderWindow &window) const
{
    /*
    switch (currentSprite)
    {
        case idle:
            texture->loadFromFile("../textures/playershipstill.jpg", sf::IntRect(0, 0, 64, 64));
            break;
        case left:
            texture->loadFromFile("../textures/playershipleft.jpg", sf::IntRect(0, 0, 64, 64));
            break;
        case right:
            texture->loadFromFile("../textures/playershipright.jpg", sf::IntRect(0, 0, 64, 64));
            break;
    }
     */
    window.draw(*sprite);
}