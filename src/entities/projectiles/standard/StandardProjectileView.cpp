// =====================================================================
// @name: StandardProjectileView.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 06.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "StandardProjectileView.h"
using namespace entities::projectiles;

StandardProjectileView::StandardProjectileView(std::shared_ptr<StandardProjectile> projectile)
{
    entity = std::move(projectile);
    entity->subscribe(this);
    texture = std::make_unique<sf::Texture>();
    texture->loadFromFile("../textures/standardprojectile.png", sf::IntRect(0, 0, 8, 24));

    sprite = std::make_unique<sf::Sprite>();
    sprite->setTexture(*texture);
    sprite->setOrigin(entity->getXSize()/2, entity->getYSize()/2);
}

void StandardProjectileView::notify()
{
    sprite->setPosition(entity->getX(), entity->getY());
}

void StandardProjectileView::draw(sf::RenderWindow &window) const
{
    window.draw(*sprite);
}