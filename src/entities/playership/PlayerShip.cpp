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

// CONTROLLER 
PlayerShipController::PlayerShipController()
{
    // create the object and it's view
    view = new PlayerShipView();
    view->object = new PlayerShip;
    projectileController = new projectiles::ProjectileController;
}

void PlayerShipController::update(sf::RenderWindow &window)
{
    // move the player object
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) view->object ->moveLeft();

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) view->object ->moveRight();
    view->object ->move();

    // check if we are shooting and update all active projectiles
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        projectileController->createProjectile(view->object ->x, view->object ->y, projectiles::standard);
    projectileController->update(window);

    // draw the player object
    view->draw(window);
}

PlayerShipController::~PlayerShipController()
{
    delete view;
    delete projectileController;
}

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


