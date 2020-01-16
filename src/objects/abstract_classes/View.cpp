/** \file View.cpp
 * project: space_invaders
 * author: Mano Marichal
 * date: 13.12.19
 */

#include "./View.h"

using namespace objects;

View::View(const std::string& image, std::shared_ptr<Entity> sharedPtr)
{
        this->entity = std::move(sharedPtr);

        texture = std::make_unique<sf::Texture>();
        texture->loadFromFile(image);

        sprite = std::make_unique<sf::Sprite>();
        sprite->setTexture(*texture);
        sprite->setScale(entity->getXSize() / texture->getSize().x, entity->getYSize() / texture->getSize().y);
        sprite->setOrigin(float(texture->getSize().x) / 2, (float(texture->getSize().x)) / 2);
}

void View::init()
{
        initialized = true;
        std::dynamic_pointer_cast<Subject>(entity)->attach(shared_from_this());
}
void View::draw(sf::RenderWindow& window) const
{
        if (!initialized)
                throw std::runtime_error("View objects must be attached to an entity before calling draw");
        window.draw(util::Transformation::transform<sf::Sprite>(*sprite));
}
