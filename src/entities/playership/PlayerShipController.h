// =====================================================================
// @name: PlayerShipController.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 05.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_PLAYERSHIPCONTROLLER_H
#define SPACE_INVADERS_PLAYERSHIPCONTROLLER_H

#include "./PlayerShipView.h"

#include "../abstract_classes/Controller.h"
#include "../projectiles/ProjectileFactory.h"
#include "../../util/Stopwatch.h"
#include <utility>

namespace entities
{
    class PlayerShipController: public entities::Controller
    {
        std::shared_ptr<PlayerShip> entity;
        std::shared_ptr<PlayerShipView> view;
        std::unique_ptr<Stopwatch> stopwatch;
        void createProjectile();
    public:
        PlayerShipController(std::shared_ptr<PlayerShip> entity, std::shared_ptr<PlayerShipView> view, Game* game);
        bool handleEvents(const std::vector<std::shared_ptr<Entity>> &entities) override ;
        ~PlayerShipController() override = default;
    };
}

#endif //SPACE_INVADERS_PLAYERSHIPCONTROLLER_H
