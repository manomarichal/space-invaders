/** \file Controller.h
* project: space_invaders
* author: Mano Marichal
* date: 01.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#ifndef SPACE_INVADERS_CONTROLLER_H
#define SPACE_INVADERS_CONTROLLER_H

#include "../../util/Collision.h"
#include "./View.h"

class World;

namespace objects
{
    class Controller
        {
        protected:
            World &world;
            std::shared_ptr<Entity> entity;
            std::shared_ptr<View> view;

        public:
            /**
             * Constructor
             * @param world the world the controller belongs to
             * @param entity the entity of the object the controller belongs to
             * @param view the view of the object the controller belongs to
             */
            explicit Controller(World &world, std::shared_ptr<Entity> entity, std::shared_ptr<View> view):
            world(world), entity(std::move(entity)), view(std::move(view)) {};

            /**
             * this function specifies which action the controller should take each game interval
             * this can be for example check for collision or react to keyboard input
             * @param objects the other active objects in the world
             * @return this tells the owner if the entire object (entity, view and controller) should be destroyed at the end of this interval
             */
            virtual bool handleEvents(const std::vector<std::shared_ptr<Entity>> &objects)=0;

            virtual ~Controller()=0;
        };
        inline Controller::~Controller()=default;
}





#endif //SPACE_INVADERS_CONTROLLER_H
