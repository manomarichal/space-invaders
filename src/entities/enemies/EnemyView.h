// =====================================================================
// @name: EnemyView.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 11.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_ENEMYVIEW_H
#define SPACE_INVADERS_ENEMYVIEW_H

#include "../abstract_classes/View.h"
#include "../abstract_classes/Observer.h"

namespace entities::enemies
{
    class EnemyView: public View, public Observer
    {
    private:
    };
}
#endif //SPACE_INVADERS_ENEMYVIEW_H
