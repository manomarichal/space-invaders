/** \file RedAlienView.h
 * project: space_invaders
 * author: Mano Marichal
 * date: 12.12.19
 * copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#ifndef SPACE_INVADERS_REDALIENVIEW_H
#define SPACE_INVADERS_REDALIENVIEW_H

#include "../../abstract_classes/View.h"
#include "RedAlien.h"

namespace objects::enemies::red_alien {
class RedAlienView : public View
{
public:
        explicit RedAlienView(const std::shared_ptr<RedAlien>& enemy);
        void onNotify() override;
        ~RedAlienView() override = default;
};
} // namespace objects::enemies::red_alien

#endif // SPACE_INVADERS_REDALIENVIEW_H
