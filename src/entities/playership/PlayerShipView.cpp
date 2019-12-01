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
    object = new PlayerShip;

    texture = new sf::Texture();
    if (!texture->loadFromFile("../textures/red.jpg"))
    {
        throw std::runtime_error("could not load file ../textures/red.jpg");
    }
    sprite = new sf::Sprite;
    sprite->setTextureRect(sf::IntRect(10, 10, 32, 32));
};

void PlayerShipView::draw(sf::RenderWindow &window)
{
    window.draw(*sprite);
};

PlayerShipView::~PlayerShipView()
{
    delete sprite;
    delete texture;
    delete object;
}