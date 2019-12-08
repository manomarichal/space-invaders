// =====================================================================
// @name: StandardProjectileView.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 06.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_STANDARDPROJECTILEVIEW_H
#define SPACE_INVADERS_STANDARDPROJECTILEVIEW_H

#include "../../abstract_classes/View.h"
#include "./StandardProjectile.h"

namespace entities::projectiles
{
    class StandardProjectileView: public View
    {
    private:
        std::shared_ptr<StandardProjectile> entity;
        std::unique_ptr<sf::Sprite> sprite;
        std::unique_ptr<sf::Texture> texture;
    public:

        explicit StandardProjectileView(std::shared_ptr<StandardProjectile> projectile);

        void draw(sf::RenderWindow &window) const override;

        ~StandardProjectileView() override = default;
    };
}
#endif //SPACE_INVADERS_STANDARDPROJECTILEVIEW_H
