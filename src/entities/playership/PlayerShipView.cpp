// =====================================================================
// @name: PlayerShipView.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 05.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "PlayerShipView.h"

using namespace entities::playership;

PlayerShipView::PlayerShipView(std::shared_ptr<PlayerShip> ship)
{
    entity = std::move(ship);

    texture = std::make_unique<sf::Texture>();
    texture->loadFromFile("../textures/playershipstill.jpg", sf::IntRect(0, 0, 64, 64));

    sprite = std::make_unique<sf::Sprite>();
    sprite->setTexture(*texture);
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

    sprite->setPosition(entity->getX(), entity->getY());
    window.draw(*sprite);
}