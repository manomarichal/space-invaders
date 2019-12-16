// =====================================================================
// @name: PlayerLivesView.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 15.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_PLAYERLIVESVIEW_H
#define SPACE_INVADERS_PLAYERLIVESVIEW_H

#include "../abstract_classes/View.h"
#include "PlayerShip.h"

namespace entities::playership
{
    class PlayerLivesView: public View
    {
    private:
        std::unique_ptr<sf::Text> string;
        std::unique_ptr<sf::Font> font;
        std::unique_ptr<sf::Texture> ship;
        std::vector<std::unique_ptr<sf::Sprite>> lives;
    public:
        explicit PlayerLivesView(std::shared_ptr<PlayerShip> ship);
        void notify() override;
        void draw(sf::RenderWindow &window) const override;
        ~PlayerLivesView() override = default;
    };
}

#endif //SPACE_INVADERS_PLAYERLIVESVIEW_H
