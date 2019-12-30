/** \file StandardEnemyProjectileView.h
* project: space_invaders
* author: Mano Marichal
* date: 11.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#ifndef SPACE_INVADERS_STANDARDENEMYPROJECTILEVIEW_H
#define SPACE_INVADERS_STANDARDENEMYPROJECTILEVIEW_H


#include "../../abstract_classes/View.h"
#include "./StandardEnemyProjectile.h"

namespace objects::projectiles::standard_enemy
{
    class StandardEnemyProjectileView: public View
    {
    public:
        explicit StandardEnemyProjectileView(const std::shared_ptr<StandardEnemyProjectile>& projectile)
                : View("../resources/textures/whitesquare.png", projectile) {};
        void onNotify() override;
        ~StandardEnemyProjectileView() override = default;
    };
}


#endif //SPACE_INVADERS_STANDARDENEMYPROJECTILEVIEW_H
