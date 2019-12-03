// =====================================================================
// @name: StandardProjectile.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 03.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "StandardProjectile.h"
using namespace entities::projectiles;

bool StandardProjectile::move()
{
    y -= vspeed;
    return y < 0;
}

StandardProjectileView::StandardProjectileView(entities::projectiles::StandardProjectile *projectile)
{
    this->projectile = projectile;

    texture = new sf::Texture();
    texture->loadFromFile("../textures/standardprojectile.png", sf::IntRect(0, 0, 10, 20));

    sprite = new sf::Sprite;
    sprite->setTexture(*texture);
}

void StandardProjectileView::draw(sf::RenderWindow &window) const
{
    sprite->setPosition(projectile->getX(), projectile->getY());
    window.draw(*sprite);
}

StandardProjectileView::~StandardProjectileView()
{
    delete projectile;
}