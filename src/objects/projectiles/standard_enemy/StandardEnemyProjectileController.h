/** \file StandardEnemyProjectileController.h
 * project: space_invaders
 * author: Mano Marichal
 * date: 11.12.19
 * copyright: BA2 Informatica - Mano Marichal - University of Antwerp */

#ifndef SPACE_INVADERS_STANDARDENEMYPROJECTILECONTROLLER_H
#define SPACE_INVADERS_STANDARDENEMYPROJECTILECONTROLLER_H

#include "../../abstract_classes/Controller.h"
#include "./StandardEnemyProjectileView.h"

namespace objects::projectiles::standard_enemy {
class StandardEnemyProjectileController : public Controller
{
public:
        StandardEnemyProjectileController(const std::shared_ptr<Entity>& entity, const std::shared_ptr<View>& view,
                                          World& world)
            : Controller(world, entity, view){};
        bool handleEvents(const std::vector<std::shared_ptr<Entity>>& objects) override;
        ~StandardEnemyProjectileController() override = default;
};
} // namespace objects::projectiles::standard_enemy

#endif // SPACE_INVADERS_STANDARDENEMYPROJECTILECONTROLLER_H
