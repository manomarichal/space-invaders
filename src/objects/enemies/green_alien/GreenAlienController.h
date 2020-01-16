/** \file GreenAlienController.h
 * project: space_invaders
 * author: Mano Marichal
 * date: 11.12.19
 * copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#ifndef SPACE_INVADERS_GREENALIENCONTROLLER_H
#define SPACE_INVADERS_GREENALIENCONTROLLER_H

#include "../../../util/Stopwatch.h"
#include "../../abstract_classes/Controller.h"
#include "GreenAlienView.h"

namespace objects::enemies::green_alien {
class GreenAlienController : public Controller
{
private:
        std::unique_ptr<util::Stopwatch> stopwatch;

public:
        GreenAlienController(const std::shared_ptr<Entity>& entity, const std::shared_ptr<View>& view, World& world);
        bool handleEvents(const std::vector<std::shared_ptr<Entity>>& objects) override;
        ~GreenAlienController() override = default;
};
} // namespace objects::enemies::green_alien

#endif // SPACE_INVADERS_GREENALIENCONTROLLER_H
