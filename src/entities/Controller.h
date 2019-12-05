// =====================================================================
// @name: Controller.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 01.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_CONTROLLER_H
#define SPACE_INVADERS_CONTROLLER_H

#include <SFML/Graphics.hpp>

namespace entities
{
    class Controller
    {
    public:
        virtual void handleEvents()=0;
        virtual ~Controller()=0;
    };
    inline Controller::~Controller() { }
}
#endif //SPACE_INVADERS_CONTROLLER_H
