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

#include "./PlayerHudView.h"

namespace entities::playership
{
    class PlayerShipView: public View
    {
    private:
        std::unique_ptr<PlayerHudView> hud;
    public:
        explicit PlayerShipView(std::shared_ptr<PlayerShip> ship);
        void notify() override;
        void draw(sf::RenderWindow &window) const override;
        ~PlayerShipView() override = default;
    };
}


#endif //SPACE_INVADERS_PLAYERSHIPVIEW_H
