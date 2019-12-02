// =====================================================================
// @name: StandardProjectileView.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 02.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_STANDARDPROJECTILEVIEW_H
#define SPACE_INVADERS_STANDARDPROJECTILEVIEW_H

#include "../../View.h"
#include "./StandardProjectile.h"
#include "../Projectile.h"

namespace projectiles
{
    class StandardProjectileView: public View
    {
    private:
        Projectile * object;
    public:
        void draw(sf::RenderWindow &window) override;

        ~StandardProjectileView() override;
    };
}


#endif //SPACE_INVADERS_STANDARDPROJECTILEVIEW_H
