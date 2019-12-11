// =====================================================================
// @name: HexagonView.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 08.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "HexagonView.h"
#include <iostream>
using namespace entities::enemies;

HexagonView::HexagonView(std::shared_ptr<Hexagon> hexagon)
{
    entity = std::move(hexagon);
    entity->subscribe(this);
    texture = std::make_unique<sf::Texture>();
    texture->loadFromFile("../textures/redsquare.jpg", sf::IntRect(0, 0, 64, 64));

    sprite = std::make_unique<sf::Sprite>();
    sprite->setTexture(*texture);
    sprite->setOrigin(entity->getXSize()/2, entity->getYSize()/2);
}

void HexagonView::notify()
{
    sprite->setPosition(entity->getX(), entity->getY());
}

void HexagonView::draw(sf::RenderWindow &window) const
{
    window.draw(*sprite);
}