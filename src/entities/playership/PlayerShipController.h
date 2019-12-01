// =====================================================================
// @name: PlayerShipController.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 01.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_PLAYERSHIPCONTROLLER_H
#define SPACE_INVADERS_PLAYERSHIPCONTROLLER_H

#include "./PlayerShipView.h"
#include "./PlayerShip.h"
#include "../Controller.h"

class PlayerShipController: public Controller
{
    PlayerShipView* view;
    PlayerShip *object;
public:
    PlayerShipController();

    void update(sf::RenderWindow &window) override ;

    ~PlayerShipController() override;
};

#endif //SPACE_INVADERS_PLAYERSHIPCONTROLLER_H
