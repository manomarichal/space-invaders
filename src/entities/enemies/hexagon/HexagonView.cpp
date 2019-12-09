// =====================================================================
// @name: HexagonView.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 08.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "HexagonView.h"
using namespace entities::enemies;

HexagonView::HexagonView(std::shared_ptr<Hexagon> hexagon)
{
    entity = std::move(hexagon);
    maxHP = entity->hitpoints;

    texture = std::make_unique<sf::Texture>();
    texture->loadFromFile("../textures/playershipleft.jpg", sf::IntRect(0, 0, 64, 64));

    sprite = std::make_unique<sf::Sprite>();
    sprite->setTexture(*texture);
    sprite->setOrigin(entity->getXSize()/2, entity->getYSize()/2);
}

void HexagonView::draw(sf::RenderWindow &window) const
{
    sprite->setScale(entity->hitpoints/maxHP, entity->hitpoints/maxHP);
    sprite->setPosition(entity->getX(), entity->getY());
    sprite->setRotation(sprite->getRotation() + 2);
    window.draw(*sprite);
}