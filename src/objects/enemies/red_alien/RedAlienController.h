/** \file RedAlienController.h
* project: space_invaders
* author: Mano Marichal
* date: 12.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#ifndef SPACE_INVADERS_REDALIENCONTROLLER_H
#define SPACE_INVADERS_REDALIENCONTROLLER_H

#include "RedAlienView.h"
#include "../../abstract_classes/Controller.h"

namespace objects::enemies::red_alien
{
    class RedAlienController: public Controller
    {
    public:
        RedAlienController(const std::shared_ptr<Entity> &entity, const std::shared_ptr<View> &view, World &world)
                :Controller(world, entity, view) {};
        bool handleEvents(const std::vector<std::shared_ptr<Entity>> &objects) override ;
        ~RedAlienController() override = default;
    };
}

#endif //SPACE_INVADERS_REDALIENCONTROLLER_H
