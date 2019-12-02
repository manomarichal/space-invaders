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

void Game::updateControllers()
{
    for (auto &controller:controllers)
    {
        controller->update();
    }
}

void Game::drawViews()
{
    for (auto &controller:controllers)
    {
        controller->draw(*window);
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
    Controller* ship = new entities::PlayerShipController();
    controllers.emplace_back(ship);
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

        updateControllers();
        drawViews();
        // draw everything here...

        system("sleep 0.016");
        // end the current frame
        window->display();
    }
}

Game::~Game()
{
    for (auto &controller:controllers) delete controller;
}