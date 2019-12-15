// =====================================================================
// @name: StandardEnemyProjectileController.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 11.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_STANDARDENEMYPROJECTILECONTROLLER_H
#define SPACE_INVADERS_STANDARDENEMYPROJECTILECONTROLLER_H

#include "../../abstract_classes/Controller.h"
#include "../../enemies/Enemy.h"
#include "../../playership/PlayerShip.h"
#include "./StandardEnemyProjectileView.h"


namespace entities::projectiles::standard_enemy
{
    class StandardEnemyProjectileController: public Controller
    {
        std::shared_ptr<StandardEnemyProjectile> entity;
        std::shared_ptr<StandardEnemyProjectileView> view;
    public:
        StandardEnemyProjectileController(std::shared_ptr<StandardEnemyProjectile> entity, std::shared_ptr<StandardEnemyProjectileView> view, World &world): Controller(world), entity(std::move(entity)), view(std::move(view)) {};
        bool handleEvents(const std::vector<std::shared_ptr<Entity>> &entities) override;
        ~StandardEnemyProjectileController() override = default;
    };
}


#endif //SPACE_INVADERS_STANDARDENEMYPROJECTILECONTROLLER_H
