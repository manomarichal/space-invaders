/** \file PlayerShipView.h
 * project: space_invaders
 * author: Mano Marichal
 * date: 05.12.19
 * copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#ifndef SPACE_INVADERS_PLAYERSHIPVIEW_H
#define SPACE_INVADERS_PLAYERSHIPVIEW_H

#include "PlayerLivesView.h"

namespace objects::playership {
class PlayerShipView : public View
{
private:
        std::shared_ptr<PlayerLivesView> hud;

public:
        explicit PlayerShipView(std::shared_ptr<PlayerShip> ship);
        void onNotify() override;
        void draw(sf::RenderWindow& window) const override;
        ~PlayerShipView() override = default;
};
} // namespace objects::playership

#endif // SPACE_INVADERS_PLAYERSHIPVIEW_H
