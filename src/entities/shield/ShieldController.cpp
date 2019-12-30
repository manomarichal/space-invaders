
/** \file ShieldController.cpp
* project: space_invaders
* author: Mano Marichal
* date: 27.12.19
* copyright: BA2 Informatica - Mano Marichal - University of Antwerp */
/// description:


#include "ShieldController.h"
#include "../enemies/Enemy.h"

using namespace entities::shield;

bool ShieldController::handleEvents(const std::vector<std::shared_ptr<Entity>>  &entities)
{
    for (const auto& e:entities)
    {
        if (util::Collision::enemy(*entity, e)) return false;
    }
    return true;
}