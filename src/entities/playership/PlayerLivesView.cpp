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
    dynamic_cast<Subject*>(entity.get())->subscribe(dynamic_cast<Observer *>(this));

    font = std::make_unique<sf::Font>();
    font->loadFromFile("../resources/fonts/pixeled.ttf");
    string = std::make_unique<sf::Text>("Lives left: ", *font, 32);
    string->setPosition(10, 10);

    texture = std::make_unique<sf::Texture>();
    texture->loadFromFile("../resources/textures/spaceship.png", sf::IntRect(0, 0, 64, 64));

    for (int k=0; k < dynamic_cast<PlayerShip*>(entity.get())->hitpoints; k++)
    {
        lives.emplace_back(std::make_unique<sf::Sprite>());
        lives[k]->setTexture(*texture);
        lives[k]->setPosition(k*50 + string->getCharacterSize()*10 - 4 , 10);
        lives[k]->setScale(0.6, 0.6);
    }
}

void PlayerLivesView::onNotify()
{
    if (dynamic_cast<PlayerShip*>(entity.get())->hitpoints < int(lives.size())  )
    {
        lives.erase(lives.end());
    }
}

void PlayerLivesView::draw(sf::RenderWindow &window) const
{
    for (const auto &sprite:lives)
    {
        window.draw(util::Transformation::transform<sf::Sprite>(*sprite));
    }
    window.draw(util::Transformation::transform<sf::Text>(*string));
}