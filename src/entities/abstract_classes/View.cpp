// =====================================================================
// @name: View.cpp
// @project: space_invaders
// @author: Mano Marichal
// @date: 13.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#include "./View.h"
using namespace entities;

View::View(const std::string& image, std::shared_ptr<Entity> sharedPtr)
{
    this->entity = std::move(sharedPtr);

    texture = std::make_unique<sf::Texture>();
    texture->loadFromFile(image, sf::IntRect(0, 0, entity->getXSize(), entity->getYSize()));

    sprite = std::make_unique<sf::Sprite>();
    sprite->setTexture(*texture);
    sprite->setOrigin(entity->getXSize()/2, entity->getYSize()/2);

    dynamic_cast<Subject*>(entity.get())->subscribe(dynamic_cast<Observer *>(this));
}

void View::draw(sf::RenderWindow &window) const
{
    sf::Sprite temp = *sprite;
    temp.setPosition(Transformation::getXPixelValue(temp.getPosition().x),
                     Transformation::getYPixelValue(temp.getPosition().y));
    temp.setScale(Transformation::getXScale() * sprite->getScale().x,
                  Transformation::getYScale() * sprite->getScale().y);
    window.draw(temp);
}