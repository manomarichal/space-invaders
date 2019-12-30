
/** \file Controller.h
* project: space_invaders
* author: Mano Marichal
* date: 01.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */
/// description:


#ifndef SPACE_INVADERS_CONTROLLER_H
#define SPACE_INVADERS_CONTROLLER_H

#include <SFML/Graphics.hpp>

#include "../../util/Collision.h"
#include "./View.h"

class World;

namespace entities
{
    class Controller
        {
        protected:
            World &world;
            std::shared_ptr<Entity> entity;
            std::shared_ptr<View> view;

        public:
            explicit Controller(World &world, std::shared_ptr<Entity> entity, std::shared_ptr<View> view):
            world(world), entity(std::move(entity)), view(std::move(view)) {};

            virtual bool handleEvents(const std::vector<std::shared_ptr<Entity>> &entities)=0;

            virtual ~Controller()=0;
        };
        inline Controller::~Controller()=default;
}





#endif //SPACE_INVADERS_CONTROLLER_H
