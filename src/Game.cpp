// =====================================================================
// @name: Game.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 01.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "Game.h"
#include <cassert>
#include "./settings/screensize.h"

void Game::handleEvents()
{
    for (auto &controller:activeControllers)
    {
        controller->handleEvents();
    }
}

void Game::updateEntities()
{
    for (auto &entity:activeEntities)
    {
        entity->update();
    }
}
void Game::drawViews()
{
    window->clear(sf::Color::Black);
    for (auto &view:activeViews)
    {
        view->draw(*window);
    }
    window->display();

}

void Game::initializeGame()
{
    isInitialized = true;
    auto ship = std::make_shared<entities::playership::PlayerShip>(this);
    auto view = std::make_shared<entities::playership::PlayerShipView>(ship);

    activeEntities.emplace_back(ship);
    activeViews.emplace_back(view);
    activeControllers.emplace_back(std::make_shared<entities::playership::PlayerShipController>(ship, view));

}


void Game::startGame()
{
    assert(isInitialized);

    // create the window
    sf::RenderWindow newWindow(sf::VideoMode(screensize::x, screensize::y), "Space Invaders");

    window = &newWindow;
    while (window->isOpen())
    {
        handleEvents();
        updateEntities();
        drawViews();
        system("sleep 0.016");
    }
}

Game::~Game()
{
}