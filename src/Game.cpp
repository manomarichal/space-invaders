// =====================================================================
// @name: Game.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 01.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "Game.h"
#include <iostream>

Game::Game()
{
    activeEntities.reserve(50);
    activeViews.reserve(50);
    activeControllers.reserve(50);
    objectsToDelete.reserve(50);

    auto ship = std::make_shared<entities::PlayerShip>(300, 900);
    auto view = std::make_shared<entities::PlayerShipView>(ship);
    auto controller = std::make_shared<entities::PlayerShipController>(ship, view, this);

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
    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(screensize::x, screensize::y), "Space Invaders");

    while (window->isOpen())
    {
        handleEvents();
        drawViews();
        system("sleep 0.016");
    }
}

void Game::readLevelFromFile(std::string filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) throw std::runtime_error("could not open file: " + filename);
    nlohmann::json root;
    file >> root;

    for (auto enemy:root["Enemies"])
    {
        if (enemy["type"] == "Hexagon")
        {
            auto projectile = std::make_shared<entities::enemies::Hexagon>(enemy["x"], enemy["y"]);
            auto view = std::make_shared<entities::enemies::HexagonView>(projectile);
            auto controller = std::make_shared<entities::enemies::HexagonController>(projectile, view, this);

            addObject(std::make_tuple(std::move(projectile), std::move(view), std::move(controller)));
        }
    }
}
Game::~Game()
{
}

const std::vector<std::shared_ptr<entities::Entity>> &Game::getActiveEntities() const
{
    return activeEntities;
}
