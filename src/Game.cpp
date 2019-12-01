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
#include <assert.h>

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
    sf::RenderWindow window(sf::VideoMode(800, 600), "Space Invaders");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        for (auto &entity:entities)
        {
            entity->update(window);
        }

        // end the current frame
        window.display();
    }
}

Game::~Game()
{
    for (auto &entity:entities) delete entity;
}