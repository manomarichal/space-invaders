// =====================================================================
// @name: PlayerHudView.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 15.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "PlayerHudView.h"
using namespace entities::playership;

PlayerHudView::PlayerHudView(std::shared_ptr<PlayerShip> ship)
{
    this->entity = std::move(ship);
    dynamic_cast<Subject*>(entity.get())->subscribe(dynamic_cast<Observer *>(this));

    sf::Font font;
    font.loadFromFile("../fonts/pixeled.ttf");
    //string = std::make_unique<sf::String>("Lives left: ", font, 30);
}

void PlayerHudView::notify()
{
}

void PlayerHudView::draw(sf::RenderWindow &window) const
{
    //window.draw(string);
}