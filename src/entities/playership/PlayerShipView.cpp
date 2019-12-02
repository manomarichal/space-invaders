// =====================================================================
// @name: PlayerShipView.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 01.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "./PlayerShipView.h"
PlayerShipView::PlayerShipView()
{
    texture = new sf::Texture();
    texture->loadFromFile("../textures/playershipstill.jpg", sf::IntRect(0, 0, 64, 64));

    sprite = new sf::Sprite;
    sprite->setTexture(*texture);
}
void PlayerShipView::draw(sf::RenderWindow &window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        texture->loadFromFile("../textures/playershipleft.jpg", sf::IntRect(0, 0, 64, 64));
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        texture->loadFromFile("../textures/playershipright.jpg", sf::IntRect(0, 0, 64, 64));
    else
        texture->loadFromFile("../textures/playershipstill.jpg", sf::IntRect(0, 0, 64, 64));

    sprite->setPosition(object->x, object->y);
    window.draw(*sprite);
};

PlayerShipView::~PlayerShipView()
{
    delete object;
    delete sprite;
    delete texture;
}

