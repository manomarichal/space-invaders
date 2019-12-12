// =====================================================================
// @name: View.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 01.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_VIEW_H
#define SPACE_INVADERS_VIEW_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "./Entity.h"

namespace entities
{
    class View
    {
    protected:

        std::shared_ptr<Entity> entity;
        std::unique_ptr<sf::Sprite> sprite;
        std::unique_ptr<sf::Texture> texture;

        View(std::string image, std::shared_ptr<Entity> sharedPtr)
        {
            this->entity = std::move(sharedPtr);

            texture = std::make_unique<sf::Texture>();
            texture->loadFromFile(image, sf::IntRect(0, 0, entity->getXSize(), entity->getYSize()));
            sprite = std::make_unique<sf::Sprite>();
            sprite->setTexture(*texture);
            sprite->setOrigin(entity->getXSize()/2, entity->getYSize()/2);
        }
    public:
        virtual void draw(sf::RenderWindow &window) const
        {
            window.draw(*sprite);
        };
        virtual ~View()=0;
    };
    inline View::~View()=default;
}
#endif //SPACE_INVADERS_VIEW_H
