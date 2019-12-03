// =====================================================================
// @name: PlayerShip.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 01.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "PlayerShip.h"
#include "../../settings/screensize.h"
using namespace entities;

PlayerShip::PlayerShip()
{
    x = screensize::x/2;
    y = screensize::y-(screensize::y/10);
}
void PlayerShip::moveLeft()
{
    if (vx > 0) vx = 0;
    vx -= ax;
    vx *= friction;

    if (vx < -max_v) vx = -max_v;
}

void PlayerShip::moveRight()
{
    if (vx < 0) vx = 0;

    vx *= friction;
    vx += ax;

    if (vx > max_v) vx = max_v;
}

void PlayerShip::move()
{
    vx *= friction;
    x += vx;

    if (x < 0) x = 0;
    if (x + xSize> screensize::x) x = screensize::x-xSize;
}

PlayerShip::~PlayerShip()=default;

// VIEW
PlayerShipView::PlayerShipView(PlayerShip* ship)
{
    object = ship;
    
    texture = new sf::Texture();
    texture->loadFromFile("../textures/playershipstill.jpg", sf::IntRect(0, 0, 64, 64));

    sprite = new sf::Sprite;
    sprite->setTexture(*texture);
}
void PlayerShipView::draw(sf::RenderWindow &window) const
{
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

    sprite->setPosition(object->x, object->y);
    window.draw(*sprite);
};

PlayerShipView::~PlayerShipView()
{
    delete object;
    delete sprite;
    delete texture;
}

// CONTROLLER 
PlayerShipController::PlayerShipController()
{
    // create the view->object and it's view
    object = new PlayerShip();
    view = new PlayerShipView(object);
    projectileController = new entities::projectiles::ProjectileController;
}

void PlayerShipController::update()
{
    // move the player view->object
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        object ->moveLeft();
        view->currentSprite = view->left;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        object ->moveRight();
        view->currentSprite = view->right;
    }
    else view->currentSprite = view->idle;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        projectileController->createProjectile(object->x,object->y, projectiles::standard);
    }
    object ->move();
    projectileController->update();
}

void PlayerShipController::draw(sf::RenderWindow &window)
{
    view->draw(window);
    projectileController->draw(window);
}

PlayerShipController::~PlayerShipController()
{
    delete view;
    delete projectileController;
}