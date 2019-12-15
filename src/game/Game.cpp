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
    activeEntities.reserve(50);
    activeViews.reserve(50);
    activeControllers.reserve(50);
    objectsToDelete.reserve(50);
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

void Game::updateEntities()
{
    for (auto &entity:activeEntities)
    {
        entity->update();
    }
}

void Game::handleEvents()
{
    sf::Event event{};
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                gameIsRunning = false;
                window->close();
                break;
            default:
                break;
        }
    }

    uint index = 0;

    while (index < activeControllers.size())
    {
        if (!activeControllers[index]->handleEvents(activeEntities)) objectsToDelete.emplace_back(index);
        index++;
    }

    for (auto i:objectsToDelete)
    {
        deleteObject(i);
    }
    objectsToDelete.clear();
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
    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(entities::Transformation::getScreenWidth(), entities::Transformation::getScreenHeight()), "Space Invaders");
    Stopwatch stopwatch(8);

    while (gameIsRunning)
    {
        handleEvents();
        updateEntities();
        drawViews();
        while (!stopwatch.isReady()) {usleep(5000);};
    }
    window->close();
}

void Game::notify()
{
    gameIsRunning = player->hitpoints > 0;
}

Game::~Game()=default;

