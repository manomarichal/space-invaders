// =====================================================================
// @name: StandardProjectileController.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 06.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_STANDARDPROJECTILECONTROLLER_H
#define SPACE_INVADERS_STANDARDPROJECTILECONTROLLER_H

#include "../../abstract_classes/Controller.h"
#include "../../enemies/Enemy.h"
#include "./StandardProjectileView.h"

namespace entities::projectiles::standard
{
    class StandardProjectileController: public Controller
    {
        std::shared_ptr<StandardProjectile> entity;
        std::shared_ptr<StandardProjectileView> view;
    public:
        StandardProjectileController(std::shared_ptr<StandardProjectile> entity, std::shared_ptr<StandardProjectileView> view, Game* game): Controller(game), entity(std::move(entity)), view(std::move(view)) {};
        bool handleEvents(const std::vector<std::shared_ptr<Entity>> &entities) override;
        ~StandardProjectileController() override = default;
    };
}

#endif //SPACE_INVADERS_STANDARDPROJECTILECONTROLLER_H
