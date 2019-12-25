// =====================================================================
// @name: PlayerLivesView.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 15.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "PlayerLivesView.h"
using namespace entities::playership;

PlayerLivesView::PlayerLivesView(std::shared_ptr<PlayerShip> ship)
{
    this->entity = std::move(ship);

    const float SCALE = util::Transformation::getScreenWidth()/1600;

    font = std::make_unique<sf::Font>();
    font->loadFromFile("../resources/fonts/pixeled.ttf");
    string = std::make_unique<sf::Text>("Lives left: ", *font, 32 * SCALE);
    string->setPosition(10*SCALE, 10*SCALE);

    texture = std::make_unique<sf::Texture>();
    texture->loadFromFile("../resources/textures/spaceship.png", sf::IntRect(0, 0, 64, 64));

    for (int k=0; k < std::dynamic_pointer_cast<PlayerShip>(entity)->hitpoints; k++)
    {
        lives.emplace_back(std::make_unique<sf::Sprite>());
        lives[k]->setTexture(*texture);
        lives[k]->setPosition(float((k*50 + string->getCharacterSize()*10 - 4))*SCALE , 10*SCALE);
        lives[k]->setScale(0.6, 0.6);
    }
}

void PlayerLivesView::onNotify()
{
    if (std::dynamic_pointer_cast<PlayerShip>(entity)->hitpoints < int(lives.size())  )
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