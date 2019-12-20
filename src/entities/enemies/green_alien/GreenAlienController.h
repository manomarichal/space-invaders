// =====================================================================
// @name: GreenAlienController.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 11.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_GREENALIENCONTROLLER_H
#define SPACE_INVADERS_GREENALIENCONTROLLER_H

#include "GreenAlienView.h"
#include "../../abstract_classes/Controller.h"
#include "../../projectiles/standard/StandardProjectile.h"
#include "../../projectiles/ProjectileFactory.h"
#include "../../../util/Stopwatch.h"


namespace entities::enemies::green_alien
{
    class GreenAlienController: public Controller
    {
    private:
        std::unique_ptr<Stopwatch> stopwatch;
    public:
        GreenAlienController(const std::shared_ptr<Entity> &entity, const std::shared_ptr<View> &view, World &world);
        bool handleEvents(const std::vector<std::shared_ptr<Entity>> &entities) override ;
        ~GreenAlienController() override = default;
    };
}


#endif //SPACE_INVADERS_GREENALIENCONTROLLER_H
