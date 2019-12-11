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

namespace entities
{
    class PlayerShipView: public entities::View, public entities::Observer
    {
    private:
        std::shared_ptr<PlayerShip> entity;
        std::unique_ptr<sf::Sprite> sprite;
        std::unique_ptr<sf::Texture> texture;
    public:

        explicit PlayerShipView(std::shared_ptr<PlayerShip> ship);

        void draw(sf::RenderWindow &window) const override;
        void notify() override;

        ~PlayerShipView() override = default;
    };
}


#endif //SPACE_INVADERS_PLAYERSHIPVIEW_H
