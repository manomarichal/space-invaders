// =====================================================================
// @name: GameScreens.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 01.01.20
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description:
// =====================================================================

#include "Game.h"

bool Game::gameOverScreen()
{
        sf::Font font;
        font.loadFromFile("./resources/fonts/pixeled.ttf");

        const float SCALE = util::Transformation::getScreenWidth() / 1600;

        sf::Text string("GAME OVER", font, static_cast<unsigned int>(64 * SCALE));
        string.setPosition(float(window->getSize().x) / 2,
                           float(window->getSize().y) / 2 - string.getGlobalBounds().height);
        string.setOrigin(string.getGlobalBounds().width / 2, string.getGlobalBounds().height / 2);
        string.setScale(util::Transformation::getScreenWidth() / 1600, util::Transformation::getScreenHeight() / 1200);

        sf::Text string1("PRESS SPACE TO TRY AGAIN", font, static_cast<unsigned int>(64 * SCALE));
        string1.setPosition(float(window->getSize().x) / 2,
                            float(window->getSize().y) / 2 + string1.getGlobalBounds().height);
        string1.setOrigin(string1.getGlobalBounds().width / 2, string1.getGlobalBounds().height / 2);
        string1.setScale(util::Transformation::getScreenWidth() / 1600, util::Transformation::getScreenHeight() / 1200);

        window->draw(string);
        window->draw(string1);
        window->display();

        /// we pause the game as long as the player does not press pause
        bool pressed = true;
        // we pause the game until the player presses space
        while (true) {
                checkEvents();
                if (not sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                        pressed = false;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and not pressed) {
                        return true;
                }
                // else system("sleep 10");
        }
}

void Game::newLevelScreen()
{
        window->clear(sf::Color::Black);
        sf::Font font;
        font.loadFromFile("./resources/fonts/pixeled.ttf");

        const float SCALE = util::Transformation::getScreenWidth() / 1600;

        sf::Text string("PRESS SPACE", font, static_cast<unsigned int>(64 * SCALE));
        string.setPosition(float(window->getSize().x) / 2,
                           float(window->getSize().y) / 2 - string.getGlobalBounds().height);
        string.setOrigin(string.getGlobalBounds().width / 2, string.getGlobalBounds().height / 2);
        string.setScale(util::Transformation::getScreenWidth() / 1600, util::Transformation::getScreenHeight() / 1200);

        sf::Text string1("TO START", font, static_cast<unsigned int>(64 * SCALE));
        string1.setPosition(float(window->getSize().x) / 2,
                            float(window->getSize().y) / 2 + string1.getGlobalBounds().height);
        string1.setOrigin(string1.getGlobalBounds().width / 2, string1.getGlobalBounds().height / 2);
        string1.setScale(util::Transformation::getScreenWidth() / 1600, util::Transformation::getScreenHeight() / 1200);

        window->draw(string);
        window->draw(string1);
        window->display();

        bool pressed = true;
        // we pause the game until the player presses space
        while (true) {
                checkEvents();
                if (not sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                        pressed = false;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and not pressed) {
                        return;
                }
                // else system("sleep 10");
        }
}

void Game::endlessScreen()
{
        sf::Font font;
        font.loadFromFile("./resources/fonts/pixeled.ttf");

        const float SCALE = util::Transformation::getScreenWidth() / 1600;

        sf::Text string("ENTERING ENDLESS MODE", font, static_cast<unsigned int>(64 * SCALE));
        string.setPosition(float(window->getSize().x) / 2,
                           float(window->getSize().y) / 2 - string.getGlobalBounds().height);
        string.setOrigin(string.getGlobalBounds().width / 2, string.getGlobalBounds().height / 2);
        string.setScale(util::Transformation::getScreenWidth() / 1600, util::Transformation::getScreenHeight() / 1200);

        sf::Text string1("PRESS SPACE TO START", font, static_cast<unsigned int>(64 * SCALE));
        string1.setPosition(float(window->getSize().x) / 2,
                            float(window->getSize().y) / 2 + string1.getGlobalBounds().height);
        string1.setOrigin(string1.getGlobalBounds().width / 2, string1.getGlobalBounds().height / 2);
        string1.setScale(util::Transformation::getScreenWidth() / 1600, util::Transformation::getScreenHeight() / 1200);

        window->draw(string);
        window->draw(string1);
        window->display();

        bool pressed = true;
        // we pause the game until the player presses space
        while (true) {
                checkEvents();
                if (not sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                        pressed = false;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and not pressed) {
                        return;
                }
                // else system("sleep 10");
        }
}