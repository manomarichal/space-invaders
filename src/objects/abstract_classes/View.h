/** \file  View.h
* project: space_invaders
* author: Mano Marichal
* date: 01.12.19
*/

#ifndef SPACE_INVADERS_VIEW_H
#define SPACE_INVADERS_VIEW_H

#include <SFML/Graphics.hpp>

#include "./Entity.h"
#include "../../util/Transformation.h"

namespace objects
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
        /**
         * this function specifies what our view should draw each game interval, by default it is the view's sprite
         * @param window
         */
        virtual void draw(sf::RenderWindow &window) const;
        /**
         * function that initiates the view, meaning the view attaches to the objects entity
         */
        void init();
        ~View() override= default ;
    };
}
#endif //SPACE_INVADERS_VIEW_H
