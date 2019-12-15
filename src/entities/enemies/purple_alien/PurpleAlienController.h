// =====================================================================
// @name: PurpleAlienController.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 08.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_PURPLEALIENCONTROLLER_H
#define SPACE_INVADERS_PURPLEALIENCONTROLLER_H

#include "PurpleAlienView.h"
#include "../../abstract_classes/Controller.h"
#include "../../projectiles/standard/StandardProjectile.h"

namespace entities::enemies::purple_alien
{
    class PurpleAlienController: public Controller
    {
    private:
        std::shared_ptr<PurpleAlien> entity;
        std::shared_ptr<PurpleAlienView> view;
    public:
        PurpleAlienController(std::shared_ptr<PurpleAlien> entity, std::shared_ptr<PurpleAlienView> view, World &world): Controller(world), entity(std::move(entity)), view(std::move(view)) {};
        bool handleEvents(const std::vector<std::shared_ptr<Entity>> &entities) override ;
        ~PurpleAlienController() override = default;
    };
}
#endif //SPACE_INVADERS_PURPLEALIENCONTROLLER_H
