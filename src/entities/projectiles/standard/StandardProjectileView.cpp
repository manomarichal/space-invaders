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

StandardProjectileView::StandardProjectileView(std::shared_ptr<StandardProjectile> &projectile)
{
    object = projectile;
    texture = std::make_unique<sf::Texture>();
    texture->loadFromFile("../textures/standardprojectile.jpg", sf::IntRect(0, 0, 8, 24));

    sprite = std::make_unique<sf::Sprite>();
    sprite->setTexture(*texture);
}

void StandardProjectileView::draw(sf::RenderWindow &window) const
{
    sprite->setPosition(object->x, object->y);
    window.draw(*sprite);
}