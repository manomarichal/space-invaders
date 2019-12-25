// =====================================================================
// @name: Game.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 15.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "Game.h"

Game::Game(const std::string &settings)
{
    std::ifstream file(settings);
    if (!file.is_open()) throw std::runtime_error("could not open file: " + settings);
    nlohmann::json root;
    file >> root;

    float width = root["Screen"]["width"];
    float height = root["Screen"]["height"];
    for (const auto &level: root["Levels"])
    {
        levels.emplace_back(level);
    }

    util::Transformation::setScreenWidth(width);
    util::Transformation::setScreenHeight(height);

    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(width, height), "Space Invaders");

}

bool Game::gameOverScreen()
{
    sf::Font font;
    font.loadFromFile("../resources/fonts/pixeled.ttf");

    const float SCALE = util::Transformation::getScreenWidth()/1600;

    sf::Text string("GAME OVER", font, 64*SCALE);
    string.setPosition(float(window->getSize().x)/2, float(window->getSize().y)/2 - string.getGlobalBounds().height - 10);
    string.setOrigin(string.getGlobalBounds().width/2, string.getGlobalBounds().height/2);
    string.setScale(util::Transformation::getScreenWidth()/1600, util::Transformation::getScreenHeight()/1200);

    sf::Text string1("PRESS SPACE TO TRY AGAIN", font, 32*SCALE);
    string1.setPosition(float(window->getSize().x)/2, float(window->getSize().y)/2 + string1.getGlobalBounds().height + 10);
    string1.setOrigin(string1.getGlobalBounds().width/2, string1.getGlobalBounds().height/2);
    string1.setScale(util::Transformation::getScreenWidth()/1600, util::Transformation::getScreenHeight()/1200);

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

void Game::newLevelScreen()
{
    sf::Font font;
    font.loadFromFile("../resources/fonts/pixeled.ttf");

    const float SCALE = util::Transformation::getScreenWidth()/1600;

    sf::Text string("PRESS SPACE", font, 64*SCALE);
    string.setPosition(float(window->getSize().x)/2, float(window->getSize().y)/2 - string.getGlobalBounds().height);
    string.setOrigin(string.getGlobalBounds().width/2, string.getGlobalBounds().height/2);
    string.setScale(util::Transformation::getScreenWidth()/1600, util::Transformation::getScreenHeight()/1200);

    sf::Text string1("TO START", font, 64*SCALE);
    string1.setPosition(float(window->getSize().x)/2, float(window->getSize().y)/2 + string1.getGlobalBounds().height);
    string1.setOrigin(string1.getGlobalBounds().width/2, string1.getGlobalBounds().height/2);
    string1.setScale(util::Transformation::getScreenWidth()/1600, util::Transformation::getScreenHeight()/1200);

    window->draw(string);
    window->draw(string1);
    window->display();

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
    const double MS_PER_UPDATE = 16;

    double lag = 0;

    while (world.isRunning())
    {
        lag += util::Clock::update();

        while (lag >= MS_PER_UPDATE)
        {
            world.handleEvents();
            world.updateEntities();
            lag -= MS_PER_UPDATE;
        }

        world.drawViews();
    }
}
void Game::play()
{
    while (true)
    {
        auto world = std::make_shared<World>(window);

        for (const auto &level:levels)
        {
            newLevelScreen();
            world->loadLevel(level);
            Game::runWorld(*world);
            
            if (world->isLevelCompleted()) continue;
            else if (gameOverScreen()) break;
            else return;
        }
    }
}