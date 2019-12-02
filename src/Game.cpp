// =====================================================================
// @name: Game.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 01.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "Game.h"
#include "entities/playership/PlayerShipController.h"
#include <cassert>
#include "./settings/screensize.h"

void Game::drawEntities()
{
    for (auto &entity:entities)
    {
        entity->update(*window);
    }
}

void Game::handleEvents()
{
    sf::Event event;
    while (window->pollEvent(event))
    {
        // check the type of the event...
        switch (event.type)
        {
            case sf::Event::Closed:
                window->close();
                break;
            default:
                return;
        }
    }
}
void Game::initializeGame()
{
    isInitialized = true;
    Controller* ship = new PlayerShipController();
    entities.emplace_back(ship);
}


void Game::startGame()
{
    assert(isInitialized);

    // create the window
    sf::RenderWindow newWindow(sf::VideoMode(screensize::x, screensize::y), "Space Invaders");

    window = &newWindow;

    // run the program as long as the window is open
    while (window->isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        handleEvents();

        // clear the window with black color
        window->clear(sf::Color::Black);

        // draw everything here...
        drawEntities();

        system("sleep 0.016");
        // end the current frame
        window->display();
    }
}

Game::~Game()
{
    for (auto &entity:entities) delete entity;
}