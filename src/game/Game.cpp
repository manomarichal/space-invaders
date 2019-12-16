// =====================================================================
// @name: Game.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 15.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "Game.h"

Game::Game(const std::string &settings, std::vector<std::string> levels)
{
    this->levels = std::move(levels);
    std::ifstream file(settings);
    if (!file.is_open()) throw std::runtime_error("could not open file: " + settings);
    nlohmann::json root;
    file >> root;

    uint width = root["Screen"]["width"];
    uint height = root["Screen"]["height"];
    entities::Transformation::setScreenWidth(width);
    entities::Transformation::setScreenHeight(height);

    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(width, height), "Space Invaders");

}

bool Game::gameOver()
{
    sf::Font font;
    font.loadFromFile("../fonts/pixeled.ttf");

    sf::Text string("GAME OVER", font, 128);
    string.setPosition(float(entities::Transformation::getScreenWidth())/2, float(entities::Transformation::getScreenHeight())/2 - string.getGlobalBounds().height - 10);
    string.setOrigin(string.getGlobalBounds().width/2, string.getGlobalBounds().height/2);
    
    sf::Text string1("PRESS SPACE TO TRY AGAIN", font, 64);
    string1.setPosition(float(entities::Transformation::getScreenWidth())/2, float(entities::Transformation::getScreenHeight())/2 + string1.getGlobalBounds().height + 10);
    string1.setOrigin(string1.getGlobalBounds().width/2, string1.getGlobalBounds().height/2);

    window->draw(string);
    window->draw(string1);
    window->display();

    while(true)
    {
        checkEvents();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            return true;
        }
        //else system("sleep 10");
    }
}

void Game::newLevel()
{
}


void Game::checkEvents()
{
    sf::Event event{};
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed) exit(0);
    }
}

void Game::play()
{
    while (true)
    {
        for (const auto &level:levels)
        {
            World world(level, window);
            if (world.play()) continue;
            else if (gameOver()) break;
            else return;
        }
    }
}