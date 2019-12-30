
/** \file  View.h
* project: space_invaders
* author: Mano Marichal
* date: 01.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */
/// description:


#ifndef SPACE_INVADERS_VIEW_H
#define SPACE_INVADERS_VIEW_H

#include <SFML/Graphics.hpp>
#include <memory>

#include "./Entity.h"
#include "../../util/Transformation.h"

namespace entities
{
class View: public Observer
    {
    protected:
        View()=default;
        View(const std::string& image, std::shared_ptr<Entity> sharedPtr);
        std::shared_ptr<Entity> entity;
        std::unique_ptr<sf::Sprite> sprite;
        std::unique_ptr<sf::Texture> texture;
        bool initialized = false;
    public:
        virtual void draw(sf::RenderWindow &window) const;
        void init();
        ~View() override= default ;
    };
}
#endif //SPACE_INVADERS_VIEW_H
