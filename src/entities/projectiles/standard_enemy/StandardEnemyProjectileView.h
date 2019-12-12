// =====================================================================
// @name: StandardEnemyProjectileView.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 11.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_STANDARDENEMYPROJECTILEVIEW_H
#define SPACE_INVADERS_STANDARDENEMYPROJECTILEVIEW_H


#include "../../abstract_classes/View.h"
#include "../../abstract_classes/Observer.h"
#include "./StandardEnemyProjectile.h"

namespace entities::projectiles::standard_enemy
{
    class StandardEnemyProjectileView: public View, public Observer
    {
    public:
        explicit StandardEnemyProjectileView(std::shared_ptr<StandardEnemyProjectile> projectile);
        void notify() override;
        ~StandardEnemyProjectileView() override = default;
    };
}


#endif //SPACE_INVADERS_STANDARDENEMYPROJECTILEVIEW_H
