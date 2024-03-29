/** \file GreenAlienView.h
 * project: space_invaders
 * author: Mano Marichal
 * date: 11.12.19
 */

#ifndef SPACE_INVADERS_GREENALIENVIEW_H
#define SPACE_INVADERS_GREENALIENVIEW_H

#include "../../abstract_classes/View.h"
#include "GreenAlien.h"

namespace objects::enemies::green_alien {
class GreenAlienView : public View
{
public:
        explicit GreenAlienView(const std::shared_ptr<GreenAlien>& alien);
        void onNotify() override;
        ~GreenAlienView() override = default;
};
} // namespace objects::enemies::green_alien

#endif // SPACE_INVADERS_GREENALIENVIEW_H
