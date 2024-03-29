/** \file PlayerLivesView.h
 * project: space_invaders
 * author: Mano Marichal
 * date: 15.12.19
 * copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#ifndef SPACE_INVADERS_PLAYERLIVESVIEW_H
#define SPACE_INVADERS_PLAYERLIVESVIEW_H

#include "../abstract_classes/View.h"
#include "PlayerShip.h"

namespace objects::playership {
class PlayerLivesView : public View
{
private:
        std::unique_ptr<sf::Text> string;
        std::unique_ptr<sf::Font> font;
        std::unique_ptr<sf::Texture> ship;
        std::vector<std::unique_ptr<sf::Sprite>> lives;

public:
        explicit PlayerLivesView(std::shared_ptr<PlayerShip> ship);
        void onNotify() override;
        void draw(sf::RenderWindow& window) const override;
        ~PlayerLivesView() override = default;
};
} // namespace objects::playership

#endif // SPACE_INVADERS_PLAYERLIVESVIEW_H
