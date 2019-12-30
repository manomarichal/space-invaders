
/** \file PlayerLivesView.cpp
* project: space_invaders
* author: Mano Marichal
* date: 15.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */
/// description:


#include "PlayerLivesView.h"
using namespace entities::playership;

PlayerLivesView::PlayerLivesView(std::shared_ptr<PlayerShip> ship)
{
    this->entity = std::move(ship);
    
    font = std::make_unique<sf::Font>();
    font->loadFromFile("../resources/fonts/pixeled.ttf");

    string = std::make_unique<sf::Text>("Lives left: ", *font, 32 );
    string->setPosition(10, 10);
    string->setScale(util::Transformation::getScreenWidth()/1600, util::Transformation::getScreenHeight()/1200);

    texture = std::make_unique<sf::Texture>();
    texture->loadFromFile("../resources/textures/spaceship.png", sf::IntRect(0, 0, 64, 64));

    for (int k=0; k < std::dynamic_pointer_cast<PlayerShip>(entity)->hitpoints; k++)
    {
        lives.emplace_back(std::make_unique<sf::Sprite>());
        lives[k]->setTexture(*texture);
        lives[k]->setPosition((float(k)*50*(util::Transformation::getScreenWidth()/1600) +
                               string->getGlobalBounds().width) , 10);
        lives[k]->setScale((32.f / texture->getSize().x)*util::Transformation::getScreenWidth()/1600,
                string->getGlobalBounds().height/(lives[k]->getGlobalBounds().height * float(1.1 )));
    }
}

void PlayerLivesView::onNotify()
{
    if (std::dynamic_pointer_cast<PlayerShip>(entity)->hitpoints < float(lives.size())  )
    {
        lives.erase(lives.end());
    }
}

void PlayerLivesView::draw(sf::RenderWindow &window) const
{
    for (const auto &sprite:lives)
    {
        window.draw(*sprite);
    }
    window.draw(*string);
}