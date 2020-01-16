/** \file ShieldController.h
 * project: space_invaders
 * author: Mano Marichal
 * date: 27.12.19
 * copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#ifndef SPACE_INVADERS_SHIELDCONTROLLER_H
#define SPACE_INVADERS_SHIELDCONTROLLER_H

#include "../abstract_classes/Controller.h"

namespace objects::shield {
class ShieldController : public Controller
{
public:
        ShieldController(const std::shared_ptr<Entity>& entity, const std::shared_ptr<View>& view, World& world)
            : Controller(world, entity, view){};
        bool handleEvents(const std::vector<std::shared_ptr<Entity>>& objects) override;
        ~ShieldController() override = default;
};
} // namespace objects::shield

#endif // SPACE_INVADERS_SHIELDCONTROLLER_H
