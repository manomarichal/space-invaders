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
}

void View::init()
{
    initialized = true;
    std::dynamic_pointer_cast<Subject>(entity)->attach(shared_from_this());
}
void View::draw(sf::RenderWindow &window) const
{
    if (!initialized) throw std::runtime_error("View object must be attached to an entity before calling draw");
    window.draw(util::Transformation::transform<sf::Sprite>(*sprite));
}

