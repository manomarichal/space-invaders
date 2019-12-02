// =====================================================================
// @name: PlayerShipView.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 01.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_PLAYERSHIPVIEW_H
#define SPACE_INVADERS_PLAYERSHIPVIEW_H

#include "../View.h"
#include "./PlayerShip.h"

class PlayerShipView: public View
{
private:
    sf::Sprite* sprite;
    sf::Texture* texture;
public:
    PlayerShipView();

    PlayerShip* object;

    void draw(sf::RenderWindow &window) override;

    ~PlayerShipView() override;
};

#endif //SPACE_INVADERS_PLAYERSHIPVIEW_H
