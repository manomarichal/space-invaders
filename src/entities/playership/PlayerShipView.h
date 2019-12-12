// =====================================================================
// @name: PlayerShipView.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 05.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_PLAYERSHIPVIEW_H
#define SPACE_INVADERS_PLAYERSHIPVIEW_H

#include "./PlayerShip.h"
#include "../abstract_classes/View.h"
#include "../abstract_classes/Observer.h"

namespace entities::playership
{
    class PlayerShipView: public entities::View, public entities::Observer
    {
    public:

        explicit PlayerShipView(std::shared_ptr<PlayerShip> ship);

        void notify() override;

        ~PlayerShipView() override = default;
    };
}


#endif //SPACE_INVADERS_PLAYERSHIPVIEW_H
