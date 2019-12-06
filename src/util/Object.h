// =====================================================================
// @name: Object.h
// @project: space_invaders
// @author: Mano Marichal
// @date: 06.12.19
// @copyright: BA2 Informatica - Mano Marichal - University of Antwerp
// @description: 
// =====================================================================

#ifndef SPACE_INVADERS_OBJECT_H
#define SPACE_INVADERS_OBJECT_H

#include "../entities/Entity.h"
#include "../entities/View.h"
#include "../entities/Controller.h"

using Object = std::tuple<
        std::shared_ptr<entities::Entity>,
        std::shared_ptr<entities::View>,
        std::shared_ptr<entities::Controller>>;

#endif //SPACE_INVADERS_OBJECT_H
