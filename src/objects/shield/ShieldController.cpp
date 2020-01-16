/** \file ShieldController.cpp
 * project: space_invaders
 * author: Mano Marichal
 * date: 27.12.19
 * copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#include "ShieldController.h"

using namespace objects::shield;

bool ShieldController::handleEvents(const std::vector<std::shared_ptr<Entity>>& objects)
{
        for (const auto& e : objects) {
                if (util::Collision::enemy(*entity, e))
                        return false;
        }
        return true;
}