// =====================================================================
// @name: HexagonView.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 08.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_HEXAGONVIEW_H
#define SPACE_INVADERS_HEXAGONVIEW_H

#include "../../abstract_classes/View.h"
#include "../../abstract_classes/Observer.h"
#include "./Hexagon.h"
namespace entities::enemies::hexagon
{
class HexagonView: public View, public Observer
    {
        float maxHP;
        std::shared_ptr<Hexagon> entity;
        std::unique_ptr<sf::Sprite> sprite;
        std::unique_ptr<sf::Texture> texture;
    public:
        explicit HexagonView(std::shared_ptr<Hexagon> hexagon);

        void notify() override ;
        void draw(sf::RenderWindow &window) const override;

        ~HexagonView() override = default;
    };
}

#endif //SPACE_INVADERS_HEXAGONVIEW_H
