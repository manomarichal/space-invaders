// =====================================================================
// @name: PurpleAlienView.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 08.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_PURPLEALIENVIEW_H
#define SPACE_INVADERS_PURPLEALIENVIEW_H

#include "../../abstract_classes/View.h"
#include "../../abstract_classes/Observer.h"
#include "PurpleAlien.h"
namespace entities::enemies::purple_alien
{
class PurpleAlienView: public View
    {
        float maxHP;
    public:
        explicit PurpleAlienView(const std::shared_ptr<PurpleAlien> &alien);
        void notify() override ;
        ~PurpleAlienView() override = default;
    };
}

#endif //SPACE_INVADERS_PURPLEALIENVIEW_H
