// =====================================================================
// @name: PentagonView.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 11.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "PentagonView.h"

using namespace entities::enemies::pentagon;

PentagonView::PentagonView(std::shared_ptr<Pentagon> pentagon)
{
    entity = std::move(pentagon);
    entity->subscribe(this);

    maxHP = entity->hitpoints;

    texture = std::make_unique<sf::Texture>();
    texture->loadFromFile("../textures/bluesquare.jpg", sf::IntRect(0, 0, entity->getXSize(), entity->getYSize()));

    sprite = std::make_unique<sf::Sprite>();
    sprite->setTexture(*texture);
    sprite->setOrigin(entity->getXSize()/2, entity->getYSize()/2);
}

void PentagonView::notify()
{
    sprite->setScale(static_cast<float>(entity->hitpoints)/maxHP, static_cast<float >(entity->hitpoints) /maxHP);
    sprite->setPosition(entity->getX(), entity->getY());
}

void PentagonView::draw(sf::RenderWindow &window) const
{
    window.draw(*sprite);
}