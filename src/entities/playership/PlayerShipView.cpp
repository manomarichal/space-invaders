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

    std::string FILENAME = "../textures/red.jpg";
    texture = new sf::Texture();
    if (!texture->loadFromFile(FILENAME))
    {
        throw std::runtime_error(FILENAME);
    }
    sprite = new sf::Sprite;
    sprite->setTexture(*texture);
    sprite->setScale(0.2, 0.2);

    object->setXSize(texture->getSize().x * 0.2);
}
void PlayerShipView::draw(sf::RenderWindow &window)
{
    sprite->setPosition(object->getX(), object->getY());
    window.draw(*sprite);
};

PlayerShipView::~PlayerShipView()
{
    delete sprite;
    delete texture;
    delete object;
}

PlayerShip *PlayerShipView::getObject() const
{
    return object;
}
