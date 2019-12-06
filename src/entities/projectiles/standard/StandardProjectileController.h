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

#include "../../Controller.h"
#include "./StandardProjectileView.h"
namespace entities::projectiles
{
    class StandardProjectileController: public Controller
    {
        std::shared_ptr<StandardProjectile> object;
        std::shared_ptr<StandardProjectileView> view;
    public:
        StandardProjectileController(std::shared_ptr<StandardProjectile> object, std::shared_ptr<StandardProjectileView> view, Game* game): Controller(game), object(std::move(object)), view(std::move(view)) {};
    };
}

#endif //SPACE_INVADERS_STANDARDPROJECTILECONTROLLER_H
