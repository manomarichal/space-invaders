// =====================================================================
// @name: PentagonView.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 11.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_PENTAGONVIEW_H
#define SPACE_INVADERS_PENTAGONVIEW_H

#include "../../abstract_classes/View.h"
#include "../../abstract_classes/Observer.h"
#include "./Pentagon.h"

namespace entities::enemies::pentagon
{
    class PentagonView: public View, public Observer
    {
        float maxHP;
        std::shared_ptr<Pentagon> entity;
        std::unique_ptr<sf::Sprite> sprite;
        std::unique_ptr<sf::Texture> texture;
    public:
        explicit PentagonView(std::shared_ptr<Pentagon> pentagon);

        void notify() override ;
        void draw(sf::RenderWindow &window) const override;

        ~PentagonView() override = default;
    };
}


#endif //SPACE_INVADERS_PENTAGONVIEW_H
