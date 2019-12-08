// =====================================================================
// @name: Game.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 01.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "Game.h"

Game::Game()
{
    activeEntities.reserve(100);
    activeViews.reserve(100);
    activeControllers.reserve(100);

    auto ship = std::make_shared<entities::playership::PlayerShip>(300, 900);
    auto view = std::make_shared<entities::playership::PlayerShipView>(ship);
    auto controller = std::make_shared<entities::playership::PlayerShipController>(ship, view, this);

    addObject(std::make_tuple(std::move(ship), std::move(view), std::move(controller)));
}

void Game::addObject(entities::Object object)
{
    activeEntities.emplace_back(std::move(std::get<0>(object)));
    activeViews.emplace_back(std::move(std::get<1>(object)));
    activeControllers.emplace_back(std::move(std::get<2>(object)));
}

void Game::deleteObject(uint index)
{
    activeEntities.erase(activeEntities.begin() + index);
    activeViews.erase(activeViews.begin() + index);
    activeControllers.erase(activeControllers.begin() + index);
}
void Game::handleEvents()
{
    sf::Event event;
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                window->close();
                break;
            default:
                break;
        }
    }

    uint index = 0;

    while (index < activeControllers.size())
    {
        if (!activeControllers[index]->handleEvents()) deleteObject(index);
        else index++;
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

void Game::startGame()
{
    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(screensize::x, screensize::y), "Space Invaders");

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