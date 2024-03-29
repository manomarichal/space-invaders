/** \file StandardProjectileView.h
 * project: space_invaders
 * author: Mano Marichal
 * date: 06.12.19
 * copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#ifndef SPACE_INVADERS_STANDARDPROJECTILEVIEW_H
#define SPACE_INVADERS_STANDARDPROJECTILEVIEW_H

#include "../../abstract_classes/View.h"
#include "./StandardProjectile.h"

namespace objects::projectiles::standard {
class StandardProjectileView : public View
{
public:
        explicit StandardProjectileView(const std::shared_ptr<StandardProjectile>& projectile)
            : View("./resources/textures/whitesquare.png", projectile){};

        void onNotify() override;
        ~StandardProjectileView() override = default;
};
} // namespace objects::projectiles::standard
#endif // SPACE_INVADERS_STANDARDPROJECTILEVIEW_H
