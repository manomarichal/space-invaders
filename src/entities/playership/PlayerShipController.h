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
#include "../Controller.h"

namespace entities::playership
{
    class PlayerShipController: public entities::Controller
    {
        std::shared_ptr<PlayerShip> object;
        std::shared_ptr<PlayerShipView> view;
    public:
        PlayerShipController(std::shared_ptr<PlayerShip> object, std::shared_ptr<PlayerShipView> view):object(object), view(view) {};
        void handleEvents() override ;
        ~PlayerShipController() override = default;
    };
}

#endif //SPACE_INVADERS_PLAYERSHIPCONTROLLER_H
