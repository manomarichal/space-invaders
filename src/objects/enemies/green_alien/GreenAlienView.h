/** \file GreenAlienView.h
* project: space_invaders
* author: Mano Marichal
* date: 11.12.19
*/

#ifndef SPACE_INVADERS_GREENALIENVIEW_H
#define SPACE_INVADERS_GREENALIENVIEW_H

#include "../../abstract_classes/View.h"
#include "../../abstract_classes/Observer.h"
#include "GreenAlien.h"

namespace objects::enemies::green_alien
{
    class GreenAlienView: public View
    {
        float maxHP{};
    public:
        explicit GreenAlienView(const std::shared_ptr<GreenAlien> &alien);
        void onNotify() override ;
        ~GreenAlienView() override = default;
    };
}


#endif //SPACE_INVADERS_GREENALIENVIEW_H
