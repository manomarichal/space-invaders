// =====================================================================
// @name: Game.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 01.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "Game.h"

void Game::addObject(entities::Object object)
{
    activeEntities.emplace_back(std::move(std::get<0>(object)));
    activeViews.emplace_back(std::move(std::get<1>(object)));
    activeControllers.emplace_back(std::move(std::get<2>(object)));
}

void Game::eraseObject(entities::Object object)
{
    buffer.emplace_back(std::move(object));
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
        activeControllers[index]->handleEvents();
        index++;
    }

    // delete the objects
    for (auto object:buffer)
    {
        activeEntities.erase(std::find(activeEntities.begin(), activeEntities.end(), std::get<0>(object)));
        activeViews.erase(std::find(activeViews.begin(), activeViews.end(), std::get<1>(object)));
        activeControllers.erase(std::find(activeControllers.begin(), activeControllers.end(), std::get<2>(object)));
    }
    buffer.clear();
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
    auto ship = std::make_shared<entities::playership::PlayerShip>(300, 900);
    auto view = std::make_shared<entities::playership::PlayerShipView>(ship);

    activeEntities.emplace_back(ship);
    activeViews.emplace_back(view);
    activeControllers.emplace_back(std::make_shared<entities::playership::PlayerShipController>(ship, view, this));
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