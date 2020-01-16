/** \file ShieldView.h
 * project: space_invaders
 * author: Mano Marichal
 * date: 27.12.19
 * copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#ifndef SPACE_INVADERS_SHIELDVIEW_H
#define SPACE_INVADERS_SHIELDVIEW_H

#include "../abstract_classes/View.h"

namespace objects::shield {
class ShieldView : public View
{
public:
        explicit ShieldView(const std::shared_ptr<Entity>& entity);
        void onNotify() override;
        ~ShieldView() override = default;
};
} // namespace objects::shield

#endif // SPACE_INVADERS_SHIELDVIEW_H
