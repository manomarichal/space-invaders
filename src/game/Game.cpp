// =====================================================================
// name: Game.cpp
// project: space_invaders
// author: Mano Marichal
// date: 15.12.19
// copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// description:
// =====================================================================

#include "Game.h"
#include "../json/json.hpp"
#include <fstream>

Game::Game(const std::string &settings)
{
    std::ifstream file(settings);
    if (!file.is_open()) throw std::runtime_error("could not open file: " + settings);
    nlohmann::json root;
    file >> root;

    // READ IN THE SCREENSIZE
    float width = root["Screen"]["width"];
    float height = root["Screen"]["height"];
    util::Transformation::setScreenWidth(width);
    util::Transformation::setScreenHeight(height);

    // READ IN ALL LEVELS
    for (const auto &level: root["Levels"])
    {
        levels.emplace_back(level);
    }

    // CREATE THE WINDOW WE ARE GOING TO PLAY IN
    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(static_cast<unsigned int>(width),
                                                              static_cast<unsigned int>(height)), "Space Invaders");

}

bool Game::gameOverScreen()
{
    sf::Font font;
    font.loadFromFile("../resources/fonts/pixeled.ttf");

    const float SCALE = util::Transformation::getScreenWidth()/1600;

    sf::Text string("GAME OVER", font, static_cast<unsigned int>(64 * SCALE));
    string.setPosition(float(window->getSize().x)/2, float(window->getSize().y)/2 - string.getGlobalBounds().height - 10);
    string.setOrigin(string.getGlobalBounds().width/2, string.getGlobalBounds().height/2);
    string.setScale(util::Transformation::getScreenWidth()/1600, util::Transformation::getScreenHeight()/1200);

    sf::Text string1("PRESS SPACE TO TRY AGAIN", font, static_cast<unsigned int>(32 * SCALE));
    string1.setPosition(float(window->getSize().x)/2, float(window->getSize().y)/2 + string1.getGlobalBounds().height + 10);
    string1.setOrigin(string1.getGlobalBounds().width/2, string1.getGlobalBounds().height/2);
    string1.setScale(util::Transformation::getScreenWidth()/1600, util::Transformation::getScreenHeight()/1200);

    window->draw(string);
    window->draw(string1);
    window->display();

    /// we pause the game as long as the player does not press pause
    while(true)
    {
        checkEvents();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            return true;
        }
        //else system("sleep 1");
    }
}

void Game::newLevelScreen()
{
    sf::Font font;
    font.loadFromFile("../resources/fonts/pixeled.ttf");

    const float SCALE = util::Transformation::getScreenWidth()/1600;

    sf::Text string("PRESS SPACE", font, static_cast<unsigned int>(64 * SCALE));
    string.setPosition(float(window->getSize().x)/2, float(window->getSize().y)/2 - string.getGlobalBounds().height);
    string.setOrigin(string.getGlobalBounds().width/2, string.getGlobalBounds().height/2);
    string.setScale(util::Transformation::getScreenWidth()/1600, util::Transformation::getScreenHeight()/1200);

    sf::Text string1("TO START", font, static_cast<unsigned int>(64 * SCALE));
    string1.setPosition(float(window->getSize().x)/2, float(window->getSize().y)/2 + string1.getGlobalBounds().height);
    string1.setOrigin(string1.getGlobalBounds().width/2, string1.getGlobalBounds().height/2);
    string1.setScale(util::Transformation::getScreenWidth()/1600, util::Transformation::getScreenHeight()/1200);

    window->draw(string);
    window->draw(string1);
    window->display();

    // we pause the game until the player presses space
    while(true)
    {
        checkEvents();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            return;
        }
        //else system("sleep 10");
    }
}


void Game::checkEvents()
{
    sf::Event event{};
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed) exit(0);
    }
}

void Game::runWorld(World &world)
{
    // the amount of milliseconds we want a frame to last
    const double MS_PER_UPDATE = 16;
    // the amount of lag we are having
    double lag = 0;
    while (world.isRunning())
    {
        lag += util::Clock::update();
        // whenever we have lag, we want to update our gamelogic multiple times before we update the graphical part
        while (lag >= MS_PER_UPDATE)
        {
            // update game logic and descrease lag
            world.handleEvents();
            world.updateEntities();
            lag -= MS_PER_UPDATE;
        }
        // update graphical part of the world
        world.drawViews();
    }
}
void Game::play()
{
    // we create a world objects to load our levels in
    auto world = std::make_shared<World>(window);

    while (true)
    {
        for (const auto &level:levels)
        {
            newLevelScreen();           // make new level screen
            world->loadLevel(level);    // load the level in our world
            Game::runWorld(*world);  // run the world
            
            if (world->isLevelCompleted()) continue;
            else if (gameOverScreen()) break;
            else return;
        }
    }
}