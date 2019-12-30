/** \file WorldGraphics.cpp
* project: space_invaders
* author: Mano Marichal
* date: 27.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#include "World.h"

void World::drawViews()
{
    window->clear(sf::Color::Black);
    for (auto &view:activeViews)
    {
        view->draw(*window);
    }
    drawScore();
    window->display();

}

void World::drawScore()
{
    sf::Font font;
    font.loadFromFile("../resources/fonts/pixeled.ttf");

    sf::Text string("Score: " + std::to_string(score), font, 32);
    string.setScale(util::Transformation::getScreenWidth()/1600, util::Transformation::getScreenHeight()/1200);
    string.setPosition(util::Transformation::getScreenWidth() - string.getGlobalBounds().width - 10, 10);

    window->draw(string);
}