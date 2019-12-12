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
#include "../../abstract_classes/Observer.h"
#include "./StandardProjectile.h"

namespace entities::projectiles::standard
{
    class StandardProjectileView: public View, public Observer
    {
    public:
        explicit StandardProjectileView(std::shared_ptr<StandardProjectile> projectile);
        void notify() override;
        ~StandardProjectileView() override = default;
    };
}
#endif //SPACE_INVADERS_STANDARDPROJECTILEVIEW_H
