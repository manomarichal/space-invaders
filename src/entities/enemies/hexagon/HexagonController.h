// =====================================================================
// @name: HexagonController.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 08.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_HEXAGONCONTROLLER_H
#define SPACE_INVADERS_HEXAGONCONTROLLER_H

#include "../../abstract_classes/Controller.h"
#include "../../projectiles/standard/StandardProjectile.h"
#include "../../../util/Collision.h"
#include "./HexagonView.h"

namespace entities::enemies
{
    class HexagonController: public Controller
    {
    private:
        std::shared_ptr<Hexagon> entity;
        std::shared_ptr<HexagonView> view;
    public:
        HexagonController(std::shared_ptr<Hexagon> entity, std::shared_ptr<HexagonView> view, Game* game):Controller(game), entity(std::move(entity)), view(std::move(view)) {};
        bool handleEvents(const std::vector<std::shared_ptr<Entity>> &entities) override ;
        ~HexagonController() override = default;
    };
}
#endif //SPACE_INVADERS_HEXAGONCONTROLLER_H
