/** \file PlayerShipController.h
 * project: space_invaders
 * author: Mano Marichal
 * date: 05.12.19
 * copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#ifndef SPACE_INVADERS_PLAYERSHIPCONTROLLER_H
#define SPACE_INVADERS_PLAYERSHIPCONTROLLER_H

#include "./PlayerShipView.h"

#include "../../util/Stopwatch.h"
#include "../abstract_classes/Controller.h"
#include "../projectiles/ProjectileFactory.h"

namespace objects::playership {
class PlayerShipController : public objects::Controller
{
        std::unique_ptr<util::Stopwatch> stopwatch;
        void createProjectile();

public:
        PlayerShipController(const std::shared_ptr<Entity>& entity, const std::shared_ptr<View>& view, World& world);
        bool handleEvents(const std::vector<std::shared_ptr<Entity>>& objects) override;
        ~PlayerShipController() override = default;
};
} // namespace objects::playership

#endif // SPACE_INVADERS_PLAYERSHIPCONTROLLER_H
