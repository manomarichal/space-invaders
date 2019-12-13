// =====================================================================
// @name: RedAlienController.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 12.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_REDALIENCONTROLLER_H
#define SPACE_INVADERS_REDALIENCONTROLLER_H

#include "RedAlienView.h"
#include "../../abstract_classes/Controller.h"
#include "../../projectiles/standard/StandardProjectile.h"

namespace entities::enemies::red_alien
{
    class RedAlienController: public Controller
    {
    private:
        std::shared_ptr<RedAlien> entity;
        std::shared_ptr<RedAlienView> view;
    public:
        RedAlienController(std::shared_ptr<RedAlien> entity, std::shared_ptr<RedAlienView> view, Game &game): Controller(game), entity(std::move(entity)), view(std::move(view)) {};
        bool handleEvents(const std::vector<std::shared_ptr<Entity>> &entities) override ;
        ~RedAlienController() override = default;
    };
}

#endif //SPACE_INVADERS_REDALIENCONTROLLER_H
