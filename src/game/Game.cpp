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
#include <SFML/Audio.hpp>

Game::Game(const std::string& settings)
{
        std::ifstream file(settings);
        if (!file.is_open())
                throw std::runtime_error("could not open file: " + settings);
        nlohmann::json root;
        file >> root;

        // READ IN THE SCREENSIZE
        float width = root["Screen"]["width"];
        float height = root["Screen"]["height"];
        util::Transformation::setScreenWidth(width);
        util::Transformation::setScreenHeight(height);

        // READ IN ALL LEVELS
        for (const auto& level : root["Levels"]) {
                levels.emplace_back(level);
        }
        if (levels.empty())
                throw std::runtime_error("Please specify the levels you want to play in the settings file");

        // CREATE THE WINDOW WE ARE GOING TO PLAY IN
        window = std::make_unique<sf::RenderWindow>(
            sf::VideoMode(static_cast<unsigned int>(width), static_cast<unsigned int>(height)), "Space Invaders");
}

void Game::checkEvents()
{
        sf::Event event{};
        while (window->pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                        exit(0);
        }
}

void Game::runWorld(World& world)
{
        // the amount of milliseconds we want a frame to last
        const double MS_PER_UPDATE = 16;
        // the amount of lag we are having
        double lag = 0;
        while (world.isRunning()) {
                lag += util::Clock::update();
                // whenever we have lag, we want to update our gamelogic multiple times before we update the graphical
                // part
                while (lag >= MS_PER_UPDATE) {
                        // update game logic and descrease lag
                        world.handleEvents();
                        world.updateEntities();
                        lag -= MS_PER_UPDATE;
                }
                // update graphical part of the world
                world.drawViews();
        }
}
void Game::playLevels()
{
        // load the music
        sf::SoundBuffer buffer;
        if (!buffer.loadFromFile("./resources/music/theme.wav"))
            throw std::runtime_error("could not open file: ./resources/mucis/theme.wav");
        sf::Sound theme;
        theme.setBuffer(buffer);
        theme.play();

        // we create a world objects to load our levels in
        auto world = std::make_shared<World>(window);
        unsigned int levelsCompleted = 0;

        // play all the levels
        while (levelsCompleted < levels.size()) {
                for (const auto& level : levels) {
                        newLevelScreen();        // make new level screen
                        world->loadLevel(level); // load the level in our world
                        Game::runWorld(*world);  // run the world

                        if (world->isLevelCompleted())
                                levelsCompleted++; // if the level is completed go to the next level
                        else if (gameOverScreen()) {
                                levelsCompleted = 0;
                                break; // else display the game over screen
                        } else
                                return;
                }
        }
        // enter endless mode
        endlessScreen();
        world->enterEndless();
        runWorld(*world);
}
