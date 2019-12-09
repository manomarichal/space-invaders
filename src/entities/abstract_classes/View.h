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

namespace entities
{
    class View
    {
    public:
        virtual void draw(sf::RenderWindow &window) const =0;
        virtual ~View()=0;
    };
    inline View::~View()=default;
}
#endif //SPACE_INVADERS_VIEW_H