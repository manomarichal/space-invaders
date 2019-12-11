// =====================================================================
// @name: PentagonController.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 11.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_PENTAGONCONTROLLER_H
#define SPACE_INVADERS_PENTAGONCONTROLLER_H

#include "./PentagonView.h"
#include "../../abstract_classes/Controller.h"
#include "../../projectiles/standard/StandardProjectile.h"
#include "../../../util/Collision.h"
#include "../../../settings/screensize.h"


namespace entities::enemies::pentagon
{
    class PentagonController: public Controller
    {
    private:
        std::shared_ptr<Pentagon> entity;
        std::shared_ptr<PentagonView> view;
    public:
        PentagonController(std::shared_ptr<Pentagon> entity, std::shared_ptr<PentagonView> view, Game* game):Controller(game), entity(std::move(entity)), view(std::move(view)) {};
        bool handleEvents(const std::vector<std::shared_ptr<Entity>> &entities) override ;
        ~PentagonController() override = default;
    };
}


#endif //SPACE_INVADERS_PENTAGONCONTROLLER_H
